/*
 * genproc is a tool for website generation. A content management system, specialized to process descriptions.
 * Copyright (C) 2005-2016 Thomas Spitzer
 *
 * genproc is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * genproc  is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St., Fifth Floor, Boston, MA 02110-1301, USA
*/

#include <stdio.h>
#include <argp.h>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/spirit/include/qi_action.hpp>

#include "I_element.h"
#include "root_element.h"
#include "home_element.h"
#include "page_element.h"
#include "text_owner.h"
#include "subpage_owner.h"
#include "label_owner.h"
#include "process_element.h"
#include "role_element.h"
#include "artefact_element.h"
#include "repository_element.h"
#include "transition.h"
#include "artefact_transition.h"
#include "tool_element.h"
#include "parameters.h"
#include "source_element.h"

namespace classic = boost::spirit::classic;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

const char* outpath = "./html";

/* This structure is used by main to communicate with parse_opt. */
struct Arguments
{
    Arguments(): verbose(false) {}
    bool verbose;
    std::vector<std::string> file_names;
};

Arguments arguments;

void check_duplicate(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    pass = !ast::I_element::identifier_exists(name);
    ast::label_owner* e = dynamic_cast<ast::label_owner*>(&ast::I_element::get_last());
    if (e)
        e->set_identifier(name);
}

void set_label(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::label_owner* e = dynamic_cast<ast::label_owner*>(&ast::I_element::get_last());
    if (e)
        e->set_label(name);
}

void add_label(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::label_owner* e = dynamic_cast<ast::label_owner*>(&ast::I_element::get_last());
    if (e)
        e->add_label(name);
}

void set_role(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::role_owner* e = dynamic_cast<ast::role_owner*>(&ast::I_element::get_last());
    if (e)
        e->set_role(name);
}

void set_tool(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::role_owner* e = dynamic_cast<ast::role_owner*>(&ast::I_element::get_last());
    if (e)
        e->set_tool(name);
}

void set_brief(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::label_owner* e = dynamic_cast<ast::label_owner*>(&ast::I_element::get_last());
    if (e)
        e->set_brief(name);
}

void add_subpage(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::subpage_owner* e = dynamic_cast<ast::subpage_owner*>(&ast::I_element::get_last());
    if (e)
        e->add_subpage_ID(name);
}

void add_relation(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::artefact_base* e = dynamic_cast<ast::artefact_base*>(&ast::I_element::get_last());
    if (e)
        e->add_relation_ID(name);
}

void add_text(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::text_owner* e = dynamic_cast<ast::text_owner*>(&ast::I_element::get_last());
    if (e)
        e->add_text_file_name(name);
}

void add_repository(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::process_element* e = dynamic_cast<ast::process_element*>(&ast::I_element::get_last());
    if (e)
        e->add_repository_ID(name);
}

void add_create(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::transformer* e = dynamic_cast<ast::transformer*>(&ast::I_element::get_last());
    if (e)
        e->add_create_ID(name);
}

void add_specialize(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::activity_element* e = dynamic_cast<ast::activity_element*>(&ast::I_element::get_last());
    if (e)
        e->add_specialize_ID(name);
}

void add_transform(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::transformer* e = dynamic_cast<ast::transformer*>(&ast::I_element::get_last());
    if (e)
        e->add_transform_ID(name);
}

void add_source(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::transition::setSource(name);
}

void add_destination(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::transition::setDestination(name);
}

void add_guard(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::transition::setGuard(name);
}

void addNamespace(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::I_element::addNamespace(name);
}

void removeNamespace(const boost::spirit::unused_type& name, const boost::spirit::unused_type& it, bool& pass)
{
    pass = ast::I_element::removeNamespace();
}

std::string loadFileName;
void addFile(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    loadFileName = name;
}

void handleLoad(const boost::spirit::unused_type& name, const boost::spirit::unused_type& it, bool& pass);

void add_parameter(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::parameters::addParameter(name);
}

void add_transition(const ast::transition& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::transformer::add_transition(name);
}

template<typename T>
void check_existing(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    T* a = dynamic_cast<T*>(ast::I_element::static_find_element(name));
    if (a == 0)
    {
        pass = false;
        return;
    }
    ast::I_element::set_last(a);
}

template <typename Iterator>
struct process_description
  : qi::grammar<Iterator, std::list<ast::root_element>()>
{
    process_description()
      : process_description::base_type(rootElements)
    {
        rootElements    = *(rootElement > space);
        rootElement     = (qi::lit("@home") > space > homeElement) |
                          (qi::lit("page") >  space > pageElement) |
                          (qi::lit("activity") >  space > activityElement) |
                          (qi::lit("extend") >> space >> qi::lit("activity") > space > activityExtend) |
                          (qi::lit("extend") >> space >> qi::lit("artefact") > space > artefactExtend) |
                          (qi::lit("extend") >> space >> qi::lit("folder") > space > folderExtend) |
                          (qi::lit("extend") >> space >> qi::lit("repository") > space > repositoryExtend) |
                          (qi::lit("role") >  space > roleElement) |
                          (qi::lit("tool") >  space > toolElement) |
                          (qi::lit("artefact") >  space > artefactElement) |
                          (qi::lit("folder") >  space > folderElement) |
                          (qi::lit("repository") >  space > repositoryElement) |
                          name_space_begin |
                          name_space_end | 
                          do_include |
                          comment |
                          (qi::lit("process") >  space > processElement);
        
        homeElement     = OB
                        > space
                        > subpagelist
                        > space
                        > textfilelist
                        > space
                        > CB;
        
        pageElement     = name_identifier[check_duplicate]
                        > space
                        > OB
                        > space
                        > -label
                        > space
                        > -subpagelist
                        > space
                        > -textfilelist
                        > space
                        > CB;
        
        activityElement = name_identifier[check_duplicate]
                        > activityContent;

        activityExtend  = ref_identifier[check_existing<ast::activity_element>]
                        > activityContent;

        activityContent = space
                        > OB
                        > space
                        > -label
                        > space
                        > -brief[set_brief]
                        > space
                        > -responsibleRole[set_role]
                        > space
                        > -usedTool[set_tool]
                        > space
                        > -transformlist
                        > space
                        > -createlist
                        > space
                        > -specializelist
                        > space
                        > *(transition[add_transition] > space)
                        > -subActivities
                        > space
                        > -textfilelist
                        > space
                        > CB;

        artefactElement = name_identifier[check_duplicate]
                        > artefactContent;

        artefactExtend  = ref_identifier[check_existing<ast::artefact_element>]
                        > artefactContent;
        
        artefactContent = space
                        > OB
                        > space
                        > -label
                        > space
                        > -brief[set_brief]
                        > space
                        > -subArtifacts
                        > space
                        > -relations
                        > space
                        > -textfilelist
                        > space
                        > CB;
                
          folderElement = name_identifier[check_duplicate]
                        > folderContent;

          folderExtend  = ref_identifier[check_existing<ast::folder_element>]
                        > folderContent;

          folderContent = space
                        > OB
                        > space
                        > -label
                        > space
                        > -brief[set_brief]
                        > space
                        > -subArtifacts
                        > space
                        > -textfilelist
                        > space
                        > CB;

      repositoryElement = name_identifier[check_duplicate]
                        > repositoryContent;

       repositoryExtend = ref_identifier[check_existing<ast::repository_element>]
                        > folderContent;

      repositoryContent = space
                        > OB
                        > space
                        > -label
                        > space
                        > -brief[set_brief]
                        > space
                        > -subArtifacts
                        > space
                        > -textfilelist
                        > space
                        > CB;

            roleElement = name_identifier[check_duplicate]
                        > space
                        > OB
                        > space
                        > -label
                        > space
                        > -brief[set_brief]
                        > space
                        > -textfilelist
                        > space
                        > CB;

            toolElement = name_identifier[check_duplicate]
                        > space
                        > OB
                        > space
                        > -label
                        > space
                        > -brief[set_brief]
                        > space
                        > -textfilelist
                        > space
                        > CB;

        processElement  = name_identifier[check_duplicate]
                        > space
                        > OB
                        > space
                        > -label
                        > space
                        > responsibleRole[set_role]
                        > space
                        > -transformlist
                        > space
                        > -createlist
                        > space
                        > -repositories
                        > space
                        > subActivities
                        > space
                        > textfilelist
                        > space
                        > CB;

        subpagelist     = qi::lit("subpages")
                        > space
                        > ref_identifier[add_subpage]
                        > space
                        > *(qi::lit(',') > space > ref_identifier)[add_subpage]
                        > qi::lit(';');
                        
        repositories    = qi::lit("repository")
                        > space
                        > ref_identifier[add_repository]
                        > space
                        > *(qi::lit(',') > space > ref_identifier)[add_repository]
                        > qi::lit(';');
                        
        subActivities   = qi::lit("subactivities")
                        > space
                        > ref_identifier[add_subpage]
                        > space
                        > *(qi::lit(',') > space > ref_identifier)[add_subpage]
                        > qi::lit(';');
                        
        subArtifacts    = qi::lit("contains")
                        > space
                        > ref_identifier[add_subpage]
                        > space
                        > *(qi::lit(',') > space > ref_identifier)[add_subpage]
                        > qi::lit(';');
                        
        relations       = qi::lit("relations")
                        > space
                        > ref_identifier[add_relation]
                        > space
                        > *(qi::lit(',') > space > ref_identifier)[add_relation]
                        > qi::lit(';');
                        
        textfilelist    = qi::lit("text")
                        > space
                        > filename[add_text]
                        > space
                        > *(qi::lit(',') > space > filename)[add_text]
                        > space
                        > SC;
                        
        createlist      = qi::lit("create")
                        > space
                        > ref_identifier[add_create]
                        > space
                        > *(qi::lit(',') > space > ref_identifier)[add_create]
                        > space
                        > SC;
                        
        specializelist  = qi::lit("specialize")
                        > space
                        > ref_identifier[add_specialize]
                        > space
                        > *(qi::lit(',') > space > ref_identifier)[add_specialize]
                        > space
                        > SC;
                        
        transformlist   = qi::lit("transform")
                        > space
                        > ref_identifier[add_transform]
                        > space
                        > *(qi::lit(',') > space > ref_identifier)[add_transform]
                        > space
                        > qi::lit(';');
                        
        name_identifier = qi::char_("a-zA-Z") > *qi::char_("a-zA-Z0-9");
        ref_identifier  = parameterUse
                        | (qi::char_("a-zA-Z_") > *qi::char_("a-zA-Z_0-9"));
        
       name_space_begin = qi::lit("namespace")
                        > space
                        > name_identifier[addNamespace]
                        > space
                        > OB;
        
        name_space_end  = CB[removeNamespace];
        
        do_include      = qi::lit("include")
                        > space
                        > filename[addFile]
                        > space
                        > -(parameterlist)
                        > space
                        > SC[handleLoad];

        parameterlist   = Ob
                        > space
                        > (ref_identifier | text)[add_parameter]
                        > space
                        > *(qi::lit(',') > space > (ref_identifier | text))[add_parameter]
                        > space
                        > Cb;

        parameterUse    = qi::lit('$') > qi::uint_;

        text            = parameterUse 
                        | 
                        (qi::lit('"')
                            > *(qi::alnum | qi::char_("äöüßÄÖÜ ,.;:_<>|~!§$%&/()=?{[]}'-"))
                            >  qi::lit('"')
                        );

        label           = qi::lit("label") 
                        > space
                        > text[set_label]
                        > space
                        > *(qi::lit('+') > space > text[add_label] > space)
                        > SC;
                        
        responsibleRole = qi::lit("responsible") 
                        > space
                        > ref_identifier
                        > space
                        > SC;
                        
        usedTool        = qi::lit("tool") 
                        > space
                        > ref_identifier
                        > space
                        > SC;
                        
        brief           = qi::lit("brief") 
                        > space
                        > text
                        > space
                        > SC;
                        
        statePair       = Ob
                        > space
                        > ref_identifier[add_source]
                        > C
                        > space
                        > ref_identifier[add_destination]
                        > space
                        > Cb;
                        
        transitionGuardString
                        = (qi::lit('[')
                        > *(qi::alnum | qi::char_(" ,.;:_<>|~!§$%&/()=?{}'"))
                        > qi::lit(']'));
                        
        transitionGuard = transitionGuardString[add_guard];
                        
        transition      = qi::lit("set")
                        > space
                        > ref_identifier
                        > space
                        > statePair
                        > space
                        > -transitionGuard
                        > space
                        > SC;
        
        comment         = qi::lit("//") 
                        > *(qi::alnum | qi::char_("\" ,.;:_<>|~!§$%&/()*=?{[]}'-")) 
                        > qi::lit('\n');

        filename        = +qi::char_("a-zA-Z_/.0-9");
        space           = *(qi::lit(' ') | qi::lit('\n') | qi::lit('\t') | comment);

        artefactExtend.name("the requested artefact is not found.");
        activityExtend.name("the requested activity is not found.");
        name_identifier.name("Expected a valid identifier name.");
        ref_identifier.name("Expected a valid identifier reference.");
        filename.name("Expected a valid filename.");
        textfilelist.name("\"text\" expected.");
        pageElement.name("Duplicate identifier.");
        subpagelist.name("\"subpages\" expected.");
        SC.name("';' expected.");
        C.name("',' expected.");
        Ob.name("'(' expected.");
        Cb.name("')' expected.");
        OB.name("'{' expected.");
        CB.name("'}' expected.");
        subActivities.name("\"subactivities\" expected.");
        responsibleRole.name("\"responsible\" expected.");
        statePair.name("\"state pair\" expected.");
        
        OB              = qi::lit("{");
        CB              = qi::lit("}");
        Ob              = qi::lit("(");
        Cb              = qi::lit(")");
        SC              = qi::lit(";");
        CN              = qi::lit(":");
        C               = qi::lit(",");
        ARROW           = qi::lit("->");
    }

    qi::rule<Iterator, ast::transition()> transition;
    qi::rule<Iterator, ast::parameters()> parameterUse;
    qi::rule<Iterator> name_space_begin;
    qi::rule<Iterator> comment;
    qi::rule<Iterator> parameterlist;
    qi::rule<Iterator> name_space_end;
    qi::rule<Iterator> do_include;
    qi::rule<Iterator> statePair;
    qi::rule<Iterator> subpagelist;
    qi::rule<Iterator> subActivities;
    qi::rule<Iterator> subArtifacts;
    qi::rule<Iterator> relations;
    qi::rule<Iterator> repositories;
    qi::rule<Iterator> textfilelist;
    qi::rule<Iterator> createlist;
    qi::rule<Iterator> specializelist;
    qi::rule<Iterator> transformlist;
    qi::rule<Iterator> activityExtend;
    qi::rule<Iterator> activityContent;
    qi::rule<Iterator> artefactExtend;
    qi::rule<Iterator> artefactContent;
    qi::rule<Iterator> folderExtend;
    qi::rule<Iterator> folderContent;
    qi::rule<Iterator> repositoryExtend;
    qi::rule<Iterator> repositoryContent;
    qi::rule<Iterator,ast::root_element()> rootElement;
    qi::rule<Iterator,ast::folder_element()> folderElement;
    qi::rule<Iterator,ast::home_element()> homeElement;
    qi::rule<Iterator,std::list<ast::root_element>()> rootElements;
    qi::rule<Iterator,ast::page_element()> pageElement;
    qi::rule<Iterator,ast::activity_element()> activityElement;
    qi::rule<Iterator,ast::artefact_element()> artefactElement;
    qi::rule<Iterator,ast::repository_element()> repositoryElement;
    qi::rule<Iterator,ast::role_element()> roleElement;
    qi::rule<Iterator,ast::tool_element()> toolElement;
    qi::rule<Iterator,ast::process_element()> processElement;
    qi::rule<Iterator, std::string()> ref_identifier;
    qi::rule<Iterator, std::string()> name_identifier;
    qi::rule<Iterator, std::string()> filename;
    qi::rule<Iterator> label;
    qi::rule<Iterator, std::string()> responsibleRole;
    qi::rule<Iterator, std::string()> usedTool;
    qi::rule<Iterator, std::string()> brief;
    qi::rule<Iterator, std::string()> text;
    qi::rule<Iterator> transitionGuard;
    qi::rule<Iterator, std::string()> transitionGuardString;
    qi::rule<Iterator> space;

    qi::rule<Iterator> OB;
    qi::rule<Iterator> CB;
    qi::rule<Iterator> Ob;
    qi::rule<Iterator> Cb;
    qi::rule<Iterator> SC;
    qi::rule<Iterator> CN;
    qi::rule<Iterator> C;
    qi::rule<Iterator> ARROW;

};

std::vector<ast::root_element> ast_data;
// wrap forward iterator with position iterator, to record the position
typedef classic::position_iterator2<boost::spirit::istream_iterator> pos_iterator_type;

bool load(const std::string& filename)
{
    try
    {
        // open file, disable skipping of whitespace
        std::ifstream in(filename.c_str());
        in.unsetf(std::ios::skipws);

        // wrap istream into iterator
        boost::spirit::istream_iterator begin(in);
        boost::spirit::istream_iterator end;

        pos_iterator_type position_begin(begin, end, filename.c_str());
        pos_iterator_type position_end;

        process_description<pos_iterator_type> p;       // create instance of parser

        qi::phrase_parse(position_begin, position_end, p, qi::space, ast_data);

        if (position_begin != position_end)
            throw qi::expectation_failure<pos_iterator_type>(position_begin, position_end,boost::spirit::info("general error"));
    }
    catch(const qi::expectation_failure<pos_iterator_type> e)
    {
        const classic::file_position_base<std::string>& pos = e.first.get_position();
        std::cerr   << pos.file << ':'
                    << pos.line << ": error: "
                    << e.what_  << std::endl;
        return false;    
    }
    return true;
}

void handleLoad(const boost::spirit::unused_type& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::parameters::activateParameters(arguments.verbose);
    ast::source_element::Load_begin(loadFileName,outpath);
    pass = load(loadFileName);
    ast::source_element::Load_end();
    ast::parameters::deactivateParameters(arguments.verbose);
}

const char *argp_program_version =
"genproc 0.1";

const char *argp_program_bug_address =
"<thomas@automotive-scrum.org>";

static struct argp_option options[] =
{
  {"verbose", 'v', 0,            0, "verbose info aboout parsing."},
  {"input"   ,'i', "file",       0, "the input file (May be set multiple times)."},
  {"output"  ,'o', "folder",     0, "the output folder (default: ./html)."},
  {0}
};

static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    Arguments* arguments = (Arguments*) state->input;

    switch (key)
    {
    case 'v':
        arguments->verbose = true;
        break;
    case 'i':
        arguments->file_names.push_back(arg);
        break;
    case 'o':
        outpath = arg;
        break;

    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static char doc[] =
"genproc -- A program to generate process descriptions.";

static struct argp argp = {options, parse_opt, 0, doc};

int main (int argc, char **argv)
{
    /* Where the magic happens */
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    if (arguments.file_names.empty())
    {
        printf("you must specify a process file\n");
        exit(1);
    }
    else for (std::vector<std::string>::iterator it = arguments.file_names.begin(); it != arguments.file_names.end(); it++)
    {
        try
        {
            ast::source_element::Load_begin((*it),outpath);
            if (!load(*it))
                return -1;
            ast::source_element::Load_end();
        }
        catch(const qi::expectation_failure<pos_iterator_type> e)
        {
            const classic::file_position_base<std::string>& pos = e.first.get_position();
            std::cerr   << pos.file << ':'
                        << pos.line << ": error: "
                        << e.what_  << std::endl;
            return -1;    
        }
        catch(std::string e)
        {
            std::cerr   << "logical error: "
                        << e
                        << std::endl;
            return -1;
        }
    }

    try {
        ast::I_element::init_link_all();
        ast::I_element::generate_all(outpath);
    }
    catch(std::string e)
    {
        std::cerr   << "logical error: "
                    << e
                    << std::endl;
        return -1;
    }

    return 0;
}

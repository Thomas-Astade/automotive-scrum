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

namespace classic = boost::spirit::classic;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

/* This structure is used by main to communicate with parse_opt. */
struct Arguments
{
    Arguments(): verbose(false), beautify(false) {}
    bool verbose;
    bool beautify;
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

void add_subpage(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::subpage_owner* e = dynamic_cast<ast::subpage_owner*>(&ast::I_element::get_last());
    if (e)
        e->add_subpage_ID(name);
}

void add_text(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    ast::text_owner* e = dynamic_cast<ast::text_owner*>(&ast::I_element::get_last());
    if (e)
        e->add_text_file_name(name);
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
                          (qi::lit("process") >  space > processElement);
        
        homeElement     = OB
                        > space
                        > subpagelist
                        > space
                        > textfilelist
                        > space
                        > CB;
        
        pageElement     = identifier[check_duplicate]
                        > space
                        > OB
                        > space
                        > -label[set_label]
                        > space
                        > -subpagelist
                        > space
                        > textfilelist
                        > space
                        > CB;
        
        processElement  = identifier[check_duplicate]
                        > space
                        > OB
                        > space
                        > -label[set_label]
                        > space
                        > textfilelist
                        > space
                        > CB;

        subpagelist     = qi::lit("subpages")
                        > space
                        > identifier[add_subpage]
                        > space
                        > *(qi::lit(',') > space > identifier)[add_subpage]
                        > qi::lit(';');
                        
        textfilelist    = qi::lit("text")
                        > space
                        > filename[add_text]
                        > space
                        > *(qi::lit(',') > space > filename)[add_text]
                        > space
                        > qi::lit(';');
                        
        identifier      = qi::char_("a-zA-Z_") > *qi::char_("a-zA-Z_0-9");
        
        label           = qi::lit("label") > space > qi::lit('"')
                        > *(qi::alnum | qi::char_(" ,.;:_<>|~!§$%&/()=?{[]}"))
                        >  qi::lit('"')
                        > space
                        > SC;
                        
        filename        = +qi::char_("a-zA-Z_/.0-9");
        space           = *(qi::lit(' ') | qi::lit('\n') | qi::lit('\t'));

        identifier.name("Expected a valid identifier.");
        filename.name("Expected a valid filename.");
        textfilelist.name("\"text\" expected.");
        pageElement.name("Duplicate identifier");
        subpagelist.name("\"subpages\" expected");
        SC.name("';' expected");
        
        OB              = qi::lit("{");
        CB              = qi::lit("}");
        Ob              = qi::lit("(");
        Cb              = qi::lit(")");
        SC              = qi::lit(";");
        CN              = qi::lit(":");
        ARROW           = qi::lit("->");
    }

    qi::rule<Iterator> subpagelist;
    qi::rule<Iterator> textfilelist;
    qi::rule<Iterator,ast::root_element()> rootElement;
    qi::rule<Iterator,ast::home_element()> homeElement;
    qi::rule<Iterator,std::list<ast::root_element>()> rootElements;
    qi::rule<Iterator,ast::page_element()> pageElement;
    qi::rule<Iterator,ast::process_element()> processElement;
    qi::rule<Iterator, std::string()> identifier;
    qi::rule<Iterator, std::string()> filename;
    qi::rule<Iterator, std::string()> label;
    qi::rule<Iterator> space;

    qi::rule<Iterator> OB;
    qi::rule<Iterator> CB;
    qi::rule<Iterator> Ob;
    qi::rule<Iterator> Cb;
    qi::rule<Iterator> SC;
    qi::rule<Iterator> CN;
    qi::rule<Iterator> ARROW;

};

const char *argp_program_version =
"genproc 0.1";

const char *argp_program_bug_address =
"<thomas@automotive-scrum.org>";

static struct argp_option options[] =
{
  {"verbose", 'v', 0,            0, "verbose info aboout parsing."},
  {"beautify",'b', 0,            0, "output the parsed text in a beautified form."},
  {"input"   ,'i', "file",       0, "the input file (May be set multiple times)."},
  {0}
};

static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    Arguments* arguments = (Arguments*) state->input;

    switch (key)
    {
    case 'b':
        arguments->beautify = true;
        break;
    case 'v':
        arguments->verbose = true;
        break;
    case 'i':
        arguments->file_names.push_back(arg);
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
    std::vector<ast::root_element> ast;

    // wrap forward iterator with position iterator, to record the position
    typedef classic::position_iterator2<boost::spirit::istream_iterator>
        pos_iterator_type;
       
    if (arguments.file_names.empty())
    {
        printf("you must specify a process file\n");
        exit(1);
    }
    else for (std::vector<std::string>::iterator it = arguments.file_names.begin(); it != arguments.file_names.end(); it++)
    {
        try
        {
            // open file, disable skipping of whitespace
            std::ifstream in((*it).c_str());
            in.unsetf(std::ios::skipws);

            // wrap istream into iterator
            boost::spirit::istream_iterator begin(in);
            boost::spirit::istream_iterator end;

            pos_iterator_type position_begin(begin, end, (*it).c_str());
            pos_iterator_type position_end;

            process_description<pos_iterator_type> p;       // create instance of parser

            qi::phrase_parse(position_begin, position_end, p, qi::space, ast);

            if (position_begin != position_end)
                throw qi::expectation_failure<pos_iterator_type>(position_begin, position_end,boost::spirit::info("general error"));
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

    if (arguments.beautify)
    {
        for (std::vector<ast::root_element>::iterator it = ast.begin(); it != ast.end(); it++)
        {
            (*it).dump();
        }
    }
    else
    {
        try {
            ast::I_element::init_link_all();
            ast::I_element::generate_all("/srv/automotive-scrum");
        }
        catch(std::string e)
        {
            std::cerr   << "logical error: "
                        << e
                        << std::endl;
            return -1;
        }
    }

    return 0;
}

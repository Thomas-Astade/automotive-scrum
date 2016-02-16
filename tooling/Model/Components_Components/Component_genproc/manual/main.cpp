#include <stdio.h>
#include <argp.h>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/spirit/include/qi_action.hpp>

#include "root_element.h"
#include "home_element.h"
#include "page_element.h"

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

template <typename Iterator>
struct process_description
  : qi::grammar<Iterator, std::list<ast::root_element>()>
{
    process_description()
      : process_description::base_type(rootElements)
    {
        rootElements    = *(rootElement > space);
        rootElement     = (qi::lit("@home") > space > homeElement) |
                          (qi::lit("page") >  space > pageElement);
        
        homeElement     = qi::lit('{')
                        > space
                        > qi::lit('}');
        
        pageElement     = identifier
                        > space
                        > qi::lit('{')
                        > space
                        > qi::lit('}');
        
        identifier      =  qi::char_("a-zA-Z_") > *qi::char_("a-zA-Z_0-9");
        space           = *(qi::lit(' ') | qi::lit('\n') | qi::lit('\t'));

        identifier.name("Expected a valid identifier.");
    }

    qi::rule<Iterator,ast::root_element()> rootElement;
    qi::rule<Iterator,ast::home_element()> homeElement;
    qi::rule<Iterator,std::list<ast::root_element>()> rootElements;
    qi::rule<Iterator,ast::page_element()> pageElement;
    qi::rule<Iterator, std::string()> identifier;
    qi::rule<Iterator> space;
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

            pos_iterator_type position_begin(begin, end, *it);
            pos_iterator_type position_end;

            process_description<pos_iterator_type> p;       // create instance of parser

            qi::phrase_parse(position_begin, position_end, p, qi::space, ast);
            if (position_begin != position_end)
                throw qi::expectation_failure<pos_iterator_type>(position_begin, position_end,boost::spirit::info("general error"));
        }
        catch(const qi::expectation_failure<pos_iterator_type> e)
        {
            const classic::file_position_base<std::string>& pos = e.first.get_position();
            std::cout   << "parse error at file "
                        << pos.file 
                        << " line " 
                        << pos.line 
                        << " column " 
                        << pos.column 
                        << std::endl
                        << e.what_
                        << std::endl
                        << "'"
                        << e.first.get_currentline() 
                        << "'" << std::endl 
                        << std::setw(pos.column) 
                        << " " 
                        << "^- here" 
                        << std::endl;
            return -1;    
        }
        catch(std::string e)
        {
            std::cout   << "logical error: "
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

    return 0;
}

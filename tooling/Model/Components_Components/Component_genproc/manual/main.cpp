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

namespace classic = boost::spirit::classic;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

/* This structure is used by main to communicate with parse_opt. */
struct Arguments
{
    Arguments(): verbose(false), beautify(false), scriptfile(0), xmlfile(0), host(0), port(0) {}
    bool verbose;
    bool beautify;
    char* scriptfile;
    char* xmlfile;
    char* host;
    int port;
};

Arguments arguments;

template <typename Iterator>
struct testscript
  : qi::grammar<Iterator, std::list<std::string>()>
{
    testscript()
      : testscript::base_type(rootElements)
    {

        rootElements    = *(qi::alnum);

    }

    qi::rule<Iterator,std::list<std::string>()> rootElements;

};

const char *argp_program_version =
"genproc 0.1";

const char *argp_program_bug_address =
"<thomas@automotive-scrum.org>";

static struct argp_option options[] =
{
  {"host",    'h', "HOST ADDR",  0, "the tcp address of the target.\n(e.g.: localhost or 127.0.0.1)"},
  {"port",    'p', "HOST PORT",  0, "the port number to connect.\n(e.g.: 23)"},
  {"script",  's', "SCRIPTFILE", 0, "scriptfile to execute"},
  {"verbose", 'v', 0,            0, "verbose info aboout parsing."},
  {"trace",   't', 0,            0, "an additional debug trace (for the testrunner)."},
  {"beautify",'b', 0,            0, "output the parsed text in a beautified form."},
  {"xml"     ,'x', "XML FILE",   0, "output the test report in xml format to this file."},
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
    case 's':
        arguments->scriptfile = arg;
        break;
    case 'h':
        arguments->host = arg;
        break;
    case 'x':
        arguments->xmlfile = arg;
        break;
    case 'p':
        arguments->port = atoi(arg);
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

    if (!arguments.scriptfile)
    {
        printf("you must specify a script file\n");
        exit(1);
    }

    // open file, disable skipping of whitespace
    std::ifstream in(arguments.scriptfile);
    in.unsetf(std::ios::skipws);

    // wrap istream into iterator
    boost::spirit::istream_iterator begin(in);
    boost::spirit::istream_iterator end;

    // wrap forward iterator with position iterator, to record the position
    typedef classic::position_iterator2<boost::spirit::istream_iterator>
        pos_iterator_type;

    pos_iterator_type position_begin(begin, end, arguments.scriptfile);
    pos_iterator_type position_end;

    testscript<pos_iterator_type> p;       // create instance of parser

    try
    {
        std::vector<std::string> s;
        qi::phrase_parse(position_begin, position_end, p, qi::space, s);
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

    return 0;
}

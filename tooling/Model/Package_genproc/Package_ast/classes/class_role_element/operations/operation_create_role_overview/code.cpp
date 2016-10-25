//~~ void create_role_overview(std::ofstream& outfile, const std::string& outpath) [role_element] ~~
FILE *gfile;
std::string linkname = getFullIdentifier() + "_role_overview";
std::string filename = outpath + "/" + linkname;

std::string command("neato ");
command += "-Tpng -o " + filename + ".png ";
command += "-Tcmapx -o " + filename + ".cmapx";

if(!(gfile = popen(command.c_str(), "w")))
    throw(command);

fputs("digraph role_overview {\n", gfile);
fputs("overlap=false\n", gfile);


fputs(get_graph_node(true).c_str(),gfile);
for (std::set<activity_element*>::iterator it = direct_activities.begin(); it != direct_activities.end(); it++)
if (!(*it)->isAbstract())
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = getFullIdentifier()
               + " -> "
               + (*it)->getFullIdentifier()
               + "[arrowhead=\"none\", arrowtail=\"none\", dir=\"both\", color=\"#072551\"];";
    fputs(connection.c_str(),gfile);
}

for (std::set<activity_element*>::iterator it = indirect_activities.begin(); it != indirect_activities.end(); it++)
if (!(*it)->isAbstract())
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = getFullIdentifier()
               + " -> "
               + (*it)->getFullIdentifier()
               + "[arrowhead=\"none\", arrowtail=\"none\", dir=\"both\", style=dashed, color=\"#072551\"];";
    fputs(connection.c_str(),gfile);
}

fputs("}\n",gfile);

create_headline(outfile, "Role overview");

outfile << "<IMG SRC=\""
        << linkname
        << ".png\" USEMAP=\"#role_overview\" title=\"Role overview of role: "
        << getLabel()
        << "\" />"
        << std::endl;

pclose(gfile);
insert_file(outfile, filename + ".cmapx");

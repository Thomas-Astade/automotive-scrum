//~~ void create_artefact_overview(std::ofstream& outfile, const std::string& outpath) [artefact_base] ~~
const I_element* e = dynamic_cast<const I_element*>(this);

FILE *gfile;
std::string linkname = e->getIdentifier() + "_artefact_overview";
std::string filename = outpath + "/" + linkname;

std::string command("dot ");
command += "-Tpng -o " + filename + ".png ";
command += "-Tcmapx -o " + filename + ".cmapx";

if(!(gfile = popen(command.c_str(), "w")))
    throw(command);

fputs("digraph artefact_overview {\n", gfile);
fputs("rankdir=\"LR\";\n", gfile);

fputs(e->get_graph_node(true).c_str(),gfile);

for (std::set<const I_element*>::const_iterator it = m_creator.begin(); it != m_creator.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = (*it)->getIdentifier()
        + " -> "
        + e->getIdentifier()
        + "[arrowhead=\"vee\", arrowtail=\"none\", dir=\"both\", "
        +  text_standards
        + "fontcolor=\"#072551\", color=\"#7B1E00\", label=\"create\"];";
    
    fputs(connection.c_str(),gfile);
}
    
for (std::set<const I_element*>::const_iterator it = m_user.begin(); it != m_user.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = e->getIdentifier()
        + " -> "
        + (*it)->getIdentifier()
        + "[arrowhead=\"vee\", arrowtail=\"none\", dir=\"both\", "
        +  text_standards
        + "fontcolor=\"#072551\", color=\"#7B1E00\", label=\"transform\"];";
    
    fputs(connection.c_str(),gfile);
}

fputs("}\n",gfile);

create_headline(outfile, "Artefact overview");

outfile << "<IMG SRC=\""
        << linkname
        << ".png\" USEMAP=\"#artefact_overview\" />"
        << std::endl;

pclose(gfile);
insert_file(outfile, filename + ".cmapx");
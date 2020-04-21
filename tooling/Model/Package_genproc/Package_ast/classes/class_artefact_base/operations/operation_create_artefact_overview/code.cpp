//~~ void create_artefact_overview(std::ofstream& outfile, const std::string& outpath) [artefact_base] ~~
if (m_creator.empty() && m_user.empty() && m_related.empty() && m_relation.empty())
    return;

const I_element* e = dynamic_cast<const I_element*>(this);

FILE *gfile;
std::string linkname = e->getFullIdentifier() + "_artefact_overview";
std::string filename = outpath + "/" + linkname;

std::string command("dot ");
command += "-Tpng -o " + filename + ".png ";
command += "-Tcmapx -o " + filename + ".cmapx";

if(!(gfile = popen(command.c_str(), "w")))
    throw(command);

fputs("digraph artefact_overview {\n", gfile);
fputs("rankdir=\"LR\";\n", gfile);

fputs(e->get_graph_node(true).c_str(),gfile);

insert_relations(gfile, false, e->getFullIdentifier());
insert_related(gfile, true, e->getFullIdentifier());

if (!processGate.empty())
{
    std::string connection;

    connection = "{rank = same; " + processGate + "; " + e->getFullIdentifier() + ";}\n";
    fputs(connection.c_str(),gfile);

    connection = processGate + "[shape=circle, style=filled, color=red, fillcolor=red];\n"
        + processGate
        + " -> "
        + e->getFullIdentifier()
        + "[arrowhead=\"none\", arrowtail=\"none\", dir=\"both\"];";

    fputs(connection.c_str(),gfile);
}

for (std::set<const I_element*>::const_iterator it = m_creator.begin(); it != m_creator.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;

    connection = (*it)->getFullIdentifier()
        + " -> "
        + e->getFullIdentifier()
        + arrow_create();

    fputs(connection.c_str(),gfile);
}
    
for (std::set<const I_element*>::const_iterator it = m_user.begin(); it != m_user.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = e->getFullIdentifier()
        + " -> "
        + (*it)->getFullIdentifier()
        + arrow_transform();
    
    fputs(connection.c_str(),gfile);
}

fputs("}\n",gfile);

create_headline(outfile, "Artefact overview");

outfile << "<IMG SRC=\""
        << linkname
        << ".png\" USEMAP=\"#artefact_overview\" title=\"Artefact overview of artefact: "
        << e->getLabel()
        << "\" alt=\"spem diagram of an artefact overview: "
        << e->getLabel()
        << "\" />"
        << std::endl;

pclose(gfile);
insert_file(outfile, filename + ".cmapx");

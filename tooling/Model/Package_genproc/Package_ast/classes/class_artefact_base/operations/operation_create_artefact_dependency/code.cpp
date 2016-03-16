//~~ void create_artefact_dependency(std::ofstream& outfile, const std::string& outpath) [artefact_base] ~~
if (m_neededFor.empty() && m_dependsOn.empty())
    return;

const I_element* e = dynamic_cast<const I_element*>(this);

FILE *gfile;
std::string linkname = e->getFullIdentifier() + "_artefact_dependency";
std::string filename = outpath + "/" + linkname;

std::string command("dot ");
command += "-Tpng -o " + filename + ".png ";
command += "-Tcmapx -o " + filename + ".cmapx";

if(!(gfile = popen(command.c_str(), "w")))
    throw(command);

fputs("digraph artefact_dependency {\n", gfile);
fputs("rankdir=\"LR\";\n", gfile);

insert_dependencies(gfile);
fputs(e->get_graph_node(true).c_str(),gfile);

fputs("}\n",gfile);

create_headline(outfile, "Artefact dependency");

outfile << "<IMG SRC=\""
        << linkname
        << ".png\" USEMAP=\"#artefact_dependency\" />"
        << std::endl;

pclose(gfile);
insert_file(outfile, filename + ".cmapx");
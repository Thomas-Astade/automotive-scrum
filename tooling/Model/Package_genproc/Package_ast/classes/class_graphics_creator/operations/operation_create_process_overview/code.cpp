//~~ void create_process_overview(std::ofstream& outfile, const std::string& outpath) [graphics_creator] ~~
const I_element* e = dynamic_cast<const I_element*>(this);
FILE *gfile;
std::string linkname = e->getIdentifier() + "_process_overview";
std::string filename = outpath + "/" + linkname;

std::string command("dot ");
command += "-Tpng -o " + filename + ".png ";
command += "-Tcmapx -o " + filename + ".cmapx";

if(!(gfile = popen(command.c_str(), "w")))
    throw(command);

fputs("digraph process_overview {\n", gfile);
fputs(e->get_graph_node().c_str(),gfile);
fputs("}\n",gfile);

create_headline(outfile, "Process overview");

outfile << "<IMG SRC=\""
        << linkname
        << ".png\" USEMAP=\"#process_overview\" />"
        << std::endl;

pclose(gfile);
insert_file(outfile, filename + ".cmapx");
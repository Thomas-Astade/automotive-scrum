//~~ void create_activity_breakdown(std::ofstream& outfile, const std::string& outpath) [graphics_creator] ~~
const I_element* e = dynamic_cast<const I_element*>(this);
FILE *gfile;
std::string linkname = e->getIdentifier() + "_activity_breakdown";
std::string filename = outpath + "/" + linkname;

std::string command("dot ");
command += "-Tpng -o " + filename + ".png ";
command += "-Tcmapx -o " + filename + ".cmapx";

if(!(gfile = popen(command.c_str(), "w")))
    throw(command);

fputs("digraph activity_breakdown {\n", gfile);
fputs(e->get_graph_node().c_str(),gfile);
fputs("}\n",gfile);

outfile << "<h1 class=\"chapter\">Activity break down</h1>" << std::endl;

outfile << "<IMG SRC=\""
        << linkname
        << ".png\" USEMAP=\"#activity_breakdown\" />"
        << std::endl;

pclose(gfile);
insert_file(outfile, filename + ".cmapx");
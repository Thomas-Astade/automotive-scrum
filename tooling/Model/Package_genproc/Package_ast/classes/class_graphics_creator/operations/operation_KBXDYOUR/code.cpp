//~~ void create_activity_overview(std::ofstream& outfile, const std::string& outpath) [graphics_creator] ~~
const I_element* e = dynamic_cast<const I_element*>(this);

FILE *gfile;
std::string linkname = e->getIdentifier() + "_activity_overview";
std::string filename = outpath + "/" + linkname;

std::string command("dot ");
command += "-Tpng -o " + filename + ".png ";
command += "-Tcmapx -o " + filename + ".cmapx";

if(!(gfile = popen(command.c_str(), "w")))
    throw(command);

fputs("digraph activity_overview {\n", gfile);

fputs(e->get_graph_node(true).c_str(),gfile);

fputs("}\n",gfile);

create_headline(outfile, "Activity overview");

outfile << "<IMG SRC=\""
        << linkname
        << ".png\" USEMAP=\"#activity_overview\" />"
        << std::endl;

pclose(gfile);
insert_file(outfile, filename + ".cmapx");
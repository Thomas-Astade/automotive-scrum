//~~ void create_process_overview(std::ofstream& outfile, const std::string& outpath) [process_element] ~~
const I_element* e = dynamic_cast<const I_element*>(this);
FILE *gfile;
std::string linkname = e->getFullIdentifier() + "_process_overview";
std::string filename = outpath + "/" + linkname;

std::string command("dot ");
command += "-Tpng -o " + filename + ".png ";
command += "-Tcmapx -o " + filename + ".cmapx";

if(!(gfile = popen(command.c_str(), "w")))
    throw(command);

fputs("digraph process_overview {\n", gfile);
//fputs("overlap=false\n", gfile);
fputs("rankdir=\"UD\";\n", gfile);

fputs(e->get_graph_node(true).c_str(),gfile);
insert_role(gfile);
insert_transform(gfile);
insert_repositories(gfile);
insert_tool(gfile);
insert_create(gfile);

fputs("}\n",gfile);

create_headline(outfile, "Process overview");

outfile << "<IMG SRC=\""
        << linkname
        << ".png\" USEMAP=\"#process_overview\" title=\"Process overview of process: "
        << e->getLabel()
        << "\" alt=\"spem diagram of a process overview: " 
        << e->getLabel()
        << "\" />"
        << std::endl;

pclose(gfile);
insert_file(outfile, filename + ".cmapx");

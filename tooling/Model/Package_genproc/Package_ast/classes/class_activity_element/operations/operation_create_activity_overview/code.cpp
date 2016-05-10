//~~ void create_activity_overview(std::ofstream& outfile, const std::string& outpath) [activity_element] ~~
const I_element* e = dynamic_cast<const I_element*>(this);

FILE *gfile;
std::string linkname = e->getFullIdentifier() + "_activity_overview";
std::string filename = outpath + "/" + linkname;

std::string command("dot ");
command += "-Tpng -o " + filename + ".png ";
command += "-Tcmapx -o " + filename + ".cmapx";

if(!(gfile = popen(command.c_str(), "w")))
    throw(command);

fputs("digraph activity_overview {\n", gfile);
fputs("rankdir=\"LR\";\n", gfile);

insert_process(gfile);
fputs(e->get_graph_node(true).c_str(),gfile);
insert_role(gfile);
insert_tool(gfile);
insert_create(gfile);
insert_transform(gfile);
insert_specializes(gfile);
insert_states(gfile);

fputs("}\n",gfile);

create_headline(outfile, "Activity overview");

outfile << "<IMG SRC=\""
        << linkname
        << ".png\" USEMAP=\"#activity_overview\" />"
        << std::endl;

pclose(gfile);
insert_file(outfile, filename + ".cmapx");
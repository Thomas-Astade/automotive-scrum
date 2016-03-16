//~~ void create_artefact_breakdown(std::ofstream& outfile, const std::string& outpath) [graphics_creator] ~~
const I_element* e = dynamic_cast<const I_element*>(this);
const parent_owner* p = dynamic_cast<const parent_owner*>(this);

FILE *gfile;
std::string linkname = e->getFullIdentifier() + "_artefact_breakdown";
std::string filename = outpath + "/" + linkname;

std::string command("dot ");
command += "-Tpng -o " + filename + ".png ";
command += "-Tcmapx -o " + filename + ".cmapx";

if(!(gfile = popen(command.c_str(), "w")))
    throw(command);

fputs("digraph artefact_breakdown {\n", gfile);
fputs("rankdir=\"LR\";\n", gfile);

if (p)
{
    const graphics_creator* g = dynamic_cast<const graphics_creator*>(p->getParent());
    const process_element* pr = dynamic_cast<const process_element*>(p->getParent());
    if (pr)
    {
        pr->insert_repositories(gfile);
        fputs(p->getParent()->get_graph_node(false).c_str(),gfile);
    }
    else if (g)
    {
        g->insert_child_nodes(gfile);
        fputs(p->getParent()->get_graph_node(false).c_str(),gfile);
    }
}

fputs(e->get_graph_node(true).c_str(),gfile);
    
const process_element* pr2 = dynamic_cast<const process_element*>(this);
if (pr2)
    pr2->insert_repositories(gfile);
else
    insert_child_nodes(gfile);
fputs("}\n",gfile);

create_headline(outfile, "Artefact break down");

outfile << "<IMG SRC=\""
        << linkname
        << ".png\" USEMAP=\"#artefact_breakdown\" />"
        << std::endl;

pclose(gfile);
insert_file(outfile, filename + ".cmapx");
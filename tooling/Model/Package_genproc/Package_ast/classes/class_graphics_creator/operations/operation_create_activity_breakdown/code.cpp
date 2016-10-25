//~~ void create_activity_breakdown(std::ofstream& outfile, const std::string& outpath) [graphics_creator] ~~
const I_element* e = dynamic_cast<const I_element*>(this);
const parent_owner* p = dynamic_cast<const parent_owner*>(this);
const subpage_owner* s = dynamic_cast<const subpage_owner*>(this);

FILE *gfile;
std::string linkname = e->getFullIdentifier() + "_activity_breakdown";
std::string filename = outpath + "/" + linkname;

std::string command("dot ");
command += "-Tpng -o " + filename + ".png ";
command += "-Tcmapx -o " + filename + ".cmapx";

if(!(gfile = popen(command.c_str(), "w")))
    throw(command);

fputs("digraph activity_breakdown {\n", gfile);
fputs("rankdir=\"LR\";\n", gfile);

int i = 3;

if ((s==0) || (!s->hasSubpages()))
    i=4;

while (p && (i-- > 0))
{
    const graphics_creator* g = dynamic_cast<const graphics_creator*>(p->getParent());
    if (g)
    {
        g->insert_child_nodes(gfile);
        fputs(p->getParent()->get_graph_node(false).c_str(),gfile);
    }
    else 
        i = 0;

    p = dynamic_cast<const parent_owner*>(p->getParent());
}

fputs(e->get_graph_node(true).c_str(),gfile);
    
insert_child_nodes(gfile);
fputs("}\n",gfile);

create_headline(outfile, "Activity break down");

outfile << "<IMG SRC=\""
        << linkname
        << ".png\" USEMAP=\"#activity_breakdown\" title=\"Activity break down of activity: "
        << e->getLabel()
        << "\" alt=\"spem diagram of activity breakdown: "
        << e->getLabel()
        << "\" />"
        << std::endl;

pclose(gfile);
insert_file(outfile, filename + ".cmapx");

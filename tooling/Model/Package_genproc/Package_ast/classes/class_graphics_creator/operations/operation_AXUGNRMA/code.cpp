//~~ void insert_process(FILE* gfile) [graphics_creator] ~~
const I_element* e =  dynamic_cast<const I_element*>(this);
const process_member* p = dynamic_cast<const process_member*>(e);

if (!p || !p->getProcess())
    return;
    
fputs(p->getProcess()->get_graph_node(false).c_str(),gfile);
std::string connection;
connection = p->getProcess()->getIdentifier()
           + " -> "
           + e->getIdentifier()
           + "[arrowhead=\"none\", arrowtail=\"none\", dir=\"both\", style=dashed, color=\"#7B1E00\"];";
fputs(connection.c_str(),gfile);
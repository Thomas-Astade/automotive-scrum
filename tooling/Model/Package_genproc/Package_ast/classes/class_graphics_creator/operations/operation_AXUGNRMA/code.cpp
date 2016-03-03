//~~ void insert_process(FILE* gfile) [graphics_creator] ~~
const I_element* e =  dynamic_cast<const I_element*>(this);
const process_member* p = dynamic_cast<const process_member*>(e);

if (!p || !p->getProcess())
    return;
    
fputs(p->getProcess()->get_graph_node(false).c_str(),gfile);
std::string connection;
bool isDirect;
connection = p->getProcess(&isDirect)->getIdentifier()
           + " -> "
           + e->getIdentifier();
if (isDirect)
    connection += "[arrowhead=\"none\", arrowtail=\"diamond\", dir=\"both\", color=\"#072551\"];";
else
    connection += "[arrowhead=\"none\", arrowtail=\"diamond\", dir=\"both\", style=dashed, color=\"#072551\"];";
    
fputs(connection.c_str(),gfile);
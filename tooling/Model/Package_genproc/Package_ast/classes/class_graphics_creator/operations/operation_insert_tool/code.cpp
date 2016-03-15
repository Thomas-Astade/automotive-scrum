//~~ void insert_tool(FILE* gfile) [graphics_creator] ~~
const I_element* e =  dynamic_cast<const I_element*>(this);
const role_owner* r = dynamic_cast<const role_owner*>(this);

if (!r || !r->getTool())
    return;
    
fputs(r->getTool()->get_graph_node(false).c_str(),gfile);
std::string connection;
bool isDirect;
connection = e->getIdentifier()
           + " -> "
           + r->getTool(&isDirect)->getIdentifier();
           
if (isDirect)
    connection += "[arrowhead=\"none\", arrowtail=\"none\", dir=\"both\", color=\"#71B191\"];";
else
    connection += "[arrowhead=\"none\", arrowtail=\"none\", dir=\"both\", style=dashed, color=\"#71B191\"];";
    
fputs(connection.c_str(),gfile);
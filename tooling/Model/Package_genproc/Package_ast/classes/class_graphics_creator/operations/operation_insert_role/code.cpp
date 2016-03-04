//~~ void insert_role(FILE* gfile) [graphics_creator] ~~
const I_element* e =  dynamic_cast<const I_element*>(this);
const role_owner* r = dynamic_cast<const role_owner*>(this);

if (!r || !r->getRole())
    return;
    
fputs(r->getRole()->get_graph_node(false).c_str(),gfile);
std::string connection;
bool isDirect;
connection = r->getRole(&isDirect)->getIdentifier()
           + " -> "
           + e->getIdentifier();
if (isDirect)
    connection += "[arrowhead=\"none\", arrowtail=\"none\", dir=\"both\", color=\"#7B1E00\"];";
else
    connection += "[arrowhead=\"none\", arrowtail=\"none\", dir=\"both\", style=dashed, color=\"#7B1E00\"];";
    
fputs(connection.c_str(),gfile);
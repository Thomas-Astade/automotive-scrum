//~~ void insert_participants(FILE* gfile) [graphics_creator] ~~
const I_element* e =  dynamic_cast<const I_element*>(this);
const role_owner* r = dynamic_cast<const role_owner*>(this);

if (!r || !r->getRole())
    return;
    
std::string connection;

for (auto it : r->my_participants)
{
    fputs(it->get_graph_node(false).c_str(),gfile);
    connection = it->getFullIdentifier()
               + " -> "
               + e->getFullIdentifier();
    connection += "[arrowhead=\"none\", arrowtail=\"none\", dir=\"both\", style=dotted, color=\"#7B1E00\"];";
    fputs(connection.c_str(),gfile);
}

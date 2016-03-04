//~~ void insert_role(FILE* gfile) [process_element] ~~
graphics_creator::insert_role(gfile);

for (std::set<role_element*>::iterator it = implicite_roles.begin(); it != implicite_roles.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = (*it)->label_owner::getIdentifier()
           + " -> "
           + label_owner::getIdentifier()
           + "[arrowhead=\"none\", arrowtail=\"none\", dir=\"both\", style=dashed, color=\"#7B1E00\"];";
    
    fputs(connection.c_str(),gfile);
}
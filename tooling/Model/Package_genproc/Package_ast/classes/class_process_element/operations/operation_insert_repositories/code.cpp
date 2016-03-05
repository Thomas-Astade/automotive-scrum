//~~ void insert_repositories(FILE* gfile) [process_element] ~~
for (std::vector<repository_element*>::const_iterator it = repository_PTR.begin(); it != repository_PTR.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = label_owner::getIdentifier()
           + " -> "
           + (*it)->label_owner::getIdentifier()
           + "[arrowhead=\"none\", arrowtail=\"none\", dir=\"both\", style=dashed, color=\"#072551\"];";
    
    fputs(connection.c_str(),gfile);
}
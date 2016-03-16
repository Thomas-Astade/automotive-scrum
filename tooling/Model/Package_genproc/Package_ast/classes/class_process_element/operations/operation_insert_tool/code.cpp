//~~ void insert_tool(FILE* gfile) [process_element] ~~
for (std::set<tool_element*>::iterator it = implicite_tools.begin(); it != implicite_tools.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = getFullIdentifier()
           + " -> "
           + (*it)->getFullIdentifier()
           + "[arrowhead=\"none\", arrowtail=\"none\", dir=\"both\", style=dashed, color=\"#71B191\"];";
    
    fputs(connection.c_str(),gfile);
}
//~~ void insert_specialized(FILE* gfile) [activity_element] ~~
for (std::set<activity_element*>::const_iterator it = m_specialized.begin(); it != m_specialized.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = (*it)->getFullIdentifier()
        + " -> "
        + getFullIdentifier()
        + arrow_specialize();
    
    fputs(connection.c_str(),gfile);
}

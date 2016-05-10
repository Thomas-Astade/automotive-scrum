//~~ void insert_specializes(FILE* gfile) [activity_element] ~~
for (std::set<activity_element*>::const_iterator it = m_specializes.begin(); it != m_specializes.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = getFullIdentifier()
        + " -> "
        + (*it)->getFullIdentifier()
        + arrow_specialize();
    
    fputs(connection.c_str(),gfile);
}

//~~ void insert_related(FILE* gfile, bool forward, const std::string& node) [artefact_base] ~~
for (std::set<const I_element*>::const_iterator it = m_related.begin(); it != m_related.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    
    if (forward)
    connection = node
               + " -> "
               + (*it)->getFullIdentifier()
               + "[arrowhead=\"none\", arrowtail=\"vee\", dir=\"both\", color=\"#072551\"];";
    else
    connection = (*it)->getFullIdentifier()
               + " -> "
               + node
               + "[arrowhead=\"vee\", arrowtail=\"none\", dir=\"both\", color=\"#072551\"];";
               
    fputs(connection.c_str(),gfile);
}
//~~ void insert_relations(FILE* gfile, bool forward, const std::string& node) [artefact_base] ~~
for (std::set<const I_element*>::const_iterator it = m_relation.begin(); it != m_relation.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    
    if (forward)
    connection = node
               + " -> "
               + (*it)->getFullIdentifier()
               + "[arrowhead=\"vee\", arrowtail=\"none\", dir=\"both\", color=\"#072551\"];";
    else
    connection = (*it)->getFullIdentifier()
               + " -> "
               + node
               + "[arrowhead=\"none\", arrowtail=\"vee\", dir=\"both\", color=\"#072551\"];";
               
    fputs(connection.c_str(),gfile);
}
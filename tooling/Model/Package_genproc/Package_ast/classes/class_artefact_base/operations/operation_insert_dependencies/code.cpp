//~~ void insert_dependencies(FILE* gfile) [artefact_base] ~~
const I_element* e =  dynamic_cast<const I_element*>(this);
    
for (std::set<const I_element*>::const_iterator it = m_neededFor.begin(); it != m_neededFor.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = (*it)->getFullIdentifier()
               + " -> "
               + e->getFullIdentifier()
               + "[arrowhead=\"none\", arrowtail=\"normal\", style=dashed, dir=\"both\", color=\"#072551\"];";
        
    fputs(connection.c_str(),gfile);
}

for (std::set<const I_element*>::const_iterator it = m_dependsOn.begin(); it != m_dependsOn.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = e->getFullIdentifier()
               + " -> "
               + (*it)->getFullIdentifier()
               + "[arrowhead=\"none\", arrowtail=\"normal\", style=dashed, dir=\"both\", color=\"#072551\"];";
        
    fputs(connection.c_str(),gfile);
}

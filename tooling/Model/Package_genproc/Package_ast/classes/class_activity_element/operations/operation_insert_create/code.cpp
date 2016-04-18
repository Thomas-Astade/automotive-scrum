//~~ void insert_create(FILE* gfile) [activity_element] ~~
const std::vector<artefact_base*>& c = getCreate();

for (std::vector<artefact_base*>::const_iterator it = c.begin(); it != c.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = getFullIdentifier()
        + " -> "
        + (*it)->getFullIdentifier()
        + arrow_create();
    
    fputs(connection.c_str(),gfile);
    
    (*it)->insert_relations(gfile,true,(*it)->getFullIdentifier());
    
    const parent_owner* p = dynamic_cast<const parent_owner*>(*it);
    if (p)
    {
        if (p->getParent())
        {
            fputs(p->getParent()->get_graph_node(false).c_str(),gfile);
            connection = (*it)->getFullIdentifier()
                       + " -> "
                       + p->getParent()->getFullIdentifier()
                       + "[arrowhead=\"diamond\", arrowtail=\"none\", dir=\"both\", color=\"#072551\"];";
            
            fputs(connection.c_str(),gfile);
        }
    }
}

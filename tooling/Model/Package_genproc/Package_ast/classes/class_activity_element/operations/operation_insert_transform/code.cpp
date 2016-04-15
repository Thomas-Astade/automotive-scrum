//~~ void insert_transform(FILE* gfile) [activity_element] ~~
const std::vector<artefact_base*>& c = getTransform();

for (std::vector<artefact_base*>::const_iterator it = c.begin(); it != c.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = (*it)->getFullIdentifier()
        + " -> "
        + getFullIdentifier()
        + "[arrowhead=\"vee\", arrowtail=\"none\", dir=\"both\", "
        +  text_standards
        + "fontcolor=\"#072551\", color=\"#7B1E00\", label=\"transform\"];";
    
    fputs(connection.c_str(),gfile);
    
    (*it)->insert_relations(gfile,false,(*it)->getFullIdentifier());
    
    const parent_owner* p = dynamic_cast<const parent_owner*>(*it);
    if (p)
    {
        if (p->getParent())
        {
            fputs(p->getParent()->get_graph_node(false).c_str(),gfile);
            connection = p->getParent()->getFullIdentifier()
                       + " -> "
                       + (*it)->getFullIdentifier()
                       + "[arrowhead=\"none\", arrowtail=\"diamond\", dir=\"both\", color=\"#072551\"];";
            
            fputs(connection.c_str(),gfile);
        }
    }
}

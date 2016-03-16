//~~ void insert_create(FILE* gfile) [activity_element] ~~
const std::vector<artefact_base*>& c = getCreate();

for (std::vector<artefact_base*>::const_iterator it = c.begin(); it != c.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = label_owner::getIdentifier()
        + " -> "
        + (*it)->label_owner::getIdentifier()
        + "[arrowhead=\"vee\", arrowtail=\"none\", dir=\"both\", "
        +  text_standards
        + "fontcolor=\"#072551\", color=\"#7B1E00\", label=\"create\"];";
    
    fputs(connection.c_str(),gfile);
    
    const parent_owner* p = dynamic_cast<const parent_owner*>(*it);
    if (p)
    {
        if (p->getParent())
        {
            fputs(p->getParent()->get_graph_node(false).c_str(),gfile);
            connection = (*it)->label_owner::getIdentifier()
                       + " -> "
                       + p->getParent()->getIdentifier()
                       + "[arrowhead=\"diamond\", arrowtail=\"none\", dir=\"both\", color=\"#072551\"];";
            
            fputs(connection.c_str(),gfile);
        }
    }
}

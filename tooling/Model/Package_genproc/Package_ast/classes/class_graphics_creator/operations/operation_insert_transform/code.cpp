//~~ void insert_transform(FILE* gfile) [graphics_creator] ~~
const activity_element* a =  dynamic_cast<const activity_element*>(this);

if (a == 0)
    return;

const std::vector<artefact_base*>& c = a->getTransform();

for (std::vector<artefact_base*>::const_iterator it = c.begin(); it != c.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = (*it)->label_owner::getIdentifier()
        + " -> "
        + a->label_owner::getIdentifier()
        + "[arrowhead=\"vee\", arrowtail=\"none\", dir=\"both\", "
        +  text_standards
        + "fontcolor=\"#072551\", color=\"#7B1E00\", label=\"transform\"];";
    
    fputs(connection.c_str(),gfile);
}

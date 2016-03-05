//~~ void insert_create(FILE* gfile) [graphics_creator] ~~
const activity_element* a =  dynamic_cast<const activity_element*>(this);

if (a == 0)
    return;

const std::vector<artefact_base*>& c = a->getCreate();

for (std::vector<artefact_base*>::const_iterator it = c.begin(); it != c.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = a->label_owner::getIdentifier()
        + " -> "
        + (*it)->label_owner::getIdentifier()
        + "[arrowhead=\"vee\", arrowtail=\"none\", dir=\"both\", "
        +  text_standards
        + "fontcolor=\"#072551\", color=\"#7B1E00\", label=\"create\"];";
    
    fputs(connection.c_str(),gfile);
}

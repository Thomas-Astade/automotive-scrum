//~~ void insert_transform(FILE* gfile) [process_element] ~~
const std::vector<artefact_base*>& c = getTransform();

for (std::vector<artefact_base*>::const_iterator it = c.begin(); it != c.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = getFullIdentifier()
        + " -> "
        + (*it)->getFullIdentifier()
        + "[arrowhead=\"none\", arrowtail=\"vee\", dir=\"both\", "
        +  text_standards
        + "fontcolor=\"#072551\", color=\"#7B1E00\", label=\"transform\"];";
    
    fputs(connection.c_str(),gfile);
}

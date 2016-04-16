//~~ void insert_transform(FILE* gfile) [process_element] ~~
const std::vector<artefact_base*>& c = getTransform();

for (std::vector<artefact_base*>::const_iterator it = c.begin(); it != c.end(); it++)
{
    fputs((*it)->get_graph_node(false).c_str(),gfile);
    std::string connection;
    connection = getFullIdentifier()
        + " -> "
        + (*it)->getFullIdentifier()
        + arrow_transform();
    
    fputs(connection.c_str(),gfile);
}

//~~ std::string get_graph_node(bool isSelected) [role_element] ~~
std::string ret;
std::string fc = "#FCB7A2";
    
ret += label_owner::getIdentifier()
    + "["
    + graphics_creator::text_standards
    + "shape=doublecircle, style=filled, color=\"#7B1E00\", fillcolor=\""
    + fc
    + "\", fontcolor=\"#7B1E00\", label=\""
    + breakApart(label_owner::getLabel())
    + "\", "
    + "tooltip=\""
    + label_owner::getBrief()
    + "\", URL=\""
    + getHtmlFilename()
    + "\"];";
return ret;
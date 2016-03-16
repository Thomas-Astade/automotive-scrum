//~~ std::string get_graph_node(bool isSelected) [process_element] ~~
std::string ret;
ret += getFullIdentifier()
    + "["
    + graphics_creator::text_standards
    + "shape=box3d, style=filled, color=\"#A57521\", fillcolor=\"#7B4E00\", fontcolor=\"#FCDBA2\", label=\""
    + label_owner::getLabel()
    + "\", URL=\""
    + getHtmlFilename()
    + "\"];";
return ret;
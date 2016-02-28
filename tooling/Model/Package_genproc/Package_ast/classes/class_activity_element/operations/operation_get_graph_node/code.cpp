//~~ std::string get_graph_node() [activity_element] ~~
std::string ret;
ret += label_owner::getIdentifier()
    + "["
    + graphics_creator::text_standards
    + "shape=house, orientation=270, style=filled, color=\"#A57521\", fillcolor=\"#FCDBA2\", fontcolor=\"#7B4E00\", label=\""
    + label_owner::getLabel()
    + "\", URL=\""
    + getHtmlFilename()
    + "\"];";
return ret;
//~~ std::string get_graph_node(bool isSelected) [repository_element] ~~
std::string ret;
std::string fc;

ret += label_owner::getIdentifier()
    + "["
    + graphics_creator::text_standards
    + "shape=box, image=\"repository.png\", imagescale=width, color=white, fontcolor=\"#7B4E00\", label=\""
    + breakApart(label_owner::getLabel())
    + "\", "
    + "tooltip=\""
    + label_owner::getBrief()
    + "\", URL=\""
    + getHtmlFilename()
    + "\"];";
return ret;
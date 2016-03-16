//~~ std::string get_graph_node(bool isSelected) [repository_element] ~~
std::string ret;

ret += getFullIdentifier()
    + "["
    + graphics_creator::text_standards;
    if (isSelected)
        ret += "shape=box, image=\"repository_selected.png\", imagescale=width, color=white, fontcolor=\"#072551\", label=\"";
    else
        ret += "shape=box, image=\"repository.png\", imagescale=width, color=white, fontcolor=\"#072551\", label=\"";
    ret += breakApart(label_owner::getLabel())
    + "\", "
    + "tooltip=\""
    + label_owner::getBrief()
    + "\", URL=\""
    + getHtmlFilename()
    + "\"];";
return ret;
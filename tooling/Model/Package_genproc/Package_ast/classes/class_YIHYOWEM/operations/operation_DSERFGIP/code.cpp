//~~ std::string get_graph_node(bool isSelected) [folder_element] ~~
std::string ret;

ret += label_owner::getIdentifier()
    + "["
    + graphics_creator::text_standards;
    if (isSelected)
        ret += "shape=box, image=\"folder_selected.png\", imagescale=width, color=white, fontcolor=\"#072551\", label=\"";
    else
        ret += "shape=box, image=\"folder.png\", imagescale=width, color=white, fontcolor=\"#072551\", label=\"";
    ret += breakApart(label_owner::getLabel())
    + "\", "
    + "tooltip=\""
    + label_owner::getBrief()
    + "\", URL=\""
    + getHtmlFilename()
    + "\"];";
return ret;
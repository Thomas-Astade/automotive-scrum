//~~ std::string get_graph_node(bool isSelected) [tool_element] ~~
std::string ret;
    
ret += label_owner::getIdentifier()
    + "["
    + graphics_creator::text_standards
    + "shape=box, image=\"tool.png\", color=white, fontcolor=\"#7B1E00\", label=\""
    + "\\n\\n\\n" + breakApart(label_owner::getLabel())
    + "\", "
    + "tooltip=\""
    + label_owner::getBrief()
    + "\", URL=\""
    + getHtmlFilename()
    + "\"];";
return ret;
//~~ std::string get_graph_node(bool isSelected) [I_element] ~~
std::string ret;
ret += getFullIdentifier()
    + "[label=\""
    + getLabel()
    + "\", URL=\""
    + getHtmlFilename()
    + "\"];";
return ret;
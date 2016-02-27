//~~ std::string get_graph_node() [I_element] ~~
std::string ret;
ret += getIdentifier()
    + "[label=\""
    + getLabel()
    + "\", URL=\""
    + getHtmlFilename()
    + "\"];";
return ret;
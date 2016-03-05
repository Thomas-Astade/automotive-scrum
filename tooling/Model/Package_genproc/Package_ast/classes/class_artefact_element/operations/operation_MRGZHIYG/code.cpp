//~~ std::string get_graph_node(bool isSelected) [artefact_element] ~~
std::string ret;
std::string fc;

if (isSelected)
    fc = "#ABB6C7";
else
    fc = "#7086A6";
    
ret += label_owner::getIdentifier()
    + "["
    + graphics_creator::text_standards
    + "shape=note, style=filled, color=\"#072551\", fillcolor=\""
    + fc
    + "\", fontcolor=\"#072551\", label=\""
    + breakApart(label_owner::getLabel())
    + "\", "
    + "tooltip=\""
    + label_owner::getBrief()
    + "\", URL=\""
    + getHtmlFilename()
    + "\"];";
return ret;
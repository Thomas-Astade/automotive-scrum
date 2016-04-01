//~~ std::string get_graph_node(bool isSelected) [artefact_element] ~~
if (!state_changes.empty())
    return get_graph_node(isSelected,"");

std::string ret;
std::string fc;

if (isSelected)
    fc = "#ABB6C7";
else
    fc = "#7086A6";
    
ret += getFullIdentifier()
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
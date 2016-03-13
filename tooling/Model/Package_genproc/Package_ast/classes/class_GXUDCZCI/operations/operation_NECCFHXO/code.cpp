//~~ std::string get_graph_node(bool isSelected) [virtual_artefact] ~~
std::string ret;
    
ret += label_owner::getIdentifier()
    + "["
    + graphics_creator::text_standards
    + "shape=note, style=filled, style=dashed, color=\"#072551\", fillcolor=\"white\", fontcolor=\"#072551\", label=\""
    + breakApart(label_owner::getLabel())
    + "\", "
    + "tooltip=\""
    + label_owner::getBrief()
    + "\"];";
return ret;
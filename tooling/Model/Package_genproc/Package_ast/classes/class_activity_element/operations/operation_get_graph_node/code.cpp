//~~ std::string get_graph_node(bool isSelected) [activity_element] ~~
std::string ret;
std::string fc;

if (isSelected)
    fc = "#FFF1D9";
else
    fc = "#FCDBA2";
    
ret += label_owner::getIdentifier()
    + "["
    + graphics_creator::text_standards
    + "shape=house, orientation=270, style=filled, color=\"#A57521\", fillcolor=\""
    + fc
    + "\", fontcolor=\"#7B4E00\", label=\""
    + label_owner::getLabel()
    + "\", URL=\""
    + getHtmlFilename()
    + "\"];";
return ret;
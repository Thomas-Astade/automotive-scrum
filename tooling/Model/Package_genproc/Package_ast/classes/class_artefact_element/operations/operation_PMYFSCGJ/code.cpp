//~~ std::string get_graph_node(bool isSelected, const std::string& state) [artefact_element] ~~
std::string ret;
std::string fc;

if (isSelected)
    fc = "#177445";
else
    fc = "#00562";
    
ret = getFullIdentifier();

if (!state.empty())
{
    ret += "_";
    ret += state;
}

ret +=  " ["
     + graphics_creator::text_standards
     + "shape=Mrecord, label=\"" 
     + breakApart(label_owner::getLabel())
     + "|"
     + state
     + "\", tooltip=\""
     + label_owner::getBrief()
     + "\", URL=\""
     + getHtmlFilename()
     + std::string("\", style=filled, color=\"#AFCEBE\", fillcolor=\""
     + fc
     + "\", ")
     + "fontcolor=\"#AFCEBE\"];";
return ret;
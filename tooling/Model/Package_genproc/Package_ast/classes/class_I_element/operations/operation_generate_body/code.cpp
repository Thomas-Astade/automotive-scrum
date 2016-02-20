//~~ void generate_body(std::ofstream& file) [I_element] ~~
file << "<div>"
     << getType()
     << " "
     << getLabel()
     << "</div>"
     << std::endl;
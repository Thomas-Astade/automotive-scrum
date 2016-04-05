//~~ void generate_body(std::ofstream& file, const std::string& outpath) [I_element] ~~
file << "<div>"
     << getType()
     << " "
     << getLabel()
     << "</div>"
     << std::endl;
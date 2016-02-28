//~~ void generate_body(std::ofstream& file, const std::string& outpath) [activity_element] ~~
create_activity_breakdown(file,outpath);
file << "<h1 class=\"chapter\">Detailed description for "
     << getType()
     << " \""
     << label_owner::getLabel()
     << "\"</h1>" << std::endl;

text_owner::generate(file);
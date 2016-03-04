//~~ void generate_body(std::ofstream& file, const std::string& outpath) [process_element] ~~
create_process_overview(file,outpath);
create_activity_breakdown(file,outpath);
file << "<h1 class=\"chapter\">Detailed description for "
     << getType()
     << " \""
     << label_owner::getLabel()
     << "\"</h1>" << std::endl;
text_owner::generate(file);

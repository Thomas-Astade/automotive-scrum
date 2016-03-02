//~~ void generate_body(std::ofstream& file, const std::string& outpath) [activity_element] ~~
create_activity_overview(file,outpath);
create_activity_breakdown(file,outpath);
if (hasBriefDescription())
{
    file << "<h1 class=\"chapter\">Brief description of "
         << getType()
         << " \""
         << label_owner::getLabel()
         << "\"</h1>" << std::endl;
    file << "<p>"
         << getBrief()
         << "</p>" << std::endl;
}
if (hasText())
    file << "<h1 class=\"chapter\">Detailed description of "
         << getType()
         << " \""
         << label_owner::getLabel()
         << "\"</h1>" << std::endl;

text_owner::generate(file);
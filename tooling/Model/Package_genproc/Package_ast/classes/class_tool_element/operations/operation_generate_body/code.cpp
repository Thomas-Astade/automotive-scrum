//~~ void generate_body(std::ofstream& file, const std::string& outpath) [tool_element] ~~
create_tool_overview(file, outpath);

if (hasBriefDescription())
{
    file << "<h1 class=\"chapter\">Brief description of "
         << getType()
         << " \""
         << label_owner::getLabel()
         << "\"</h1>" << std::endl;
    file << "<p>"
         << label_owner::getBrief()
         << "</p>" << std::endl;
}
if (hasText())
    file << "<h1 class=\"chapter\">Detailed description of "
         << getType()
         << " \""
         << label_owner::getLabel()
         << "\"</h1>" << std::endl;

text_owner::generate(file);
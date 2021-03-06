//~~ void generate_body(std::ofstream& file, const std::string& outpath) [artefact_base] ~~
create_artefact_statechart(file,outpath);
create_artefact_overview(file,outpath);
create_artefact_breakdown(file,outpath);
create_artefact_dependency(file,outpath);
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
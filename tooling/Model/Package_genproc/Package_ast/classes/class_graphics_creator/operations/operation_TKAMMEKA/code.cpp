//~~ void create_headline(std::ofstream& outfile, const std::string& name) [graphics_creator] ~~
const I_element* e = dynamic_cast<const I_element*>(this);

outfile << "<h1 class=\"chapter\">"
        << name
        << " for "
        << e->getType()
        << " \""
        << e->getLabel()
        << "\"</h1>" << std::endl;

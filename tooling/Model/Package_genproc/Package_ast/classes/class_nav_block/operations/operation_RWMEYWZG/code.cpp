//~~ void generate(std::ofstream& file) [nav_block] ~~
if (!my_nav_entrys.empty())
{
    file << "<tr class=\"header\">" << std::endl;
    file << "<td>" << std::endl;
    file << "<table border=\"3\" cellpadding=\"0\" cellspacing=\"0\" >" << std::endl;
    for (unsigned int i = 0; i < linecount; i++)
    {
        file << "<tr>" << std::endl;
        for (std::vector<nav_entry>::iterator it=my_nav_entrys.begin(); it!=my_nav_entrys.end(); it++)
        {
            std::string label(" ");
            if ((*it).subpage_PTR.size() > i)
                label = (*it).subpage_PTR[i]->getLabel();
                
            file << "<td class=\"nav_sel\">"
                 << label
                 << "</td>" << std::endl;
        }
        file << "</tr>" << std::endl;
    }
    file << "</table>" << std::endl;
    file << "</td>" << std::endl;
    file << "</tr>" << std::endl;
}
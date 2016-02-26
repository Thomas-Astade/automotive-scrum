//~~ void generate(std::ofstream& file) [nav_block] ~~
if (!my_nav_entrys.empty())
{
    file << "<tr class=\"header\">" << std::endl;
    file << "<td>" << std::endl;
    file << "<table border=\"10\" cellpadding=\"0\" cellspacing=\"0\" >" << std::endl;
    for (unsigned int i = 0; i < linecount; i++)
    {
        file << "<tr>" << std::endl;
        std::vector<nav_entry>::iterator old = my_nav_entrys.begin();
        for (std::vector<nav_entry>::iterator it=my_nav_entrys.begin(); it!=my_nav_entrys.end(); it++)
        {
            std::string label(" ");
            std::string c = "<td class=\"nav\">";
            if ((*it).subpage_PTR.size() > i)
            {
                if ((*it).subpage_PTR[i] == (*it).m_selected)
                {
                    c = "<td class=\"nav_sel\">";
                    label = "<a href=\""
                          + (*it).subpage_PTR[i]->getHtmlFilename()
                          + "\" class=\"link_sel\">"
                          + (*it).subpage_PTR[i]->getLabel()
                          + "</a>"; 
                }
                else
                {
                    label = "<a href=\""
                          + (*it).subpage_PTR[i]->getHtmlFilename()
                          + "\" class=\"link_nav\">"
                          + (*it).subpage_PTR[i]->getLabel()
                          + "</a>"; 
                }
            }

            if (it != my_nav_entrys.begin())
            {
                if (((*it).selno >= 0) &&
                    ((*old).selno >= 0 &&
                    ((*old).selno >= (*it).selno) &&
                    ((int)i <= (*old).selno) &&
                    ((int)i >= (*it).selno)))
                        file << "<td class=\"nav_line\"> </td>";
                else
                if (((*it).selno >= 0) &&
                    ((*old).selno >= 0 &&
                    ((*old).selno <= (*it).selno) &&
                    ((int)i >= (*old).selno) &&
                    ((int)i <= (*it).selno)))
                        file << "<td class=\"nav_line\"> </td>";
                else
                    file << "<td class=\"nav_none\"> </td>";
            }

            file << c 
                 << label
                 << "</td>" << std::endl;
            
            old = it;
        }
        file << "</tr>" << std::endl;
    }
    file << "</table>" << std::endl;
    file << "</td>" << std::endl;
    file << "</tr>" << std::endl;
}
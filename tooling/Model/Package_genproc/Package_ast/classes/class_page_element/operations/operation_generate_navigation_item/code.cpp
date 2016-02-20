//~~ void generate_navigation_item(I_element* selected, std::ofstream& file) [page_element] ~~
file << "        <li class=\"" 
     << getType() 
     << "\"><a ";
if (selected == this)
    file <<  "class=\"active\" ";
file << "href=\"" 
     << getHtmlFilename() 
     << "\">"
     << getIdentifier()
     << "</a></li>"
     << std::endl;
//~~ void generate_navigation_item(std::ofstream& file) [page_element] ~~
file << "        <li class=\"" 
     << getType() 
     << "\"><a href=\"" 
     << getHtmlFilename() 
     << "\">"
     << getIdentifier()
     << "</a></li>"
     << std::endl;
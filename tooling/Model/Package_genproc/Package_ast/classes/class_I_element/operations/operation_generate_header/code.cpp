//~~ void generate_header(std::ofstream& file) [I_element] ~~
file << "<!DOCTYPE html>" << std::endl;
file << "<html lang=\"en\">" << std::endl;
file << "<head>" << std::endl;
file << "<title>Under Construction</title>" << std::endl;
file << "<link rel=\"stylesheet\" href=\"style.css\">" << std::endl;
file << "<META HTTP-EQUIV=\"Content-Type\" content=\"text/html; charset=utf-8\">" << std::endl;
file << "</head>" << std::endl;

file << "<body class=\"news\">" << std::endl;
file << "  <header>" << std::endl;

file << "  <div id=\"my_logo\"><img src=\"automotive_scrum_logo_small.png\"></div>" << std::endl;

generate_navigation_history(0,file);

file << "  </header>" << std::endl;

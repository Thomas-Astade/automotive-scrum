//~~ void generate_header(std::ofstream& file) [I_element] ~~
file << "<!DOCTYPE html>" << std::endl;
file << "<html lang=\"en\">" << std::endl;
file << "<head>" << std::endl;
file << "<title>" << getType() << " " << getLabel() << "</title>" << std::endl;
file << "<link rel=\"stylesheet\" href=\"style.css\">" << std::endl;
file << "<META HTTP-EQUIV=\"Content-Type\" content=\"text/html; charset=utf-8\">" << std::endl;
file << "</head>" << std::endl;
file << "<body>" << std::endl;
file << "<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"100%\">" << std::endl;

file << "<tr class=\"header\">" << std::endl;
file << "<td>" << std::endl;
file << "<table border=\"0\" cellpadding=\"0\" cellspacing=\"10\" width=\"100%\">" << std::endl;
file << "<tr>" << std::endl;
file << "<td>" << std::endl;
file << "<div><img src=\"automotive_scrum_logo_small.png\" alt=\"logo\"></div>" << std::endl;
file << "</td>" << std::endl;
file << "<td>" << std::endl;
file << "<p class=\"header\"> </p>" << std::endl;
file << "</td>" << std::endl;
file << "</tr>" << std::endl;
file << "</table>" << std::endl;
file << "</td>" << std::endl;
file << "</tr>" << std::endl;

nav_block t;
insert_nav(0,t);
t.generate(file);

file << "<tr class=\"body\">" << std::endl;
file << "<td>" << std::endl;
file << "<div class=\"body\">" << std::endl;

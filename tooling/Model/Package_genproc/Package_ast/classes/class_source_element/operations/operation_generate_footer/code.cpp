//~~ void generate_footer(const std::string& filename, std::ofstream& file) [source_element] ~~
file << "</div>" << std::endl;
file << "</td>" << std::endl;
file << "</tr>" << std::endl;
file << "<tr class=\"footer\">" << std::endl;
file << "<td class=\"footer\">" << std::endl;
file << "<p>Copyright (c) Thomas Spitzer<p>" << std::endl;

file << "</td>" << std::endl;
file << "</tr>" << std::endl;
file << "</table>" << std::endl;
file << "</body>" << std::endl;
file << "</html>" << std::endl;
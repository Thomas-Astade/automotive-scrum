//~~ void generate_footer(std::ofstream& file) [I_element] ~~
file << "</div>" << std::endl;
file << "</td>" << std::endl;
file << "</tr>" << std::endl;
file << "<tr class=\"footer\">" << std::endl;
file << "<td class=\"footer\">" << std::endl;
file << "<p>Copyright (c) Thomas Spitzer <script type=\"text/javascript\">"
     << "<!--"
     << "h='&#x61;&#x75;&#116;&#x6f;&#x6d;&#x6f;&#116;&#x69;&#118;&#x65;&#x2d;&#x73;&#x63;&#114;&#x75;&#x6d;&#46;&#x6f;&#114;&#x67;';a='&#64;';n='&#116;&#104;&#x6f;&#x6d;&#x61;&#x73;';e=n+a+h;"
     << "document.write('<a h'+'ref'+'=\"ma'+'ilto'+':'+e+'\">'+'<code>'+e+'</code>'+'<\\/'+'a'+'>');"
     << "// -->"
     << "</script><a href=\"mailto:thomas@automotive-scrum.org\"><code>thomas@automotive-scrum.org</code></a><noscript>&#116;&#104;&#x6f;&#x6d;&#x61;&#x73;&#32;&#x61;&#116;&#32;&#x61;&#x75;&#116;&#x6f;&#x6d;&#x6f;&#116;&#x69;&#118;&#x65;&#x2d;&#x73;&#x63;&#114;&#x75;&#x6d;&#32;&#100;&#x6f;&#116;&#32;&#x6f;&#114;&#x67;</noscript></p>";

file << "</td>" << std::endl;
file << "</tr>" << std::endl;
file << "</table>" << std::endl;
file << "</body>" << std::endl;
file << "</html>" << std::endl;
//~~ bool identifier_exists(const std::string& identifier) [I_element] ~~
std::string h;

for (std::vector<std::string>::iterator it = current_namespace.begin(); it != current_namespace.end(); it++)
    h += (*it) + "-";

h += identifier;

return ((object_list.find(h) != object_list.end()));

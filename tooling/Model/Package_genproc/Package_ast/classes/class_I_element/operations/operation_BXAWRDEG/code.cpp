//~~ ast::I_element* static_find_element(const std::string& identifier) [I_element] ~~
for (int i = current_namespace.size(); i >= 0; i--)
{
    std::map<std::string,I_element*>::iterator it = object_list.find(getCurrentPath(i)+identifier);
    if (it != object_list.end())
        return ((*it).second);
}

return 0;

//~~ ast::I_element* find_element(const std::string& identifier) [I_element] ~~
for (int i = getNamespaceLevel(); i >= 0; i--)
{
    std::map<std::string,I_element*>::iterator it = object_list.find(getFullPath(i)+identifier);
    if (it != object_list.end())
        return ((*it).second);
}

return 0;

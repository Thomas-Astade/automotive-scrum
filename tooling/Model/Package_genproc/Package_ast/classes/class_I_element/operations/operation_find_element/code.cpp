//~~ ast::I_element* find_element(const std::string& identifier) [I_element] ~~
std::map<std::string,I_element*>::iterator it = object_list.find(m_namespace+"_"+identifier);
if (it != object_list.end())
    return ((*it).second);
else
{
    std::map<std::string,I_element*>::iterator it = object_list.find(identifier);
    if (it != object_list.end())
        return ((*it).second);
    else
        return 0;
}
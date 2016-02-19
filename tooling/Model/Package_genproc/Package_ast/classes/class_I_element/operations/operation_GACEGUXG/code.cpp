//~~ I_element* find_element(const std::string& identifier) [I_element] ~~
if (object_list.find(identifier) != object_list.end())
    return object_list[identifier];
else
    return 0;
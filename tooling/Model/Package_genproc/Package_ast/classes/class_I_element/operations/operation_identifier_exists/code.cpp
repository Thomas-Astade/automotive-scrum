//~~ bool identifier_exists(const std::string& identifier) [I_element] ~~
if (object_list.find(current_namespace+"_"+identifier) != object_list.end())
    return true;
if (object_list.find(identifier) != object_list.end())
    return true;
    
return false;
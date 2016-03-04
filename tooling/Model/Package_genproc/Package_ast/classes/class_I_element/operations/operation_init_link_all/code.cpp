//~~ void init_link_all() [I_element] ~~
for (std::map<std::string,I_element*>::iterator it = object_list.begin(); it != object_list.end(); it++)
    (*it).second->init_links();
    
for (std::map<std::string,I_element*>::iterator it = object_list.begin(); it != object_list.end(); it++)
    (*it).second->init_implicite_members();

//~~ void generate_all(const std::string& outpath) [I_element] ~~
for (std::map<std::string,I_element*>::iterator it = object_list.begin(); it != object_list.end(); it++)
    (*it).second->generate(outpath);
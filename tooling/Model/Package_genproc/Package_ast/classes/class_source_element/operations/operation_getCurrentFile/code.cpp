//~~ std::string getCurrentFile() [source_element] ~~
if (loadStack.empty())
    return std::string();
    
return loadStack.back();
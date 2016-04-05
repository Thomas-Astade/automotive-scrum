//~~ std::string getHtmlFileName(const std::string& filename) [source_element] ~~
std::string ret = filename;

while (ret.find('/') != std::string::npos)
    ret[ret.find('/')] = '_';

return std::string("source_") + ret + ".html";
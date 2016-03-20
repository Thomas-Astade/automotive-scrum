//~~ std::string getCurrentPath(unsigned int level = 0xffff) [I_element] ~~
if (level > current_namespace.size())
    level = current_namespace.size();
    
std::string ret;

for (int i = current_namespace.size()-1; level > 0; i--, level--)
{
    ret = current_namespace[i] + "_" + ret;
}

return ret;
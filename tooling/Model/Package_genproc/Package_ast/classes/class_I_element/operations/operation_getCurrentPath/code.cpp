//~~ std::string getCurrentPath(unsigned int level = 0xffff) [I_element] ~~
if (level > current_namespace.size())
    level = current_namespace.size();
    
std::string ret;

for (unsigned int i = 0; i < level; i++)
{
    ret += current_namespace[i] + "_";
}

return ret;
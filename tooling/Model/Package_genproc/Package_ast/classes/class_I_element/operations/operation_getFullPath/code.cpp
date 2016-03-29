//~~ std::string getFullPath(unsigned int level = 0xffff) [I_element] ~~
if (level > getNamespaceLevel())
    level = getNamespaceLevel();

std::string ret;

for (unsigned int i = 0; i < level; i++)
{
    ret += m_namespace[i] + "_";
}

return ret;
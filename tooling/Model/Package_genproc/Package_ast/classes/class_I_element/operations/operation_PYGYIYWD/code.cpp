//~~ std::string getFullPath(unsigned int level = 0xffff) [I_element] ~~
if (level > getNamespaceLevel())
    level = getNamespaceLevel();
    
std::string ret;

for (int i = getNamespaceLevel()-1; level > 0; i--, level--)
{
    ret = m_namespace[i] + "_" + ret;
}

return ret;
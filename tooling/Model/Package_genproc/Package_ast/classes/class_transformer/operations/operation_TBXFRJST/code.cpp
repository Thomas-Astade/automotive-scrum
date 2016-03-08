//~~ void dump() [transformer] ~~
if (!m_create_IDs.empty())
{
    std::vector<std::string>::const_iterator it = m_create_IDs.begin();
    std::cout << "\tcreate " << (*it);
    it++;
    while(it != m_create_IDs.end())
    {
        std::cout << ",\n\t\t" << (*it);
        it++;
    }
    std::cout << ";\n";
}

if (!m_transform_IDs.empty())
{
    std::vector<std::string>::const_iterator it = m_transform_IDs.begin();
    std::cout << "\ttransform " << (*it);
    it++;
    while(it != m_transform_IDs.end())
    {
        std::cout << ",\n\t\t" << (*it);
        it++;
    }
    std::cout << ";\n";
}

for (std::vector<transition>::iterator it = m_transitions.begin(); it != m_transitions.end(); it++)
    (*it).dump();
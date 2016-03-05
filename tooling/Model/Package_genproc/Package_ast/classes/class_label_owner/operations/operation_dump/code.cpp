//~~ void dump() [label_owner] ~~
if (m_identifier != m_label)
    std::cout << "\tlabel \"" << m_label << "\";" << std::endl;
    
if (!m_brief.empty())
    std::cout << "\tbrief \"" << m_brief << "\";" << std::endl;

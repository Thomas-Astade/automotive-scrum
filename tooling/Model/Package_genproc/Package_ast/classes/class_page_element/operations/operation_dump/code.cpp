//~~ void dump() [page_element] ~~
std::cout << "page " << m_identifier << " {" << std::endl;
if (m_identifier != m_label)
    std::cout << "\tlabel \"" << m_label << "\";" << std::endl;
subpage_owner::dump();
dump_text();
std::cout << "}" << std::endl;

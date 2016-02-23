//~~ void dump() [page_element] ~~
std::cout << "page " << m_identifier << " {" << std::endl;
subpage_owner::dump();
dump_text();
std::cout << "}" << std::endl;

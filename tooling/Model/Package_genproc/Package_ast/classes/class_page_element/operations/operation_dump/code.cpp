//~~ void dump() [page_element] ~~
std::cout << "page " << m_identifier << " {" << std::endl;
dump_subpages();
std::cout << "}" << std::endl;

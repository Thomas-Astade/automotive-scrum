//~~ void dump() [page_element] ~~
std::cout << "page " << m_identifier << " {" << std::endl;
dump_subpages();
dump_text();
std::cout << "}" << std::endl;

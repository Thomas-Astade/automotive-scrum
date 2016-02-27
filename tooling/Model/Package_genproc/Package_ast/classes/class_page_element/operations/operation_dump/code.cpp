//~~ void dump() [page_element] ~~
std::cout << "page " << label_owner::getIdentifier() << " {" << std::endl;
label_owner::dump();
subpage_owner::dump();
dump_text();
std::cout << "}" << std::endl;

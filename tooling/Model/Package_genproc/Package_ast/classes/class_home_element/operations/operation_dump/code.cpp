//~~ void dump() [home_element] ~~
std::cout << "@home {" << std::endl;
subpage_owner::dump();
dump_text();
std::cout << "}" << std::endl;

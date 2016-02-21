//~~ void dump() [home_element] ~~
std::cout << "@home {" << std::endl;
dump_subpages();
dump_text();
std::cout << "}" << std::endl;

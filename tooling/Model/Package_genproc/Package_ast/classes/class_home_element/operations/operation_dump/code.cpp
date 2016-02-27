//~~ void dump() [home_element] ~~
std::cout << "@home {" << std::endl;
subpage_owner::dump();
text_owner::dump();
std::cout << "}" << std::endl;

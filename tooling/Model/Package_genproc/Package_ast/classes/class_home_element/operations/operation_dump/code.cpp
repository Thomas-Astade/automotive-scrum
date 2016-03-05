//~~ void dump() [home_element] ~~
std::cout << "\n@home {" << std::endl;
subpage_owner::dump("subpages");
text_owner::dump();
std::cout << "}" << std::endl;

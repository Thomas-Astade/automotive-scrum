//~~ void dump() [page_element] ~~
std::cout << "\npage " << getFullIdentifier() << " {" << std::endl;
label_owner::dump();
subpage_owner::dump("subpages");
text_owner::dump();
std::cout << "}" << std::endl;

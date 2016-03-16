//~~ void dump() [tool_element] ~~
std::cout << "\ntool " << getFullIdentifier() << " {" << std::endl;
label_owner::dump();
text_owner::dump();
std::cout << "}" << std::endl;

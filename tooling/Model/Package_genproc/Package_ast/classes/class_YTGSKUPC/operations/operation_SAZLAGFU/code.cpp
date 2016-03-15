//~~ void dump() [tool_element] ~~
std::cout << "\ntool " << label_owner::getIdentifier() << " {" << std::endl;
label_owner::dump();
text_owner::dump();
std::cout << "}" << std::endl;

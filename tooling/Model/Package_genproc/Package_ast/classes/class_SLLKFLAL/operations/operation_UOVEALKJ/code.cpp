//~~ void dump() [role_element] ~~
std::cout << "role " << label_owner::getIdentifier() << " {" << std::endl;
label_owner::dump();
text_owner::dump();
std::cout << "}" << std::endl;

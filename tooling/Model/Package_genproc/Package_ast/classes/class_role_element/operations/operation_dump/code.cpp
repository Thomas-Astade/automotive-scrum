//~~ void dump() [role_element] ~~
std::cout << "\nrole " << getFullIdentifier() << " {" << std::endl;
label_owner::dump();
text_owner::dump();
std::cout << "}" << std::endl;

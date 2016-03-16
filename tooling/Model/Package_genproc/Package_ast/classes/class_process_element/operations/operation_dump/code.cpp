//~~ void dump() [process_element] ~~
std::cout << "\nprocess " << getFullIdentifier() << " {" << std::endl;
label_owner::dump();
role_owner::dump();
subpage_owner::dump("subactivities");
text_owner::dump();
std::cout << "}" << std::endl;

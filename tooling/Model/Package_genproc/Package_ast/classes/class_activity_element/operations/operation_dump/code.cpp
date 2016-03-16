//~~ void dump() [activity_element] ~~
std::cout << "\nactivity " << getFullIdentifier() << " {" << std::endl;
label_owner::dump();
role_owner::dump();
transformer::dump();
subpage_owner::dump("subactivities");
text_owner::dump();
std::cout << "}" << std::endl;

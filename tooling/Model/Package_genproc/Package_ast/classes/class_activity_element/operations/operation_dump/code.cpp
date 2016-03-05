//~~ void dump() [activity_element] ~~
std::cout << "\nactivity " << label_owner::getIdentifier() << " {" << std::endl;
label_owner::dump();
role_owner::dump();
subpage_owner::dump("subactivities");
text_owner::dump();
std::cout << "}" << std::endl;

//~~ void dump() [activity_element] ~~
std::cout << "\nactivity " << label_owner::getIdentifier() << " {" << std::endl;
label_owner::dump();
role_owner::dump();
transformer::dump();
subpage_owner::dump("subactivities");
text_owner::dump();
std::cout << "}" << std::endl;

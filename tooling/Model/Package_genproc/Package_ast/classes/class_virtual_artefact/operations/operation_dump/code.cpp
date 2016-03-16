//~~ void dump() [virtual_artefact] ~~
std::cout << "\nvirtual artefact " << getFullIdentifier() << " {" << std::endl;
label_owner::dump();
std::cout << "}" << std::endl;

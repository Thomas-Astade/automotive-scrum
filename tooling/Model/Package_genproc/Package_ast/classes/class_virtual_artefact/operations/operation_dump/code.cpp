//~~ void dump() [virtual_artefact] ~~
std::cout << "\nvirtual artefact " << label_owner::getIdentifier() << " {" << std::endl;
label_owner::dump();
std::cout << "}" << std::endl;

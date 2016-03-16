//~~ void dump() [artefact_base] ~~
std::cout << "\nartefact " << getFullIdentifier() << " {" << std::endl;
label_owner::dump();
subpage_owner::dump("subpages");
text_owner::dump();
std::cout << "}" << std::endl;

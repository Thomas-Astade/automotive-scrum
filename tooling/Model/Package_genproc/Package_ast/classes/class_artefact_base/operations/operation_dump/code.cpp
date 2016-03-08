//~~ void dump() [artefact_base] ~~
std::cout << "\nartefact " << label_owner::getIdentifier() << " {" << std::endl;
label_owner::dump();
subpage_owner::dump("subpages");
text_owner::dump();
std::cout << "}" << std::endl;

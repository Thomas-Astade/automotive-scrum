//~~ void insertObject() [I_element] ~~
std::cout << "enter insertObject" << std::endl;
std::cout << getFullPath()+getIdentifier() << "...";
object_list[getFullPath()+getIdentifier()] = this;
std::cout << "done" << std::endl;
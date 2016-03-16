//~~ void warn_dublicate_parent(I_element* newParent) [parent_owner] ~~
const I_element* me = dynamic_cast<const I_element*>(this);
std::cerr   << "Warning: you try to set "
            << newParent->getFullIdentifier()
            << " as parent of "
            << me->getFullIdentifier()
            << " which has already "
            << my_parent->getFullIdentifier()
            << " as parent. So it is ignored."
            << std::endl;

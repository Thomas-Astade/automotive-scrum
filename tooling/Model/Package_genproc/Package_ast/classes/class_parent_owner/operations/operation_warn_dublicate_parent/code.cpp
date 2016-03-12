//~~ void warn_dublicate_parent(I_element* newParent) [parent_owner] ~~
const I_element* me = dynamic_cast<const I_element*>(this);
std::cerr   << "Warning: you try to set "
            << newParent->getFullPath()
            << newParent->getIdentifier()
            << " as parent of "
            << me->getFullPath()
            << me->getIdentifier()
            << " which has already "
            << my_parent->getFullPath()
            << my_parent->getIdentifier()
            << " as parent. So it is ignored."
            << std::endl;

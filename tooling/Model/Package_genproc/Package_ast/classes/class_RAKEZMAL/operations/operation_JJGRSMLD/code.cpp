//~~ void warn_dublicate_parent(I_element* newParent) [parent_owner] ~~
std::cerr   << "Warning: you try to set "
            << newParent->getIdentifier()
            << " as parent of "
            << me->getIdentifier()
            << " which has already "
            << my_parent->getIdentifier()
            << " as parent. So it is ignored."
            << std::endl;

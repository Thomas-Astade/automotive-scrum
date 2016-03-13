//~~ void warn_not_allowed(const I_element* other, const std::string& reason) [transformer] ~~
const I_element* me = dynamic_cast<const I_element*>(this);
std::cerr   << "Warning: you try to add \""
            << other->getIdentifier() 
            << "\" (which is a "
            << other->getType()
            << ") as "
            << reason
            << " of \""
            << me->getIdentifier()
            << "\" (which is a "
            << me->getType()
            << ") but this is not allowed and ignored."
            << std::endl;

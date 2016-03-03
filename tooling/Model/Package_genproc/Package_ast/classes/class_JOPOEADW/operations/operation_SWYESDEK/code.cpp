//~~ void warn_not_found(const std::string& reason, const std::string& identifier) [role_owner] ~~
const I_element* me = dynamic_cast<const I_element*>(this);
std::cerr   << "Warning: you try to add \""
            << identifier
            << "\" as "
            << reason
            << " in \""
            << me->getIdentifier()
            << "\" but it does not exist and is ignored."
            << std::endl;

//~~ void warn_no_parent() [parent_owner] ~~
if (my_parent == 0)
{
    const I_element* me = dynamic_cast<const I_element*>(this);
    std::cerr   << "Warning: The element "
                << me->getFullIdentifier()
                << " has no parent specified."
                << std::endl;
}
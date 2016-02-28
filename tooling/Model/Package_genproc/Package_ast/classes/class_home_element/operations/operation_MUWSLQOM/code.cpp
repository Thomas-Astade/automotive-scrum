//~~ bool allow_child(const I_element* child) [home_element] ~~
if (dynamic_cast<const page_element*>(child))
    return true;

if (dynamic_cast<const process_element*>(child))
    return true;

return false;
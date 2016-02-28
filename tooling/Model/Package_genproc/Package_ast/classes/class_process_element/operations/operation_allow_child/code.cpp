//~~ bool allow_child(const I_element* child) [process_element] ~~
if (dynamic_cast<const activity_element*>(child))
    return true;

return false;
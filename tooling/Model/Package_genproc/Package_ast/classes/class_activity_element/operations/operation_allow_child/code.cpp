//~~ bool allow_child(const I_element* child) [activity_element] ~~
if (dynamic_cast<const activity_element*>(child))
    return true;

return false;
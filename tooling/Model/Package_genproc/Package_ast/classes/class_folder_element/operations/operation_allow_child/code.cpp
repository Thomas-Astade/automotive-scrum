//~~ bool allow_child(const I_element* child) [folder_element] ~~
if (dynamic_cast<const artefact_element*>(child))
    return true;

if (dynamic_cast<const folder_element*>(child))
    return true;

return false;
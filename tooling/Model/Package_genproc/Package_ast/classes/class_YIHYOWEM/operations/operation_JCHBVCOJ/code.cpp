//~~ bool allow_child(const I_element* child) [artefact_element] ~~
if (dynamic_cast<const artefact_element*>(child))
    return true;

return false;
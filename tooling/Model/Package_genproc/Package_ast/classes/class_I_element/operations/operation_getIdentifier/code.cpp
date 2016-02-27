//~~ std::string getIdentifier() [I_element] ~~
const label_owner* l = dynamic_cast<const label_owner*>(this);
if (l)
    return l->getIdentifier();
else
    throw(std::string("object should inherit from label_owner or overload this function!"));
//~~ std::string getLabel() [I_element] ~~
const label_owner* l = dynamic_cast<const label_owner*>(this);
if (l)
    return l->getLabel();
else
    return getIdentifier();
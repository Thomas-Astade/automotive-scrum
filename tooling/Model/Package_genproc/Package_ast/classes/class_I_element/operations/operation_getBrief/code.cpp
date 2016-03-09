//~~ std::string getBrief() [I_element] ~~
const label_owner* l = dynamic_cast<const label_owner*>(this);
if (l)
    return l->getBrief();
else
    return " ";
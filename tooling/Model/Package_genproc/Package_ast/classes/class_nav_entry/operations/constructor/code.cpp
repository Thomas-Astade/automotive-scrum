//~~ nav_entry(I_element* selected, std::vector<I_element*> childs) [nav_entry] ~~
for (unsigned int i = 0; i < childs.size(); i++)
    if (childs[i] == selected)
        selno = i;
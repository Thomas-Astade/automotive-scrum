//~~ void generate_navigation_items(I_element* selected, std::ofstream& file) [home_element] ~~
for (std::vector<I_element*>::const_iterator it = subpage_PTR.begin(); it != subpage_PTR.end(); it++)
    (*it)->generate_navigation_item(selected,file);
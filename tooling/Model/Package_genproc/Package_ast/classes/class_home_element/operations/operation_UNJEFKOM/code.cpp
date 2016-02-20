//~~ void generate_navigation_items(std::ofstream& file) [home_element] ~~
for (std::vector<I_element*>::iterator it = subpage_PTR.begin(); it != subpage_PTR.end(); it++)
    (*it)->generate_navigation_item(file);
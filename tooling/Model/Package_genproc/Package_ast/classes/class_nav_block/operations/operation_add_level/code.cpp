//~~ void add_level(I_element* selected, std::vector<I_element*> childs) [nav_block] ~~
if (linecount == 0)
    linecount = 1;
    
if (childs.size() > linecount)
    linecount = childs.size();
    
my_nav_entrys.push_back(nav_entry(selected,childs));
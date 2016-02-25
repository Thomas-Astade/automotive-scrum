//~~ void add_level(I_element* const selected, std::vector<I_element*> childs) [nav_block] ~~
if (linecount == 0)
    linecount = 1;
    
if (childs.size() > linecount)
    linecount = childs.size();
    

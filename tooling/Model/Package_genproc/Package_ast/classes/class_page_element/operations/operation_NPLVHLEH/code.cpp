//~~ void init_subpage_ptr() [page_element] ~~
for (std::vector<std::string>::iterator it = subpage_IDs.begin(); it != subpage_IDs.end(); it++)
{
    ast::I_element* element = ast::I_element::find_element(*it);

    if (element != 0)
        subpage_PTR.push_back(element);
    else 
        warn_not_found("subpage",*it);
}

for (std::vector<I_element*>::iterator it = subpage_PTR.begin(); it != subpage_PTR.end(); it++)
    (*it)->do_parent_link(this);

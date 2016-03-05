//~~ void init_links() [subpage_owner] ~~
const I_element* me = dynamic_cast<const I_element*>(this);
for (std::vector<std::string>::iterator it = subpage_IDs.begin(); it != subpage_IDs.end(); it++)
{
    ast::I_element* element = ast::I_element::find_element(*it);

    if (element == 0)
        warn_not_found("subpage",*it);
    else if (!me->allow_child(element))
        warn_not_allowed(element, "child");
    else
        subpage_PTR.push_back(element);
}

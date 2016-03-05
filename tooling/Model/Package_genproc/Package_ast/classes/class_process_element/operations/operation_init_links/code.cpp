//~~ void init_links() [process_element] ~~
subpage_owner::init_links();
role_owner::init_links();
const std::vector<I_element*>& s = getSubpages();
for (std::vector<I_element*>::const_iterator it = s.begin(); it != s.end(); it++)
{
    parent_owner* p = dynamic_cast<parent_owner*>(*it);
    if (p)
        p->init_link(this);
}

for (std::vector<std::string>::iterator it = repository_IDs.begin(); it != repository_IDs.end(); it++)
{
    I_element* element = I_element::find_element(*it);
    repository_element* r = dynamic_cast<repository_element*>(element);
    
    if (element == 0)
        subpage_owner::warn_not_found("repository",*it);
    else if (r == 0)
        subpage_owner::warn_not_allowed(element, "repository");
    else
    {
        repository_PTR.push_back(r);
        r->parent_owner::init_link(this);
    }
}

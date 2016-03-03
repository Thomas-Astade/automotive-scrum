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
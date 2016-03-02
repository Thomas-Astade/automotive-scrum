//~~ void init_links() [activity_element] ~~
subpage_owner::init_links();
const std::vector<I_element*>& s = getSubpages();
for (std::vector<I_element*>::const_iterator it = s.begin(); it != s.end(); it++)
{
    process_member* P = dynamic_cast<process_member*>(*it);
    if (P)
        P->setProcess(getProcess());
    parent_owner* p = dynamic_cast<parent_owner*>(*it);
    if (p)
        p->init_link(this);
}
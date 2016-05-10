//~~ void init_links() [activity_element] ~~
const I_element* me = dynamic_cast<const I_element*>(this);
subpage_owner::init_links();
role_owner::init_links();
transformer::init_links();

const std::vector<I_element*>& s = getSubpages();
for (std::vector<I_element*>::const_iterator it = s.begin(); it != s.end(); it++)
{
    parent_owner* p = dynamic_cast<parent_owner*>(*it);
    if (p)
        p->init_link(this);
}

for (std::vector<std::string>::iterator it = m_specialize_IDs.begin(); it != m_specialize_IDs.end(); it++)
{
    ast::I_element* element = me->find_element(*it);

    if (element == 0)
        transformer::warn_not_found("specialize",*it);
    else
    {
        activity_element* a = dynamic_cast<activity_element*>(element);
        if (a == 0)
            transformer::warn_not_allowed(element, "specialize target");
        else
        {
            m_specializes.insert(a);
            a->addSpecialized(this);
        }
    }
}

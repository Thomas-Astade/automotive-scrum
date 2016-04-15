//~~ void init_links() [artefact_base] ~~
subpage_owner::init_links();
const std::vector<I_element*>& s = getSubpages();
for (std::vector<I_element*>::const_iterator it = s.begin(); it != s.end(); it++)
{
    parent_owner* p = dynamic_cast<parent_owner*>(*it);
    if (p)
        p->init_link(this);
}

for (std::vector<std::string>::iterator it = relation_IDs.begin(); it != relation_IDs.end(); it++)
{
    ast::I_element* element = find_element(*it);
    artefact_base* a = dynamic_cast<artefact_base*>(element);

    if (element == 0)
        warn_not_found("relation",*it);
    else if (a == 0)
        warn_not_allowed(element, "relation");
    else
    {
        addRelation(element);
        a->addRelated(this);
    }
}

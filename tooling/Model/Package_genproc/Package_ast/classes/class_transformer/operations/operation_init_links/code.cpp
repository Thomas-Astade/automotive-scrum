//~~ void init_links() [transformer] ~~
const I_element* me = dynamic_cast<const I_element*>(this);
for (std::vector<std::string>::iterator it = m_create_IDs.begin(); it != m_create_IDs.end(); it++)
{
    ast::I_element* element = me->find_element(*it);

    if (element == 0)
        warn_not_found("create",*it);
    else
    {
        artefact_base* a = dynamic_cast<artefact_base*>(element);
        if (a == 0)
            warn_not_allowed(element, "create target");
        else
        {
            m_create.push_back(a);
            a->addCreator(dynamic_cast<I_element*>(this));
        }
    }
}

for (std::vector<std::string>::iterator it = m_transform_IDs.begin(); it != m_transform_IDs.end(); it++)
{
    ast::I_element* element = me->find_element(*it);

    if (element == 0)
        warn_not_found("transform",*it);
    else
    {
        artefact_base* a = dynamic_cast<artefact_base*>(element);
        if (a == 0)
            warn_not_allowed(element, "transform target");
        else
        {
            m_transform.push_back(a);
            a->addUser(dynamic_cast<I_element*>(this));
        }
    }
}

// artefact dependency

for (std::vector<artefact_base*>::iterator it_create = m_create.begin(); it_create != m_create.end(); it_create++)
{
    for (std::vector<artefact_base*>::iterator it_trans = m_transform.begin(); it_trans != m_transform.end(); it_trans++)
    {
        (*it_create)->add_needed(dynamic_cast<const I_element*>(*it_trans));
        (*it_trans)->add_dependency(dynamic_cast<const I_element*>(*it_create));
    }
}

for (std::vector<transition>::iterator it = m_transitions.begin(); it != m_transitions.end(); it++)
{
    ast::I_element* element = me->find_element((*it).getID());

    if (element == 0)
        warn_not_found("transition",(*it).getID());
    else
    {
        artefact_base* a = dynamic_cast<artefact_base*>(element);
        if (a == 0)
            warn_not_allowed(element, "state transition");
        else
        {
            (*it).setElement(element);
            a->addTransition(dynamic_cast<I_element*>(this),
                (*it).getSource(),(*it).getDestination(),(*it).getGuard());
        }
    }
}

for (std::vector<artefact_base*>::iterator it_create = m_create.begin(); it_create != m_create.end(); it_create++)
{
    for (std::vector<transition>::iterator it = m_transitions.begin(); it != m_transitions.end(); it++)
    if ((*it).getElement())
    {
        (*it_create)->add_needed((*it).getElement());
        dynamic_cast<artefact_base*>((*it).getElement())->add_dependency(dynamic_cast<const I_element*>(*it_create));
    }
}


for (std::vector<artefact_base*>::iterator it_trans = m_transform.begin(); it_trans != m_transform.end(); it_trans++)
{
    for (std::vector<transition>::iterator it = m_transitions.begin(); it != m_transitions.end(); it++)
    if ((*it).getElement())
    {
        dynamic_cast<artefact_base*>((*it).getElement())->>add_needed(dynamic_cast<const I_element*>(*it_trans));
        (*it_trans)->add_dependency((*it).getElement());

    }
}


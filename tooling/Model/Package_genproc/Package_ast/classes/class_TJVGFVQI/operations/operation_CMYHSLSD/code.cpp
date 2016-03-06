//~~ void init_links() [transformer] ~~
for (std::vector<std::string>::iterator it = m_create_IDs.begin(); it != m_create_IDs.end(); it++)
{
    ast::I_element* element = ast::I_element::find_element(*it);

    if (element == 0)
        warn_not_found("create",*it);
    else
    {
        artefact_base* a = dynamic_cast<artefact_base*>(element);
        if (a == 0)
            warn_not_allowed(element, "create target");
        else
            m_create.push_back(a);
    }
}

for (std::vector<std::string>::iterator it = m_transform_IDs.begin(); it != m_transform_IDs.end(); it++)
{
    ast::I_element* element = ast::I_element::find_element(*it);

    if (element == 0)
        warn_not_found("transform",*it);
    else
    {
        artefact_base* a = dynamic_cast<artefact_base*>(element);
        if (a == 0)
            warn_not_allowed(element, "transform target");
        else
            m_transform.push_back(a);
    }
}

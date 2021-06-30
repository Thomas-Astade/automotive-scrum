//~~ void init_links() [role_owner] ~~
if (!roleID.empty())
{
    const I_element* e = dynamic_cast<const I_element*>(this);

    ast::I_element* element = e->find_element(roleID);

    if (element == 0)
        warn_not_found("role",roleID);
    else
        my_role = element;
}

if (!toolID.empty())
{
    const I_element* e = dynamic_cast<const I_element*>(this);

    ast::I_element* element = e->find_element(toolID);

    if (element == 0)
        warn_not_found("tool",roleID);
    else
        my_tool = element;
}

for (auto it : my_participantIDs)
{
    const I_element* e = dynamic_cast<const I_element*>(this);

    ast::I_element* element = e->find_element(it);

    if (element == 0)
        warn_not_found("participant",it);
    else
        my_participants.insert(element);
}
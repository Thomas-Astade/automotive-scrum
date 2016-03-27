//~~ void init_implicite_members() [activity_element] ~~
bool isDirect;
role_element* r = dynamic_cast<role_element*>(getRole(&isDirect));

if (r != 0)
{
    r->add_activity(this,isDirect);

    if (isDirect)
    {
        process_element* p = dynamic_cast<process_element*>(getProcess());

        if (p != 0)
            p->addImpliciteRole(r);
    }
}

tool_element* t = dynamic_cast<tool_element*>(getTool(&isDirect));

if (t != 0)
{
    t->add_activity(this,isDirect);

    if (isDirect)
    {
        process_element* p = dynamic_cast<process_element*>(getProcess());

        if (p != 0)
            p->addImpliciteTool(t);
    }
}

warn_no_parent();
//~~ void init_implicite_members() [activity_element] ~~
bool isDirect;
role_element* r = dynamic_cast<role_element*>(getRole(&isDirect));

if (r == 0)
    return;

r->add_activity(this,isDirect);

if (isDirect)
{
    process_element* p = dynamic_cast<process_element*>(getProcess());

    if (p != 0)
        p->addImpliciteRole(r);
}
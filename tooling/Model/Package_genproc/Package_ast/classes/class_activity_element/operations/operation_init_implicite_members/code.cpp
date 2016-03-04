//~~ void init_implicite_members() [activity_element] ~~
if (hasExplicitRole())
{
    role_element* r = dynamic_cast<role_element*>(getRole());
    if (r == 0)
        return;
    
    process_element* p = dynamic_cast<process_element*>(getProcess());
    
    if (p != 0)
        p->addImpliciteRole(r);
}
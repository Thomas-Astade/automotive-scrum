//~~ void addImpliciteRole(role_element* role) [process_element] ~~
if ((role != getRole()) &&
     (implicite_roles.find(role) == implicite_roles.end())
    )
{
    implicite_roles.insert(role);
    add_subpage(role);
    role->init_link(this);
}
//~~ void init_links() [role_owner] ~~
if (roleID.empty())
    return;

ast::I_element* element = ast::I_element::find_element(roleID);

if (element == 0)
    warn_not_found("role",roleID);
else
    my_role = element;
//~~ ast::I_element* getRole(bool* IsDirectChild = 0) [role_owner] ~~
if (IsDirectChild)
    *IsDirectChild = my_role != 0;

if (my_role != 0)
    return my_role;
    
const parent_owner* p = dynamic_cast<const parent_owner*>(this);
if (p == 0)
    return 0;
    
const role_owner* r = dynamic_cast<const role_owner*>(p->getParent());

if (r)
    return r->getRole();
else
    return 0;
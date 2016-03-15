//~~ ast::I_element* getTool(bool* IsDirectChild = 0) [role_owner] ~~
if (IsDirectChild)
    *IsDirectChild = my_tool != 0;

if (my_tool != 0)
    return my_tool;
    
const parent_owner* p = dynamic_cast<const parent_owner*>(this);
if (p == 0)
    return 0;
    
const role_owner* r = dynamic_cast<const role_owner*>(p->getParent());

if (r)
    return r->getTool();
else
    return 0;
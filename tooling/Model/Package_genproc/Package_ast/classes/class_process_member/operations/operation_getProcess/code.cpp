//~~ ast::I_element* getProcess(bool* IsDirectChild = 0) [process_member] ~~
const parent_owner* p = dynamic_cast<const parent_owner*>(this);
const I_element* e = 0;

if (p)
    e = p->getParent();

const process_element* pr = dynamic_cast<const process_element*>(e);

if (IsDirectChild)
{
    *IsDirectChild = pr != 0;
}

if (pr != 0) // parent is a process
    return p->getParent();

if (e == 0) // no parent
    return 0;

const process_member* pe = dynamic_cast<const process_member*>(e);

return pe->getProcess();
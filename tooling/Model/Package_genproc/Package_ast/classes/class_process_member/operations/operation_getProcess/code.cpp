//~~ ast::I_element* getProcess(bool* IsDirectChild = 0) [process_member] ~~
const parent_owner* p = dynamic_cast<const parent_owner*>(this);
I_element* e = 0;

if (p)
    e = p->getParent();

if (e == 0) // no parent
    return 0;

process_element* pr = dynamic_cast<process_element*>(e);

if (IsDirectChild)
{
    *IsDirectChild = pr != 0;
}

if (pr != 0) // parent is a process
    return pr;

const process_member* pe = dynamic_cast<const process_member*>(e);

if (pe == 0)
    return 0;

return pe->getProcess();
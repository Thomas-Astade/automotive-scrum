//~~ ast::I_element* getRepository(bool* IsDirectChild = 0) [artefact_base] ~~
const parent_owner* p = dynamic_cast<const parent_owner*>(this);
const I_element* e = 0;

if (p)
    e = p->getParent();

const repository_element* r = dynamic_cast<const repository_element*>(e);

if (IsDirectChild)
{
    *IsDirectChild = r != 0;
}

if (r != 0) 
    return p->getParent();

if (e == 0) 
    return 0;

const artefact_base* ab = dynamic_cast<const artefact_base*>(e);

return ab->getRepository();
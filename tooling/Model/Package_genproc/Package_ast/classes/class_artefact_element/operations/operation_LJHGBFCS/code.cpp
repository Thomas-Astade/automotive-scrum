//~~ std::string getPath() [artefact_element] ~~
std::string ret;

const artefact_element* a = this;
const I_element* e = this;
const repository_element* r = 0;
const folder_element* f = 0;

do {
    if (a)
        e = a->getParent();
    else if (f)
        e = f->getParent();
    else if (r)
        e = r->getParent();
        
    a = dynamic_cast<const artefact_element*>(e);
    r = dynamic_cast<const repository_element*>(e);
    f = dynamic_cast<const folder_element*>(e);
    
    if (e)
    {
        if (ret.empty())
            ret =  e->getLabel();
        else
            ret =  e->getLabel() + "/" + ret;
    }
        
} while (e && (r == 0));

return ret;
//~~ void init_implicite_members() [process_element] ~~
role_element* r = dynamic_cast<role_element*>(getRole());
if (r)
{
    r->init_link(this);
}

//~~ void do_parent_link(I_element* parent) [parent_owner] ~~
if (my_parent != 0)
{
    warn_dublicate_parent(parent);
    return;
}
my_parent = parent;
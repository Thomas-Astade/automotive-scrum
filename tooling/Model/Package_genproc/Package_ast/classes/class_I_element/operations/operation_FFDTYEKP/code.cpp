//~~ void do_parent_link(I_element* parent) [I_element] ~~
if (my_parent != 0)
{
    warn_dublicate_parent(parent);
    return;
}
my_parent = parent;
init_subpage_ptr();
//~~ void init_link(I_element* parent, int depth) [parent_owner] ~~
if (my_parent != 0)
{
    warn_dublicate_parent(parent);
    return;
}
my_parent = parent;

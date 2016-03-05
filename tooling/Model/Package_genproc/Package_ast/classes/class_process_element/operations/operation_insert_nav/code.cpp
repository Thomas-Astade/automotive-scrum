//~~ void insert_nav(I_element* selected, nav_block& block) [process_element] ~~
role_element* ro = dynamic_cast<role_element*>(selected);
repository_element* re = dynamic_cast<repository_element*>(selected);

if ((ro==0) && (re==0))
{
    I_element::insert_nav(selected,block);
    return;
}

getParent()->insert_nav(this,block);

if (ro != 0)
{
    std::vector<ast::I_element*> h;
    h.push_back(getRole());

    for (std::set<role_element*>::iterator it = implicite_roles.begin(); it != implicite_roles.end(); it++)
        h.push_back(*it);

    block.add_level(selected,h);
}
else
{
    std::vector<ast::I_element*> h;

    for (std::vector<repository_element*>::iterator it = repository_PTR.begin(); it != repository_PTR.end(); it++)
        h.push_back(*it);

    block.add_level(selected,h);
}
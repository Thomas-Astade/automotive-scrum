//~~ void insert_nav(I_element* selected, nav_block& block) [process_element] ~~
role_element* r = dynamic_cast<role_element*>(selected);

if (r==0)
{
    I_element::insert_nav(selected,block);
    return;
}

getParent()->insert_nav(this,block);

std::vector<ast::I_element*> h;
h.push_back(getRole());

for (std::set<role_element*>::iterator it = implicite_roles.begin(); it != implicite_roles.end(); it++)
    h.push_back(*it);

block.add_level(selected,h);

//~~ void insert_nav(nav_block& block) [I_element] ~~
subpage_owner* s = dynamic_cast<subpage_owner*>(this);
parent_owner* p = dynamic_cast<parent_owner*>(this);

if (p)
    p->getParent()->insert_nav(block);

if (s)
    block.add_level(this,s->getSubpages());
else
    block.add_level(this,std::vector<ast::I_element*>());
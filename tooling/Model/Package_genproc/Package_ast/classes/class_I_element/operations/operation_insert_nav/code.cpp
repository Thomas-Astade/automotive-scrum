//~~ void insert_nav(I_element* selected, nav_block& block) [I_element] ~~
subpage_owner* s = dynamic_cast<subpage_owner*>(this);
parent_owner* p = dynamic_cast<parent_owner*>(this);

if (p)
    p->getParent()->insert_nav(this,block);
else
    {
        std::vector<ast::I_element*> h;
        h.push_back(this);
        block.add_level(this,h);
    }

if (s && !s->getSubpages().empty())
    block.add_level(selected,s->getSubpages());

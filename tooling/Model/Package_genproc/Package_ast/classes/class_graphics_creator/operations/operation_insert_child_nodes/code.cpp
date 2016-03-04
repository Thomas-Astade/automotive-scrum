//~~ void insert_child_nodes(FILE* gfile) [graphics_creator] ~~
const subpage_owner* p = dynamic_cast<const subpage_owner*>(this);
const I_element* e =  dynamic_cast<const I_element*>(this);

if (!p)
    return;
    
const std::vector<ast::I_element*>& c = p->getSubpages();

for (std::vector<ast::I_element*>::const_iterator it = c.begin(); it != c.end(); it++)
{
    if (dynamic_cast<role_element*>(*it) == 0)
    {
        fputs((*it)->get_graph_node(false).c_str(),gfile);
        std::string connection;
        connection = e->getIdentifier()
                   + " -> "
                   + (*it)->getIdentifier()
                   + "[arrowhead=\"none\", arrowtail=\"diamond\", dir=\"both\", color=\"#072551\"];";
        fputs(connection.c_str(),gfile);
    }
}
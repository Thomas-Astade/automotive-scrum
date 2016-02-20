//~~ void do_parent_link() [generator] ~~
ast::I_element* home = ast::I_element::find_element("@home");
if (home == 0)
    throw(std::string("cannot find @home"));

home->do_parent_link(0);
//~~ void generate_navigation_history(I_element* selected, std::ofstream& file) [I_element] ~~
if (my_parent)
    my_parent->generate_navigation_history(this,file);

generate_navigation_bar(selected,file);

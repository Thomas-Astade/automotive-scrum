//~~ void generate_navigation_bar(I_element* selected, std::ofstream& file) [I_element] ~~
if (!hasSubpages())
    return;
    
file << "    <div class=\"nav\">" << std::endl;
file << "      <ul>" << std::endl;
generate_navigation_items(selected,file); 
file << "      </ul>" << std::endl;
file << "    </div>" << std::endl;


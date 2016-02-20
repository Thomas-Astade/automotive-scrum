//~~ void generate_navigation_bar(std::ofstream& file) [I_element] ~~
if (!hasSubpages())
    return;
    
file << "    <div class=\"nav\">" << std::endl;
file << "      <ul>" << std::endl;
generate_navigation_items(file); 
file << "      </ul>" << std::endl;
file << "    </div>" << std::endl;


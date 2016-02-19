//~~ void dump_childs() [I_element] ~~
if (childs.empty())
    return;
std::vector<std::string>::iterator it = childs.begin();
std::cout << "\tchilds " << (*it);
it++;
while(it != childs.end())
{
    std::cout << ",\n\t" << (*it);
    it++;
}
std::cout << ";\n";
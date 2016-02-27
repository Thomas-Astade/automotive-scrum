//~~ void dump() [subpage_owner] ~~
if (subpage_IDs.empty())
    return;
std::vector<std::string>::const_iterator it = subpage_IDs.begin();
std::cout << "\tsubpages " << (*it);
it++;
while(it != subpage_IDs.end())
{
    std::cout << ",\n\t" << (*it);
    it++;
}
std::cout << ";\n";
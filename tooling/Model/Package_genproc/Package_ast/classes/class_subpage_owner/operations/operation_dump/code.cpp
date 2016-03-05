//~~ void dump(const std::string& keyword) [subpage_owner] ~~
if (subpage_IDs.empty())
    return;
std::vector<std::string>::const_iterator it = subpage_IDs.begin();
std::cout << "\t" << keyword << " " << (*it);
it++;
while(it != subpage_IDs.end())
{
    std::cout << ",\n\t\t" << (*it);
    it++;
}
std::cout << ";\n";
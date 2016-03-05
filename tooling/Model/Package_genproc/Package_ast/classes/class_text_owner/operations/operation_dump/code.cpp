//~~ void dump() [text_owner] ~~
if (textfiles.empty())
    return;
std::vector<std::string>::const_iterator it = textfiles.begin();
std::cout << "\ttext " << (*it);
it++;
while(it != textfiles.end())
{
    std::cout << ",\n\t\t" << (*it);
    it++;
}
std::cout << ";\n";
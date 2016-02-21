//~~ void dump_text() [page_element] ~~
if (textfiles.empty())
    return;
std::vector<std::string>::iterator it = textfiles.begin();
std::cout << "\ttext " << (*it);
it++;
while(it != textfiles.end())
{
    std::cout << ",\n\t" << (*it);
    it++;
}
std::cout << ";\n";
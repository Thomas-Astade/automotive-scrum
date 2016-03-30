//~~ void dump_parameters(const char* prefix) [parameters] ~~

std::cout << prefix;

for (std::vector<std::string>::iterator it = currentParameters.begin(); it != currentParameters.end(); it++)
{
    std::cout << (*it) << ", ";
}

std::cout << std::endl;
//~~ void generate_body(const std::string& filename, std::ofstream& file, const std::string& outpath) [source_element] ~~
FILE *in;
char buff[512];

std::string command("pandoc ");

command += "md/example_begin.md ";
command += filename;
command += " md/example_end.md";


if(!(in = popen(command.c_str(), "r")))
    throw(command);

while(fgets(buff, sizeof(buff), in)!=NULL)
{
    file << buff;
}

pclose(in);
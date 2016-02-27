//~~ void generate(std::ofstream& file) [text_owner] ~~
FILE *in;
char buff[512];

std::string command("pandoc ");

for (std::vector<std::string>::const_iterator it = textfiles.begin();
     it != textfiles.end(); it++)
     command += (*it) + " ";

if(!(in = popen(command.c_str(), "r")))
    throw(command);

while(fgets(buff, sizeof(buff), in)!=NULL)
{
    file << buff;
}

pclose(in);
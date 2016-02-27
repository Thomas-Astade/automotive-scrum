//~~ void insert_file(std::ofstream& file, const std::string& sourcename) [graphics_creator] ~~
FILE * pFile;
char buff[512];

if(!(pFile = fopen (sourcename.c_str(),"r")))
    throw(sourcename);

while(fgets(buff, sizeof(buff), pFile)!=NULL)
{
    file << buff;
}

fclose(pFile);
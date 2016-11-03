//~~ void insert_file(std::ofstream& file, const std::string& sourcename) [graphics_creator] ~~
FILE * pFile;
char buff[512];

if(!(pFile = fopen (sourcename.c_str(),"r")))
    throw(sourcename);

std::string obuf;

while(fgets(buff, sizeof(buff), pFile)!=NULL)
{
    obuf += buff;
}

while (obuf.find("id=\"node")!=std::string::npos)
{
    int p1 = obuf.find("id=\"node");
    int p2 = obuf.find("\"",p1);
    obuf.erase(p1,2+p2-p1);
}

file << obuf;

fclose(pFile);
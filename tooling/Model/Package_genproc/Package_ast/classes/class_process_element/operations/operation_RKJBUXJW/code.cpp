//~~ void create_GateOverview(std::ofstream& outfile, const std::string& outpath) [process_element] ~~

create_headline(outfile, "Gate overview");


std::ofstream hfile;
std::string filename = outpath + "/help.md";
hfile.open (filename.c_str(), std::ofstream::out);

unsigned int lineCount = 0;

for (std::map<std::string, std::vector<artefact_base*> >::const_iterator it = gateTable.begin(); it != gateTable.end(); it++ )
{
    if ((*it).second.size() > lineCount)
        lineCount = (*it).second.size();
}

for (std::vector<std::string>::const_iterator it = processGates.begin(); it != processGates.end(); it++ )
{
    hfile << "|" << (*it);
}
hfile << "|" << std::endl;

for (std::vector<std::string>::const_iterator it = processGates.begin(); it != processGates.end(); it++ )
{
    hfile << "|------";
}
hfile << "|" << std::endl;

for (unsigned int i = 0; i < lineCount; i++)
{
    for (std::vector<std::string>::const_iterator it = processGates.begin(); it != processGates.end(); it++ )
    {
        const std::vector<artefact_base*> v;
        std::map<std::string, std::vector<artefact_base*> >::const_iterator it2 = gateTable.find(*it);
        
        if ((it2 != gateTable.end()) && ((*it2).second.size() > i))
        {
            label_owner* lo = dynamic_cast<label_owner*>((*it2).second[i]);
            hfile << "[" << lo->getLabel() << "](" << (*it2).second[i]->getHtmlFilename() << ")";
        }
        else
        {
            hfile << " |";
        }
    }
    hfile << " |" << std::endl;
}

hfile.close();

FILE *in;
char buff[512];

std::string command("pandoc " + filename);

if(!(in = popen(command.c_str(), "r")))
    throw(command);

while(fgets(buff, sizeof(buff), in)!=NULL)
{
    outfile << buff;
}

pclose(in);
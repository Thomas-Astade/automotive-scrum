//~~ void generate_all(const std::string& outpath, const std::set<std::string>& filenames) [I_element] ~~
unsigned int count = 0;

for (std::map<std::string,I_element*>::iterator it = object_list.begin(); it != object_list.end(); it++)
{
    if (filenames.empty() || (filenames.find((*it).second->getHtmlFilename())!=filenames.end()))
    {
        (*it).second->generate(outpath);
        count++;
    }
}

std::ofstream ofs;
std::string fullName = outpath + "/sitemap.xml";
ofs.open (fullName.c_str(), std::ofstream::out);

time_t rawtime;
struct tm * timeinfo;
char buffer[80];

time (&rawtime);
timeinfo = localtime(&rawtime);

strftime(buffer,80,"%Y-%m-%d",timeinfo);

ofs << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
ofs << "<urlset xmlns=\"http://www.sitemaps.org/schemas/sitemap/0.9\">" << std::endl;

for (std::map<std::string,I_element*>::iterator it = object_list.begin(); it != object_list.end(); it++)
{
    ofs << "<url>" << std::endl;
    
    ofs << "<loc>http://automotive-scrum.org/"
        << (*it).second->getHtmlFilename()
        << "</loc>" << std::endl;
        
    ofs << "<lastmod>"
        << buffer
        << "</lastmod>" << std::endl;
        
    ofs.precision(2);
    
    ofs << "<priority>"
        << (*it).second->getPriority()
        << "</priority>" << std::endl;
        
    ofs << "</url>" << std::endl;
}

if (count == 1)
    std::cout << "created " << count << " element." << std::endl;
else
    std::cout << "created " << count << " elements." << std::endl;

ofs << "</urlset>" << std::endl;

ofs.close();
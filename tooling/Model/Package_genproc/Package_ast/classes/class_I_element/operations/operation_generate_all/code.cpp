//~~ void generate_all(const std::string& outpath) [I_element] ~~
std::ofstream ofs;
std::string fullName = outpath+"/sitemap.xml";
ofs.open (fullName.c_str(), std::ofstream::out);

ofs << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
ofs << "<urlset xmlns=\"http://www.sitemaps.org/schemas/sitemap/0.9\">" << std::endl;

for (std::map<std::string,I_element*>::iterator it = object_list.begin(); it != object_list.end(); it++)
{
    (*it).second->generate(outpath);

    ofs << "<url>" << std::endl;
    ofs << "<loc>http://automotive-scrum.org/"
        << (*it).second->getHtmlFilename()
        << "</loc>" << std::endl;
    ofs << "</url>" << std::endl;

}

std::cout << "created " << object_list.size() << " elements." << std::endl;

ofs << "</urlset>" << std::endl;

ofs.close();
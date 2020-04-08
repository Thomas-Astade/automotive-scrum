//~~ void generate(const std::string& outpath) [I_element] ~~
std::ofstream ofs;
std::string fullName = outpath+"/"+getHtmlFilename();
ofs.open (fullName.c_str(), std::ofstream::out);
std::cout << "generating file: " << fullName << std::endl;

generate_header(ofs);
generate_body(ofs,outpath);
generate_footer(ofs);
ofs.close();

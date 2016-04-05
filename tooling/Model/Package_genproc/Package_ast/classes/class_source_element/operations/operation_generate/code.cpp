//~~ void generate(const std::string& filename, const std::string& outpath) [source_element] ~~
std::ofstream ofs;
std::string fullName = outpath+"/"+getHtmlFileName(filename);
ofs.open (fullName.c_str(), std::ofstream::out);
std::cout << "generating file: " << fullName << std::endl;
generate_header(filename, ofs);
generate_body(filename, ofs, outpath);
generate_footer(filename, ofs);
ofs.close();

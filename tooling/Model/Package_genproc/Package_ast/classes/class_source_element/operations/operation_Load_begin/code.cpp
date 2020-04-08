//~~ void Load_begin(const std::string& filename, const std::string& outpath, bool generatePage) [source_element] ~~
loadStack.push_back(filename);

if (alreadyGenerated.find(filename) == alreadyGenerated.end() && generatePage)
    generate(filename,outpath);

alreadyGenerated.insert(filename);
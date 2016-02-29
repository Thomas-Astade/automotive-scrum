//~~ std::string breakApart(const std::string& inString) [I_element] ~~
std::string s(inString);
std::string ret;
std::vector<std::string> words;
std::vector<std::string> lines;

while (!s.empty())
{
    size_t l = s.find(' ');
    if(l == 0)
    {
        s.erase(0,1);
    }
    else if (l == std::string::npos)
    {
        words.push_back(s);
        s.clear();
    }
    else
    {
        words.push_back(s.substr(0,l));
        s.erase(0,l);
    }
}

std::string h;

while (!words.empty())
{
    if (h.size() + words.front().size() < 20)
    {
        if (h.empty())
            h += words.front();
        else
            h += std::string(" ") + words.front();
        words.erase(words.begin());
    } 
    else if (!h.empty())
    {
        lines.push_back(h);
        h.clear();
    }
    else
    {
        lines.push_back(words.front());
        words.erase(words.begin());
    }
    
}

if (!h.empty())
    lines.push_back(h);

for (std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); it++)
{
    if (it != lines.begin())
        ret += "\\n";
    ret += (*it);
}

return ret;

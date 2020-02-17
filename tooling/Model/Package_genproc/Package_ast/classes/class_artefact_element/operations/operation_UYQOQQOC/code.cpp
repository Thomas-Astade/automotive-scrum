//~~ void insertToConfigurationPlan(std::ofstream& ofs, unsigned int firstColumn, unsigned int secondColumn) [artefact_element] ~~
std::vector<ast::I_element*> subpages = getSubpages();
unsigned int printContent = 1;

std::string name = std::string("[") + I_element::getLabel() + "](" + getHtmlFilename() + ")";

if (subpages.size() > 0)
    ofs << std::setw(firstColumn) << name << std::setw(secondColumn) << subpages[0]->getLabel() << " " << getPath() << std::endl;
else
    ofs << std::setw(firstColumn) << name << std::setw(secondColumn) << "-" << " " << getPath() << std::endl;

if (I_element::getBrief().size() > 2)
{
    printContent = 2;
    if (subpages.size() > 1)
        ofs << std::setw(firstColumn) << I_element::getBrief() << std::setw(secondColumn) << subpages[1]->getLabel() << std::endl;
    else
        ofs << std::setw(firstColumn) << I_element::getBrief() << std::endl;
}

if (subpages.size() > printContent)
    for (unsigned int i = printContent; i < subpages.size(); i++)
        ofs << std::setw(firstColumn+secondColumn) << subpages[i]->getLabel() << std::endl;

ofs << std::endl;

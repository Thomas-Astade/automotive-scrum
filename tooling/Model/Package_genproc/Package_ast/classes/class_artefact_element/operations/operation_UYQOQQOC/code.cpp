//~~ void insertToConfigurationPlan(std::ofstream ofs ofs, unsigned int int firstColumn, unsigned int int secondColumn) [artefact_element] ~~
ofs << std::setw(firstColumn) << I_element::getLabel() << std::setw(secondColumn) << "Content" << " Path" << std::endl << std::endl;

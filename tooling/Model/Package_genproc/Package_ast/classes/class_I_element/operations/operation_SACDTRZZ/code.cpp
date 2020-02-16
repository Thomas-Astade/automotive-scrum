//~~ void generateConfigurationManagementPlan(const std::string& outpath) [I_element] ~~
std::set<process_element*> processes;

for (std::map<std::string,I_element*>::iterator it = object_list.begin(); it != object_list.end(); it++)
{
    I_element* e = (*it).second;
    artefact_element* artefact = dynamic_cast<artefact_element*>(e);
    if (artefact)
    {
        process_element* process = dynamic_cast<process_element*>(artefact->getProcess());
        if (process)
            processes.insert(process);
    }
}

for (std::set<process_element*>::iterator it = processes.begin(); it != processes.end(); it++)
{
    
    std::ofstream ofs;
    std::string fullName = outpath + "/ConfigurationManagementPlan_" + (*it)->getFullIdentifier() + ".md";
    ofs.open (fullName.c_str(), std::ofstream::out);
    ofs << "Configuration Management Plan" << std::endl;
    ofs << "=============================" << std::endl << std::endl;
    ofs << "-------------------------------------------------" << std::endl;
    ofs << "ConfigurationItem                                            Content                                           Path    " << std::endl;
    ofs << "------------------------------------------------------------ ------------------------------------------------- --------" << std::endl;

    for (std::map<std::string,I_element*>::iterator it2 = object_list.begin(); it2 != object_list.end(); it2++)
    {
        I_element* e = (*it2).second;
        artefact_element* artefact = dynamic_cast<artefact_element*>(e);
        if (artefact)
        {
            folder_element* f = dynamic_cast<folder_element*>(artefact->getParent());
            if (f)
            {
                process_element* process = dynamic_cast<process_element*>(artefact->getProcess());
                if (process == *it)
                {
                    artefact->insertToConfigurationPlan(ofs,60,50);
                }
            }
        }
      
    }
    
    ofs << "-----------------------------------------" << std::endl << std::endl;
    ofs.close();
    
}
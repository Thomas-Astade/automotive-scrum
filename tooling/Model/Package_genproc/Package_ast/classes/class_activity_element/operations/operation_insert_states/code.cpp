//~~ void insert_states(FILE* gfile) [activity_element] ~~

std::set<std::string> duplicate;

for (std::vector<transition>::const_iterator it = m_transitions.begin(); it != m_transitions.end(); it++)
if((*it).getElement())
{
    std::string connection;
    std::string node;

    node = getFullIdentifier() + "_" + (*it).getDestination();
    node +=  " ["
         + graphics_creator::text_standards
         + "shape=Mrecord, label=\"" 
         + (*it).getElement()->breakApart((*it).getElement()->getLabel())
         + "|"
         + (*it).getDestination()
         + "\", tooltip=\""
         + (*it).getElement()->getBrief()
         + "\", URL=\""
         + (*it).getElement()->getHtmlFilename()
         + std::string("\", style=filled, color=\"#AFCEBE\", fillcolor=\"#177445\", ")
         + "fontcolor=\"#AFCEBE\"];";
         
    fputs(node.c_str(),gfile);

    if ((*it).getSource()!="null")
    {
        node = getFullIdentifier() + "_" + (*it).getSource();
        node +=  " ["
             + graphics_creator::text_standards
             + "shape=Mrecord, label=\"" 
             + (*it).getElement()->breakApart((*it).getElement()->getLabel())
             + "|"
             + (*it).getSource()
             + "\", tooltip=\""
             + (*it).getElement()->getBrief()
             + "\", URL=\""
             + (*it).getElement()->getHtmlFilename()
             + std::string("\", style=filled, color=\"#AFCEBE\", fillcolor=\"#177445\", ")
             + "fontcolor=\"#AFCEBE\"];";
             
        fputs(node.c_str(),gfile);
    }

    connection = getFullIdentifier()
        + " -> "
        + getFullIdentifier() + "_" + (*it).getDestination()
        + "["
        +  text_standards;
        if (!(*it).getGuard().empty())
        {
            connection += "label=\"[";
            connection += (*it).getGuard();
            connection += "]\", ";
        }
        connection += "fontcolor=\"#177445\", color=\"#177445\"];";
    
    fputs(connection.c_str(),gfile);

    if ((*it).getSource()!="null")
    {
        connection = getFullIdentifier() + "_" + (*it).getSource()
            + " -> "
            + getFullIdentifier()
        + "["
            + text_standards
            + "fontcolor=\"#177445\", color=\"#177445\"];";
        
        if (duplicate.find(connection) == duplicate.end())
        {
            fputs(connection.c_str(),gfile);
            duplicate.insert(connection);
        }
    }

}

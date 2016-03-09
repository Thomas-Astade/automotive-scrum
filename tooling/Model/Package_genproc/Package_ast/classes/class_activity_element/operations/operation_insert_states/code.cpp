//~~ void insert_states(FILE* gfile) [activity_element] ~~

for (std::vector<transition>::const_iterator it = m_transitions.begin(); it != m_transitions.end(); it++)
if((*it).getElement())
{
    std::string connection;
    std::string node;

    node = label_owner::getIdentifier() + "_" + (*it).getDestination();
    node +=  " [shape=Mrecord, label=\"" 
         + (*it).getElement()->getLabel()
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
        node = label_owner::getIdentifier() + "_" + (*it).getSource();
        node +=  " [shape=Mrecord, label=\"" 
             + (*it).getElement()->getLabel()
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

    connection = label_owner::getIdentifier()
        + " -> "
        + label_owner::getIdentifier() + "_" + (*it).getDestination()
        + "["
        +  text_standards
        + "fontcolor=\"#177445\", color=\"#177445\"];";
    
    fputs(connection.c_str(),gfile);

    if ((*it).getSource()!="null")
    {
        connection = label_owner::getIdentifier() + "_" + (*it).getSource()
            + " -> "
            + label_owner::getIdentifier()
        + "["
            + text_standards
            + "fontcolor=\"#177445\", color=\"#177445\"];";
        
        fputs(connection.c_str(),gfile);
    }

}

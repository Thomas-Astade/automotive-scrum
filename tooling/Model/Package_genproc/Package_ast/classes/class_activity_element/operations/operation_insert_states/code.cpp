//~~ void insert_states(FILE* gfile) [activity_element] ~~

std::set<std::string> duplicate;

for (std::vector<transition>::const_iterator it = m_transitions.begin(); it != m_transitions.end(); it++)
if((*it).getElement())
{
    std::string connection;

    if ((*it).getDestination()!="null")
    {
        fputs(dynamic_cast<artefact_element*>((*it).getElement())->get_graph_node(false, (*it).getDestination()).c_str(),gfile);
    }

    if ((*it).getSource()!="null")
    {
        fputs(dynamic_cast<artefact_element*>((*it).getElement())->get_graph_node(false, (*it).getSource()).c_str(),gfile);
    }

    if (((*it).getDestination()!="null") && ((*it).getSource() != (*it).getDestination()))
    {
        connection = getFullIdentifier()
            + " -> "
            + (*it).getElement()->getFullIdentifier() + "_" + (*it).getDestination()
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
    }

    if ((*it).getSource()!="null")
    {
        connection = (*it).getElement()->getFullIdentifier() + "_" + (*it).getSource()
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

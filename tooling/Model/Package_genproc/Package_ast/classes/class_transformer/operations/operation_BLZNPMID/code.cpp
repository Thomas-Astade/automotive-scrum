//~~ void add_transition(const transition& transition) [transformer] ~~
transformer* t = dynamic_cast<transformer*>(&I_element::get_last());

if(t)
    t->m_transitions.push_back(transition);
//~~ void assignGates() [artefact_base] ~~
if (!processGate.empty())
{
    process_element* p = dynamic_cast<process_element*>(getProcess());
    if (p)
    {
        p->insertArtefactToGate(*this, processGate);
    }
}


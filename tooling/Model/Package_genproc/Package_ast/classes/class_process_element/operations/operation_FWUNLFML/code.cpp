//~~ void insertArtefactToGate(artefact_base& artefact, const std::string& gate) [process_element] ~~
if (processGatesSet.find(gate) == processGatesSet.end())
    warn_no_gate(artefact);
else
    gateTable[gate].push_back(&artefact);
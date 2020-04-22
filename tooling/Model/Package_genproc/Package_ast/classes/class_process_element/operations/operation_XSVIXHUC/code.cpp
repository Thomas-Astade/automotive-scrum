//~~ void warn_no_gate(artefact_base& artefact) [process_element] ~~
std::cerr   << "Warning: The element "
            << artefact.getFullIdentifier()
            << " specifies a gate that does not exist."
            << std::endl;

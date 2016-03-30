//~~ void deactivateParameters(bool dump) [parameters] ~~
currentParameters.clear();

if (!callStack.empty())
     callStack.pop_back();

if (!callStack.empty())
    currentParameters = callStack.back();

if (dump)
    dump_parameters("end:   ");
//~~ void activateParameters(bool dump) [parameters] ~~
currentParameters = futureParameters;
futureParameters.clear();
callStack.push_back(currentParameters);

if (dump)
    dump_parameters("begin: ");
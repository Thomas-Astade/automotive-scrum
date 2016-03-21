//~~ void deactivateParameters() [parameters] ~~
currentParameters.clear();

if (!callStack.empty())
{
    currentParameters = callStack.back();
    callStack.pop_back();
}
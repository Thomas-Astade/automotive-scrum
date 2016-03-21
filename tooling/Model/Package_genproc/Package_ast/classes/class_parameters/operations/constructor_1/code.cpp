//~~ parameters(unsigned int parameterNumber) [parameters] ~~
 std::cout << "number " << parameterNumber << std::endl;
if (parameterNumber < currentParameters.size())
{
    this->assign(currentParameters[parameterNumber]);
    std::cout << "assigning " << currentParameters[parameterNumber] << std::endl;
}
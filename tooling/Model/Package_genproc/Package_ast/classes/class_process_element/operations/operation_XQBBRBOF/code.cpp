//~~ void addImpliciteTool(tool_element* tool) [process_element] ~~
if ((tool != getTool()) &&
     (implicite_tools.find(tool) == implicite_tools.end())
    )
{
    implicite_tools.insert(tool);
    tool->init_link(this);
}
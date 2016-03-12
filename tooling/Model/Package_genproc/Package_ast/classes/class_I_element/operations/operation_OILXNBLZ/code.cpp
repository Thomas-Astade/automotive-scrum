//~~ bool removeNamespace() [I_element] ~~
if (current_namespace.empty())
    return false;

current_namespace.pop_back();
return true;
//~~ void add_activity(activity_element* element, int isDirectActivity) [role_element] ~~
if (isDirectActivity)
    direct_activities.insert(element);
else
    indirect_activities.insert(element);

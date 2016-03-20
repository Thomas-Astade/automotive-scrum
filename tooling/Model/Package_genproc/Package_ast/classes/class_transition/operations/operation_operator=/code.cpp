//~~ ast::transition& operator=(const transition& orig) [transition] ~~
last_created = this;
artefact_ID = orig.artefact_ID;
sourceState = orig.sourceState;
destinationState = orig.destinationState;
guard = orig.guard;
return *this;
#ifndef STEPPING_HH
#define STEPPING_HH

#include "G4UserSteppingAction.hh"

#include "event.hh"
#include "construction.hh"

class MySteppingAction : public G4UserSteppingAction
{
public:
    MySteppingAction(MyEventAction* eventAction);
    virtual ~MySteppingAction();

    virtual void UserSteppingAction(const G4Step*);

private:
    MyEventAction* eventAction;
    G4LogicalVolume* scoringVolume;
};

#endif

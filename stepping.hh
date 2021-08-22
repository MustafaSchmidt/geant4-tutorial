#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include "construction.hh"
#include "event.hh"

class MySteppingAction : public G4UserSteppingAction
{
public:
    MySteppingAction(MyEventAction* eventAction);
    virtual ~MySteppingAction();

    virtual void UserSteppingAction(const G4Step*);

private:
    MyEventAction* fEventAction;
};

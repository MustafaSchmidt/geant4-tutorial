#include "stepping.hh"

MySteppingAction::MySteppingAction(MyEventAction* eventAction)
{}

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step*)
{
    const MyDetectorConstruction* detectorConstruction = static_cast<const MyDetectorConstruction*>(G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    
    scoringVolume = detectorConstruction->GetScoringVolume();
}

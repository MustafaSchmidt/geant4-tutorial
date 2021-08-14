#include "run.hh"

MyRunAction::MyRunAction()
{
    edep = 0.;
    
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->CreateNtuple("Photons", "Photons");
    man->CreateNtupleIColumn("fEvent");
    man->CreateNtupleDColumn("fX");
    man->CreateNtupleDColumn("fY");
    man->CreateNtupleDColumn("fZ");
    man->CreateNtupleDColumn("fWlen");
    man->FinishNtuple(0);
    
    man->CreateNtuple("Hits", "Hits");
    man->CreateNtupleIColumn("fEvent");
    man->CreateNtupleDColumn("fX");
    man->CreateNtupleDColumn("fY");
    man->CreateNtupleDColumn("fZ");
    man->FinishNtuple(1);
    
    G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
    accumulableManager->RegisterAccumulable(edep);
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    
    G4int runID = run->GetRunID();
    
    std::stringstream strRunID;
    strRunID << runID;
    
    man->OpenFile("output"+strRunID.str()+".root");
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    
    man->Write();
    man->CloseFile();
}

#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericMessenger.hh"

#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    MyDetectorConstruction();
    ~MyDetectorConstruction();
    
    void ConstructCherenkov();
    void ConstructScintillator();
    
    virtual G4VPhysicalVolume *Construct();
    
    G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }
    
private:
    G4Tubs *solidScint;
    G4Box *solidWorld, *solidRadiator, *solidDetector;
    G4LogicalVolume *logicWorld, *logicRadiator, *logicDetector, *logicScint;
    G4VPhysicalVolume *physWorld, *physDetector, *physRadiator, *physScint;
    
    G4Material *SiO2, *H2O, *Aerogel, *worldMat;
    G4Element *C;
    
    void DefineMaterials();
    virtual void ConstructSDandField();
    
    G4GenericMessenger *fMessenger;
    
    G4int nRows, nCols;
    
    G4double xWorld, yWorld, zWorld;
    
    G4bool cherenkov, scintillator;
    
    G4LogicalVolume*  fScoringVolume;
};

#endif

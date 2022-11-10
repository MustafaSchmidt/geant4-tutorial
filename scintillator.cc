#include "scintillator.hh"

ScintillatorConstruction::ScintillatorConstruction()
{
    nCols = 10;
    nRows = 10;

    xWorld = 10.*cm;
    yWorld = 10.*cm;
    zWorld = 10.*cm; 

    fMessenger = new G4GenericMessenger(this, "/detector/", "Detector Construction");

    fMessenger->DeclareProperty("nCols", nCols, "Number of cols");
    fMessenger->DeclareProperty("nRows", nRows, "Number of rows");

    DefineMaterials();
    
    Construct();
}


ScintillatorConstruction::~ScintillatorConstruction()
{}


void ScintillatorConstruction::DefineMaterials()
{
    G4double energy[2] = {1.239841939*eV/0.2, 1.239841939*eV/0.9};
    G4double rindex_PlasticSC[2] = {1.58, 1.58};
    G4double rindexWorld[2] = {1.0, 1.0};
    G4double reflectivity[2] = {1.0, 1.0};

    // Plastic Scitillator

    G4NistManager *nIst = G4NistManager::Instance();

    plastic_SC_material = nIst->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE_KKKKKK");

    G4MaterialPropertiesTable *MPT_plastic_SC = new G4MaterialPropertiesTable();
    MPT_plastic_SC->AddProperty("RINDEX", energy, rindex_PlasticSC, 2);

    plastic_SC_material->SetMaterialPropertiesTable(MPT_plastic_SC);


    // World Volume

    G4MaterialPropertiesTable *MPT_world = new G4MaterialPropertiesTable();
    MPT_world->AddProperty("RINDEX", energy, rindexWorld, 2);

    world_material->SetMaterialPropertiesTable(MPT_world);


    // Mirror Surface

    mirrorSurface = new G4OpticalSurface("mirrorSurface");

    mirrorSurface->SetType(dielectric_metal);
    mirrorSurface->SetFinish(ground);
    mirrorSurface->SetModel(unified);

    G4MaterialPropertiesTable *mptMirror = new G4MaterialPropertiesTable();
    mptMirror->AddProperty("REFLECTIVITY", energy, reflectivity, 2);

    mirrorSurface->SetMaterialPropertiesTable(mptMirror);
}


void ScintillatorConstruction::Construct_Detector()
{
    solidScintillator = new G4Box("solidScintillator", Solid_Scintillator_X, Solid_Scintillator_Y, Solid_Scintillator_Z);

    logicScintillator = new G4LogicalVolume(solidScintillator, plastic_SC_material, "logicalScintillator");

    fScoringVolume = logicScintillator;


    solidDetector = new G4Box("solidDetector", Solid_Detector_X, Solid_Detector_Y, Solid_Detector_Z);

    logicDetector = new G4LogicalVolume(solidDetector, world_material, "logicDetector");


    skin = new G4LogicalSkinSurface("skin", logicWorld, mirrorSurface);


    for(G4int i = 0; i < 6; i++)
    {
        for(G4int j = 0; j < 16; j++)
        {
            G4Rotate3D rotZ(j*22.5*deg, G4ThreeVector(0,0,1));
            G4Translate3D transXScint(G4ThreeVector(5./tan(22.5/2*deg)*cm+5.*cm, 0.*cm, -40.*cm + i*15*cm));
            G4Transform3D transformScint = (rotZ)*(transXScint);

            G4Translate3D transXDet(G4ThreeVector(5./tan(22.5/2*deg)*cm+5.*cm+6.*cm, 0.*cm, -40.*cm + i*15*cm));
            G4Transform3D transformDet = (rotZ)*(transXDet);

            physScintillator = new G4PVPlacement(transformScint, logicScintillator, "physScintillator", logicWorld, false, 0, true);

            physDetector = new G4PVPlacement(transformDet, logicDetector, "physDetector", logicWorld, false, 0, true);
        }
    }
}


G4VPhysicalVolume *ScintillatorConstruction::Construct_World()
{
    solidWorld = new G4Box("solidWorld", xWorld, yWorld, zWorld);

    logicWorld = new G4LogicalVolume(solidWorld, world_material, "logicWorld");

    physWorld  = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

    return physWorld;
}

G4VPhysicalVolume *ScintillatorConstruction::Construct(){

    Construct_World();

    Construct_Detector();

    return physWorld;
}

void ScintillatorConstruction::Construct_SensitiveDetector_and_Field()
{
    MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");

    if(logicDetector != NULL)
        logicDetector->SetSensitiveDetector(sensDet);
}


G4LogicalVolume* ScintillatorConstruction::GetScoringVolume() const { 
    return fScoringVolume; 
}

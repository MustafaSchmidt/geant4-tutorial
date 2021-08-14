#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
    fParticleGun = new G4ParticleGun(1);
    
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName="proton";
    G4ParticleDefinition *particle = particleTable->FindParticle("chargedgeantino");
    
    G4ThreeVector pos(0.,0.,0.);
    G4ThreeVector mom(0.,0.,1.);
    
    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleMomentum(0.*GeV);
    fParticleGun->SetParticleDefinition(particle);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
    G4int Z = 9;
    G4int A = 18;
    G4double Q = 0.*eplus;
    G4double E = 0.*keV;
    
    G4ParticleDefinition* ion = G4IonTable::GetIonTable()->GetIon(Z, A, E);
    fParticleGun->SetParticleDefinition(ion);
    fParticleGun->SetParticleCharge(Q);
    
    fParticleGun->GeneratePrimaryVertex(anEvent);
}

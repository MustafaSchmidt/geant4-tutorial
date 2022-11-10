#ifndef CFG_HH
#define CFG_HH

#include <nlohmann/json.hpp> // https://json.nlohmann.me/integration/package_managers/#homebrew
#include "G4SystemOfUnits.hh"

// Scintillator Parameters (cilynder)

#define SC_height 10*cm
#define SC_diameter 10*cm



#define Solid_Scintillator_X 5.*cm
#define Solid_Scintillator_Y 5.*cm
#define Solid_Scintillator_Z 6.*cm

#define Solid_Detector_X 1.*cm
#define Solid_Detector_Y 5.*cm
#define Solid_Detector_Z 6.*cm

#endif

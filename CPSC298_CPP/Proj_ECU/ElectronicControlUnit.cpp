#include "ElectronicControlUnit.h"
#include <iostream>

ElectronicControlUnit::ElectronicControlUnit() {
  activatedBeltTires = false;
  activatedHydraulicJacks = false;
  activatedIRIllumination = false;
}

ElectronicControlUnit::~ElectronicControlUnit() {

}

  void ElectronicControlUnit::actuateHydraulics() {
    activatedHydraulicJacks = !activatedHydraulicJacks;
    if(activatedHydraulicJacks) {
      std::cout << "Hydraulic jacks activated" << std::endl;
    } else {
      std::cout << "Hydraulic jacks deactivated" << std::endl;
    }
  }

  void ElectronicControlUnit::actuateBelt() {
    activatedBeltTires = !activatedBeltTires;
    if(activatedBeltTires) {
      std::cout << "Belt tires activated" << std::endl;
    } else {
      std::cout << "Belt tires deactivated" << std::endl;
    }
  }

  void ElectronicControlUnit::actuateIR() {
    activatedIRIllumination = !activatedIRIllumination;
    if(activatedIRIllumination) {
      std::cout << "Infrared illumination activated" << std::endl;
    } else {
      std::cout << "Infrared illumination deactivated" << std::endl;
    }
  }

  void ElectronicControlUnit::handleCommand(char c) {
    switch(c) {
      case 'A':
      case 'a':
        actuateHydraulics();
        break;
      case 'B':
      case 'b':
        actuateBelt();
        break;
      case 'E':
      case 'e':
        actuateIR();
        break;
      default:
        std::cout << "Incorrect input" << std::endl;
        break;
    }
  }

#if !defined(ELECTRONICCONTROLUNIT_H)
#define ELECTRONICCONTROLUNIT_H

class ElectronicControlUnit {
public:
  ElectronicControlUnit();
  ~ElectronicControlUnit();
  void handleCommand(char c);

private:
  bool activatedHydraulicJacks;
  bool activatedBeltTires;
  bool activatedIRIllumination;

  void actuateHydraulics();
  void actuateBelt();
  void actuateIR();

};

#endif

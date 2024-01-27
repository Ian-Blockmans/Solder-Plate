#include "./globals.h"
#include "./EEPROMDataManager.h"

WrappedState<ReflowProcessState> reflowProcessState = WrappedState<ReflowProcessState>(INITIALIZING);
AnalogRef analogRef(5.0);
TempCalibration calibration_100K_3950 = {25, 100000, 86, 10000, 170, 1000};
// Initalize the 3950 100K thermistors with ACTUAL reference resistor measurnment(Measured between Left pin and GND when the board is powered off) using the default calibration data for 100K thermistor
Thermistor thermistor1(THERMISTOR1_PIN, 2500);
Thermistor thermistor2(THERMISTOR2_PIN, 2500);
Thermistor thermistor3(THERMISTOR3_PIN, 2500);
Thermistor thermistor4(THERMISTOR4_PIN, 2500);
Thermistor thermistor5(THERMISTOR5_PIN, 2500);
Thermistor thermistor6(THERMISTOR6_PIN, 9000);
Thermistor thermistors[6] = {thermistor1, thermistor2, thermistor3, thermistor4, thermistor5, thermistor6};

ReflowProfile reflowProfiles[] = {
   ReflowProfile(new ReflowStep[5] {
    ReflowStep(ReflowProcessState::PREHEAT, 2, 150),
    ReflowStep(ReflowProcessState::SOAK, 3, 180),
    ReflowStep(ReflowProcessState::REFLOW, 3, 220, EASE_IN_OUT),
    ReflowStep(ReflowProcessState::COOL, 3, 100),
    ReflowStep(ReflowProcessState::DONE, 0, 0)
  }, "Test\0"),
 ReflowProfile(new ReflowStep[5] {
    ReflowStep(ReflowProcessState::PREHEAT, 2, 150),
    ReflowStep(ReflowProcessState::SOAK, 3, 180),
    ReflowStep(ReflowProcessState::REFLOW, 3, 220, EASE_IN_OUT),
    ReflowStep(ReflowProcessState::COOL, 3, 100),
    ReflowStep(ReflowProcessState::DONE, 0, 0)
  }, "Test2\0"),
};

int nReflowProfiles = 2;

uint16_t plateResistanceOhm = 0;
EEPROMDataManager eepromDataManager = EEPROMDataManager();

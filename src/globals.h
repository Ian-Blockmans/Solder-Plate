#ifndef GLOBALS_H
#define GLOBALS_H
#include "./common.h"
#include "./thermistors/Thermistor.h"
#include "./reflow.h"
#include "./EEPROMDataManager.h"
#include "./PID/PidController.h"

//Comment out to disable debug messages

//#define DEBUG 

//For printing debug messages
#ifdef DEBUG
#define debugLine(x)  Serial.println(x)
#define debugC(x) Serial.print(x)
#else
#define debugLine(x)
#define debugC(x)
#endif


extern WrappedState<ReflowProcessState> reflowProcessState;
extern AnalogRef analogRef;
extern Thermistor thermistor1;
extern Thermistor thermistor2;
extern Thermistor thermistor3;
extern Thermistor thermistor4;
extern Thermistor thermistor5;
extern Thermistor thermistor6;
extern Thermistor thermistors[6];
extern ReflowProfile reflowProfiles[];
extern ReflowProfile chosenReflowProfile;
extern uint16_t plateResistanceOhm;
extern int nReflowProfiles;

extern PidControllerData pidControllerData;
extern PidController pidController;
extern EEPROMDataManager eepromDataManager;

#endif
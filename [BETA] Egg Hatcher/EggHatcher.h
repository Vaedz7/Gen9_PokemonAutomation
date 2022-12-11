// SETTINGS FILE FOR:
// SCVI SLOW EGG HATCHER
// ---------------------
// (tries to) Hatch a batch of 6 eggs every 13 minutes.
//
// CREDITS
// -------
// - Pokemon Automation Team for HEX Generator, and Program Base
// - Vaedz#1011 for Program
// -------
// SCARLET AND VIOLET VERSION
// WORKS WITH BOTH GAMES
//
// TESTING
// -------
// Teensy 2 - UNTESTED
// Teensy 2++ - UNTESTED
// Arduino Leonardo - STABLE
// Arduino UNO R3 - STABLE
// Pro Micro - UNTESTED

#include "Common/NintendoSwitch/NintendoSwitch_ControllerDefs.h"

//  Set to the number of 5 egg batches to be hatched.
extern const uint16_t BATCH_LIMIT;

//  Set to the number of boxes ahead of the "egg box" the deposit box is.
extern const uint16_t DEPOSIT_BOX;

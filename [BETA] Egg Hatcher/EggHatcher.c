// SETTINGS FILE FOR:
// SCVI EGG HATCHER
// ---------------------
// Hatches a specified number of eggs.
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
// Arduino Leonardo - UNTESTED
// Arduino UNO R3 - UNTESTED
// Pro Micro - UNTESTED

#include "Common/NintendoSwitch/NintendoSwitch_ControllerDefs.h"
#include "Programs/FriendDelete.h"



//  Set to the number of 5 egg batches to be hatched.
const uint16_t BATCH_LIMIT    =   6;

//  Set to the number of boxes ahead of the "egg box" the deposit box is.
const uint16_t DEPOSIT_BOX    =   3;



// SCVI ITEM DUPLICATION VERSION 2
// -------------------------------
// Includes reset in case of failures and optimized squence to duplicate 999x in under 6 hours!
//
// CREDITS (FOR BASE v1 PROGRAM)
// -------
// - Pokemon Automation Team for HEX Generator, Program Base, and Help in development
// - Vaedz#1011 for Original Program, Development, Failure Reset Function, and Startup Correction
// - Zeverand#6019 for Modifications on timing and Dpad Controls
// - Jack Mutsers#2563 for Optimization, Original Violet Program, Development, Joystick Reset for Emotes, Joystick Cycle System, and Program Condesation
//
// CREDITS (FOR v2 PROGRAM)
// -------
// - Pokemon Automation Team for HEX Generator and Program Base
// - Vaedz#1011 for v2 Development
// -------
// SCARLET AND VIOLET VERSION
// WORKS WITH BOTH GAMES
//
// TESTING
// -------
// Teensy 2 - STABLE
// Teensy 2++ - STABLE
// Arduino Leonardo - STABLE
// Arduino UNO R3 - STABLE
// Pro Micro - STABLE

#include "Common/PokemonSwSh/PokemonProgramIDs.h"
#include "NativePrograms/DeviceFramework/DeviceSettings.h"
#include "NativePrograms/NintendoSwitch/Libraries/FrameworkSettings.h"
#include "NativePrograms/NintendoSwitch/Libraries/NintendoSwitch_Device.h"
#include "NativePrograms/NintendoSwitch/Libraries/NintendoSwitch_PushButtons.h"
#include "NativePrograms/NintendoSwitch/Programs/CustomProgram.h"
#include "NativePrograms/PokemonSwSh/Libraries/PokemonSwSh_Settings.h"

int resetFail = 0;

int main(void){
// START PROGRAM ON MICROCONTROLLER
start_program_callback();
initialize_framework(0);

// START PROGRAM ON SWITCH
start_program_flash(CONNECT_CONTROLLER_DELAY);
grip_menu_connect_go_home();

// START GAME (BE SURE TO HAVE GLITCH ACTIVE)
pbf_press_button(BUTTON_HOME, 10, PokemonSwSh_HOME_TO_GAME_DELAY);
    
// ENSURE MENU IS IN CORRECT POSITION
pbf_press_button(BUTTON_X, 5, 105);
pbf_press_dpad(DPAD_LEFT, 5, 105);
pbf_press_dpad(DPAD_UP, 500, 105);
pbf_press_dpad(DPAD_DOWN, 5, 105);
  
while (true){
	// DELAY START
	pbf_wait(50);

	// ACTIVATE RIDE FORM GLITCH
	pbf_press_button(BUTTON_A, 5, 125);
	pbf_press_dpad(DPAD_UP, 5, 10);
	pbf_press_dpad(DPAD_UP, 5, 85);
	pbf_press_button(BUTTON_A, 5, 130);
	pbf_press_button(BUTTON_A, 5, 140);
	pbf_press_button(BUTTON_A, 5, 100); // ENSURE DIALOG ENDS
	pbf_press_button(BUTTON_A, 5, 300);
	pbf_press_button(BUTTON_A, 5, 100);

	// COLLECT ITEM FROM BOX
	pbf_press_dpad(DPAD_RIGHT, 5, 85);
	pbf_press_dpad(DPAD_DOWN, 5, 25);
	pbf_press_dpad(DPAD_DOWN, 5, 55);
	pbf_press_button(BUTTON_A, 5, 420);
	pbf_press_button(BUTTON_X, 5, 60);
	pbf_press_button(BUTTON_X, 5, 60);
	pbf_press_button(BUTTON_L, 5, 80);
	pbf_press_button(BUTTON_A, 5, 100);
	pbf_press_dpad(DPAD_DOWN, 5, 10);
	pbf_press_dpad(DPAD_DOWN, 5, 10);
	pbf_press_dpad(DPAD_DOWN, 5, 65);
	pbf_press_button(BUTTON_A, 5, 100);
	pbf_press_button(BUTTON_B, 5, 240);

	// GO TO LEGENDARY
	pbf_press_dpad(DPAD_LEFT, 5, 105);
	resetFail++;

	// CHECK FAILURE EVERY 2 CYCLES
if (resetFail = 2) {
    pbf_press_button(BUTTON_B, 5, 105);
    pbf_press_button(BUTTON_B, 5, 105);
    pbf_press_button(BUTTON_B, 5, 105);
    pbf_press_button(BUTTON_B, 5, 105);
    pbf_press_button(BUTTON_PLUS, 5, 375);
    pbf_press_button(BUTTON_A, 5, 105);
    pbf_move_left_joystick(0x80, 0xff, 2, 105);
    pbf_press_button(BUTTON_X, 5, 105);
    pbf_press_dpad(DPAD_LEFT, 5, 105);
    pbf_press_dpad(DPAD_UP, 500, 105);
    pbf_press_dpad(DPAD_DOWN, 5, 105);
};
}
	//EXIT TO IDLE MODE (NEVER USED)
	pbf_press_button(BUTTON_HOME, 10, PokemonSwSh_GAME_TO_HOME_DELAY_SAFE);
	end_program_callback();
	end_program_loop();
};

// SCVI BASIC GIMMIGHOUL COIN FARMER
// ---------------------------------
// Manipulates date in order to collect coins from 5% chance Gimmighoul chest respawn.
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
// Arduino UNO R3 - UNTESTED
// Pro Micro - UNTESTED

#include "Common/PokemonSwSh/PokemonProgramIDs.h"
#include "NativePrograms/DeviceFramework/DeviceSettings.h"
#include "NativePrograms/NintendoSwitch/Libraries/FrameworkSettings.h"
#include "NativePrograms/NintendoSwitch/Libraries/NintendoSwitch_Device.h"
#include "NativePrograms/NintendoSwitch/Libraries/NintendoSwitch_PushButtons.h"
#include "NativePrograms/NintendoSwitch/Programs/CustomProgram.h"
#include "NativePrograms/PokemonSwSh/Libraries/PokemonSwSh_Settings.h"

void dateSkip(void) {
    // EXIT GAME AND NAVIGATE TO SETTINGS
    pbf_press_button(BUTTON_HOME, 10, 500);
    pbf_press_dpad(DPAD_RIGHT, 5, 105);
    pbf_press_dpad(DPAD_RIGHT, 5, 105);
    pbf_press_dpad(DPAD_DOWN, 5, 105);
    pbf_press_dpad(DPAD_RIGHT, 5, 105);
    pbf_press_button(BUTTON_A, 5, 250);
    pbf_press_dpad(DPAD_DOWN, 500, 105);
    pbf_press_dpad(DPAD_RIGHT, 5, 105);
    pbf_press_dpad(DPAD_DOWN, 5, 105);
    pbf_press_dpad(DPAD_DOWN, 5, 105);
    pbf_press_dpad(DPAD_DOWN, 5, 105);
    pbf_press_dpad(DPAD_DOWN, 5, 105);
    pbf_press_dpad(DPAD_DOWN, 5, 105);
    pbf_press_dpad(DPAD_DOWN, 5, 105);
    pbf_press_dpad(DPAD_DOWN, 5, 105);
    pbf_press_button(BUTTON_A, 5, 250);
    pbf_press_dpad(DPAD_DOWN, 5, 105);
    pbf_press_dpad(DPAD_DOWN, 5, 105);
    pbf_press_button(BUTTON_A, 5, 105);
    
    // SKIP DATE
    pbf_press_dpad(DPAD_RIGHT, 5, 105);
    pbf_press_dpad(DPAD_UP, 5, 105);
    pbf_press_dpad(DPAD_RIGHT, 375, 105);
    pbf_press_button(BUTTON_A, 5, 105);
    
    // RETURN TO GAME
    pbf_press_button(BUTTON_HOME, 10, 375);
    pbf_press_button(BUTTON_HOME, 10, PokemonSwSh_HOME_TO_GAME_DELAY);
};

int main(void){
// START PROGRAM ON MICROCONTROLLER
start_program_callback();
initialize_framework(0);

// START PROGRAM ON SWITCH
start_program_flash(CONNECT_CONTROLLER_DELAY);
grip_menu_connect_go_home();

// START GAME (BE SURE TO HAVE INSTRUCTIONS SET UP)
pbf_press_button(BUTTON_HOME, 10, PokemonSwSh_HOME_TO_GAME_DELAY);

while (true){
    // START DELAY
    pbf_wait(250);
    
    // INITIATE BATTLE
    pbf_press_button(BUTTON_A, 5, 1500);
    
    // DEFEAT GIMMIGHOUL
    pbf_press_button(BUTTON_A, 5, 105);
    pbf_press_button(BUTTON_A, 5, 2700);
    
    // MOVE TO CHEST LOCATION
    pbf_move_left_joystick(0x80, 0xff, 375, 5);
    
    // DATE SKIP
    dateSkip();
}
	//EXIT TO IDLE MODE (NEVER USED)
	pbf_press_button(BUTTON_HOME, 10, PokemonSwSh_GAME_TO_HOME_DELAY_SAFE);
	end_program_callback();
	end_program_loop();
};

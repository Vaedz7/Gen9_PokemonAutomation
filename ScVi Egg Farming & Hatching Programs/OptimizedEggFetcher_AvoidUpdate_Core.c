// SCVI OPTIMIZED EGG FARMER
// -------------------------
// (tries to) Collect 5 eggs every minute. Failsafe ensures you won't get stuck in the basket.
//
// CREDITS
// -------
// - Pokemon Automation Team for HEX Generator, and Program Base
// - Vaedz#1011 for Program + Failsafe Mechanism
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

#include "Common/PokemonSwSh/PokemonProgramIDs.h"
#include "NativePrograms/DeviceFramework/DeviceSettings.h"
#include "NativePrograms/NintendoSwitch/Libraries/FrameworkSettings.h"
#include "NativePrograms/NintendoSwitch/Libraries/NintendoSwitch_Device.h"
#include "NativePrograms/NintendoSwitch/Libraries/NintendoSwitch_PushButtons.h"
#include "NativePrograms/NintendoSwitch/Programs/CustomProgram.h"
#include "NativePrograms/PokemonSwSh/Libraries/PokemonSwSh_Settings.h"

int main(void){
// START PROGRAM ON MICROCONTROLLER
start_program_callback();
initialize_framework(0);

// START PROGRAM ON SWITCH
start_program_flash(CONNECT_CONTROLLER_DELAY);
grip_menu_connect_go_home();

// START GAME (BE SURE TO HAVE INSTRUCTIONS SET UP) - AVOID UPDATE
pbf_press_button(BUTTON_HOME, 10, 250);
pbf_press_dpad(DPAD_UP, 5, 105);
pbf_press_button(BUTTON_A, 5, PokemonSwSh_HOME_TO_GAME_DELAY);

while (true){
    // SETUP POSITION FOR FAILSAFE
    pbf_move_left_joystick(0x80, 0xff, 250, 5);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_B, 5, 5);
    pbf_move_left_joystick(0x80, 0x00, 5, 5);
    
    // SPAM A TO COLLECT 5 EGGS EVERY MINUTE
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    pbf_press_button(BUTTON_A, 5, 375);
    
    // FAILSAFE MECHANISM
    pbf_press_button(BUTTON_B, 5, 105);
    pbf_press_button(BUTTON_B, 5, 105);
    pbf_press_button(BUTTON_B, 5, 105);
    pbf_press_button(BUTTON_B, 5, 7500);
}
	//EXIT TO IDLE MODE (NEVER USED)
	pbf_press_button(BUTTON_HOME, 10, PokemonSwSh_GAME_TO_HOME_DELAY_SAFE);
	end_program_callback();
	end_program_loop();
};

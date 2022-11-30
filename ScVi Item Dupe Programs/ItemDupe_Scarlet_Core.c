// SCVI ITEM DUPLICATION
// ---------------------
// ~22s per item + Reset when failed
//
// CREDITS
// -------
// - Pokemon Automation Team for HEX Generator, Program Base, and Help in development
// - Vaedz#1011 for Original Program, Development, and Failure Reset Function
// - Zeverand#6019 for Modifications on timing and Dpad Controls
// - Jack Mutsers#2563 for Optimization, Original Violet Program, Development, and Program Condesation
// -------
// SCARLET VERSION


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

// START GAME (BE SURE TO HAVE GLITCH ACTIVE)
pbf_press_button(BUTTON_HOME, 10, PokemonSwSh_HOME_TO_GAME_DELAY);
int resetFail = 0;
int incConst = 1;

while (true){
	// ENTER MENU AND NAVIGATE TO LEGENDARY
	pbf_press_button(BUTTON_X, 5, 130);

	// ACTIVATE RIDE FORM GLITCH
	pbf_press_button(BUTTON_A, 5, 145);
	pbf_press_dpad(DPAD_UP, 5, 10);
	pbf_press_dpad(DPAD_UP, 5, 55);
	pbf_press_button(BUTTON_A, 5, 120);
	pbf_press_button(BUTTON_A, 5, 105);
	pbf_press_button(BUTTON_A, 5, 405);
	pbf_press_button(BUTTON_A, 5, 75);

	// COLLECT ITEM FROM BOX
	pbf_press_dpad(DPAD_RIGHT, 125, 105);
	pbf_press_dpad(DPAD_DOWN, 5, 15);
	pbf_press_dpad(DPAD_DOWN, 5, 85);
	pbf_press_button(BUTTON_A, 5, 455);
	pbf_press_button(BUTTON_X, 5, 105);
	pbf_press_button(BUTTON_X, 5, 80);
	pbf_press_button(BUTTON_L, 5, 80);
	pbf_press_button(BUTTON_A, 5, 130);
	pbf_press_dpad(DPAD_DOWN, 5, 15);
	pbf_press_dpad(DPAD_DOWN, 5, 15);
	pbf_press_dpad(DPAD_DOWN, 5, 105);
	pbf_press_button(BUTTON_A, 5, 80);
	pbf_press_button(BUTTON_B, 5, 280);

	// RESET MENU AND NAVIGATE OUT OF MENU
	pbf_press_dpad(DPAD_LEFT, 5, 80);
	pbf_press_dpad(DPAD_UP, 5, 5);
	pbf_press_button(BUTTON_B, 5, 5);
    pbf_press_button(BUTTON_B, 5, 5); // ENSURE MENU IS CLOSED
	pbf_wait(130);
    
    // CHECK FAILURE
    if (resetFail > 9) {
        pbf_press_button(BUTTON_B, 5, 5);
        pbf_wait(100);
        pbf_press_button(BUTTON_B, 5, 5);
        pbf_wait(100);
        pbf_press_button(BUTTON_B, 5, 5);
        pbf_wait(100);
        pbf_press_button(BUTTON_B, 5, 5);
        pbf_wait(100);
        pbf_press_button(BUTTON_X, 5, 5);
        pbf_wait(100);
        pbf_press_dpad(DPAD_LEFT, 5, 5);
        pbf_wait(100);
        pbf_press_dpad(DPAD_UP, 500, 5);
        pbf_wait(100);
        pbf_press_button(BUTTON_B, 5, 5);
        resetFail = 0;
        }
    else {
        resetFail = resetFail + incConst;
    };

}
	//EXIT TO IDLE MODE (NEVER USED)
	pbf_press_button(BUTTON_HOME, 10, PokemonSwSh_GAME_TO_HOME_DELAY_SAFE);
	end_program_callback();
	end_program_loop();
};

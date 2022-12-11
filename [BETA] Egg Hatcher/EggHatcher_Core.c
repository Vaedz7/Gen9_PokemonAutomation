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
int switchEggs = 0
int swapRow = 1
int funcCheck = 0
int batches = 0

// START PROGRAM ON SWITCH
start_program_flash(CONNECT_CONTROLLER_DELAY);
grip_menu_connect_go_home();

// START GAME (BE SURE TO HAVE INSTRUCTIONS SET UP)
pbf_press_button(BUTTON_HOME, 10, PokemonSwSh_HOME_TO_GAME_DELAY);

while (true){
    // DELAY START
    pbf_wait(50);
    
    // RIDE LEGENDARY
    while ( funcCheck < 10 ) {
        pbf_move_left_joystick(0x80, 0x00, 250, 5);
        pbf_move_left_joystick(0x80, 0xff, 250, 5);
        funcCheck++;
    }
    funcCheck=5
    pbf_press_button(BUTTON_A, 5, 2500);
    pbf_press_button(BUTTON_A, 5, 750);
    
    switchEggs++;
    
    // SWITCH EGG BATCH
    if (switchEggs = 25) {
        funcCheck = 0
        batches++;
        
        // STOP IF BATCH_LIMIT IS REACHED
        if (batches = BATCH_LIMIT) {
            pbf_press_button(BUTTON_HOME, 10, PokemonSwSh_GAME_TO_HOME_DELAY_SAFE);
            end_program_callback();
            end_program_loop();
        };
        
        // NAVIGATE TO BOXES
        pbf_press_button(BUTTON_X, 5, 255);
        pbf_press_dpad(DPAD_RIGHT, 5, 105);
        pbf_press_dpad(DPAD_UP, 375, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_button(BUTTON_A, 5, 500);
        pbf_press_dpad(DPAD_LEFT, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        
        // SEND CURRENT BATCH TO BOXES
        pbf_press_button(BUTTON_MINUS, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_button(BUTTON_A, 5, 105);
        while ( funcCheck < swapRow ) {
            pbf_press_dpad(DPAD_RIGHT, 5, 105);
            funcCheck++;
        };
        funcCheck = 0;
        pbf_press_dpad(DPAD_UP, 5, 105);
        
        // GO TO DEPOSIT BOX
        while (funcCheck < DEPOSIT_BOX) {
            pbf_press_button(BUTTON_R, 5, 105);
            funcCheck++;
        };
        funcCheck = 0
        pbf_press_button(BUTTON_A, 5, 105);
        
        // RETURN TO EGG BOX
        while (funcCheck < DEPOSIT_BOX) {
            pbf_press_button(BUTTON_L, 5, 105);
            funcCheck++;
        };
        funcCheck = 0
        if (swapRow = 6) {
            pbf_press_button(BUTTON_R, 5, 105);
            pbf_press_dpad(DPAD_LEFT, 5, 105);
            pbf_press_dpad(DPAD_LEFT, 5, 105);
            pbf_press_dpad(DPAD_LEFT, 5, 105);
            pbf_press_dpad(DPAD_LEFT, 5, 105);
            pbf_press_dpad(DPAD_LEFT, 5, 105);
            swapRow = 1;
        };
        else {
            pbf_press_dpad(DPAD_RIGHT, 5, 105);
        };
        
        // FETCH NEW BATCH
        swapRow++;
        pbf_press_button(BUTTON_MINUS, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_button(BUTTON_A, 5, 105);
        while ( funcCheck < swapRow ) {
            pbf_press_dpad(DPAD_LEFT, 5, 105);
            funcCheck++;
        }
        funcCheck = 0;
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_button(BUTTON_A, 5, 105);
    }
    
}
    //EXIT TO IDLE MODE (NEVER USED)
    pbf_press_button(BUTTON_HOME, 10, PokemonSwSh_GAME_TO_HOME_DELAY_SAFE);
    end_program_callback();
    end_program_loop();
};


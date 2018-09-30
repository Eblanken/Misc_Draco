/*
 * File: Draco_Gui_Main.ino
 * ------------------------------
 * Author: Erick Blankenberg
 * Date:   8/12/2018
 *
 * Description:
 *  This is a GUI for my hyperfire mod dubbed the "Draco".
 */

//-------------------- Libraries and Submodules -----------------

#include "Fsm.h"
#include "Bounce2.h"
#include "Encoder.h"

//---------------- Constants and Global Variables ---------------

#define COLOR_FOREGROUND_LIGHT   0xf0fec9
#define COLOR_FOREGROUND_MEDIUM  0xa9da88
#define COLOR_FOREGROUND_LOW     0x62997a
#define COLOR_BACKGROUND_HIGH    0x72243c
#define COLOR_BACKGROUND_LOW     0x3b0819

#define FSM_TRANSITION_SINGLE    0 // Single button push
#define FSM_TRANSITION_UP        1 // Rotate clockwise
#define FSM_TRANSITION_DOWN      2 // Rotate counter-clockwise
Fsm     MenuMachine;

#define ENCDR_PIN_BUTTON
Bounce  Buttons()

#define ENCDR_PIN_1
#define ENCDR_PIN_2
Encoder EncrWheel(ENCDR_PIN_1, ENCDR_PIN_2)  

//--------------------------- Functions -------------------------

/*
 * Description:
 *  Sets up GUI state modules.
 */
void setup() {
  Serial.begin(9600);
  Main_Init();
  BatteryManager_Init();
  FireControl_Init();
  MagazineManager_Init();

}

/*
 * Description:
 *  The main program loop.
 */
void loop() {
  updateStats();
  checkPeripherals();
}

/*
 * Description:
 *  Sets up hardware used for the GUI
 */
void Main_Init() {
  
}

/*
 * Description:
 *  Keeps all of the icons at the top of the screen up to date
 *  and refreshes the current screen.
 */
void updateStats() {
  MenuMachine.run_machine();
}

/*
 * Description:
 *  Checks all UI hardware and acts on the FSM.
 */
void checkPeripherals() {
  // Updates encoder
  static long oldEncoderValue = 0;
  long newEncoderValue = EncrWheel.read();
  if(oldEncoderValue > newEncoderValue) {
    MenuMachine.
  } else if(oldEncoderValue < newEncoderValue){
    MenuMachine.
  }
  oldEncoderValue

  // Checks button
  Buttons.update();
  if(Buttons.rose()) {
    MenuMachine.
  }
}


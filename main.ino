//#include "Nextion.h"
#include "STD_TYPES.h"


#include "Button.h"
#include "display.h"
#include "Speed_Monitor.h"
#include "Direction.h"



void setup() {

  Speed_Monitor_voidInit();
  Direction_voidInit();
  KM_Counter_voidInit();
  Speed_Monitor_voidInit();
  Dispaly_voidInit();

}

void loop() {

    Display_voidUpdate();
    Speed_Monitor_voidUpdate();
    KM_Counter_voidUpdate();
    Direction_voidUpdate();

}

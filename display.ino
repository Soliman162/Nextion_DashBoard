
#include "STD_TYPES.h"
#include "display.h"

void Dispaly_voidInit(void)
{

  /*Board_1.Park_u8 = 0;
  Board_1.High_u8Light = 0;
  Board_1.Running_u8Light = 0;*/
  
  Serial.begin(9600);
}

void Display_voidUpdate(void)
{
  Serial.write('S');
  Serial.write(Board_1.Speed_u8Monitor);
  Serial.write('K');
  Serial.write( Board_1.KM_f32Counter);
  Serial.write('R');
  Serial.write( Board_1.Right_u8Sign);
  Serial.write('L');
  Serial.write( Board_1.Left_u8Sign);

  /*Serial.write( Board_1.High_u8Light);
  Serial.write(Board_1.Running_u8Light);

  Serial.write( Board_1.Park_u8);*/

  
  Serial.write('E');

}

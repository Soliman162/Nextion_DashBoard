#include "STD_TYPES.h"

#include "display.h"
#include "Speed_Monitor.h"

#define POT_PIN   A0 

void Speed_Monitor_voidInit(void)
{
  Board_1.Speed_u8Monitor = 0;

}
void Speed_Monitor_voidUpdate(void)
{
      Board_1.Speed_u8Monitor = Speed_Monitor_voidGet_Speed()  ;
}
u16 Speed_Monitor_voidGet_Speed(void)
{
      u16  Real_u16Speed = analogRead(POT_PIN); //measure_speed_kmph();
      //u64  Distance_u64KM = Real_u16Speed*2;// measure_distance_meter();
      return ( map( Real_u16Speed,0,10000,0,60));
}

#include "STD_TYPES.h"
#include "Button.h"
#include "display.h"
#include "KM_Counter.h"

f32 test = 2.2;

void KM_Counter_voidInit(void)
{

  Board_1.KM_f32Counter = 0;
}
void KM_Counter_voidUpdate(void)
{
  Board_1.KM_f32Counter = KM_Counter_u16GetKM();
}

u8 KM_Counter_u16GetKM(void)
{
  return(test+=1.2);
  
}

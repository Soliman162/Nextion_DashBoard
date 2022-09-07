#include "STD_TYPES.h"
#include "Button.h"

#define GET_PRESSED   HIGH

void Button_u8Init(u8 Copy_u8Button )
{
  pinMode( Copy_u8Button,INPUT );
}

u8 Get_u8Button_State( u8 Copy_u8Button )
{
  u8 LOC_Button_u8State = LOW ;
  if( digitalRead( Copy_u8Button ) == HIGH )
  {
    delay(50);
    if( digitalRead( Copy_u8Button ) == HIGH )
    {
      LOC_Button_u8State = HIGH;
    }
  }
  return LOC_Button_u8State;
}

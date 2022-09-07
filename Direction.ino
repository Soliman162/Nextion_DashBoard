#include "STD_TYPES.h"
#include "Button.h"
#include "display.h"
#include "Direction.h"

u8 State_u8Flag=1;
u8 Direction_u8ArrFlags[3] = {1};

u32 Direction_Millis = 0;
Direction_enumState Current_enumState ;

void Direction_voidInit(void)
{
    Board_1.Right_u8Sign = 0;
    Board_1.Left_u8Sign = 0;
    Current_enumState = OFF_State ;
    Direction_Millis = millis();
}
///////////////////////////////////////////////////////////////
void Direction_voidUpdate(void)
{
    CurrentState_voidUpdate();
    if( millis()- Direction_Millis >500 )
    {
          Direction_Millis = millis();
          switch (Current_enumState)
          {
            case OFF_State:
            {
              Right_Direction_voidSet_State(Sign_OFF);
              Left_Direction_voidSet_State(Sign_OFF);
              break; 
            }
            case Waiting_State:
            {
              if( State_u8Flag )
              {
                   Right_Direction_voidSet_State(Sign_ON);
                   Left_Direction_voidSet_State(Sign_ON);
                   State_u8Flag = 0;
              }else
              {
                   Right_Direction_voidSet_State(Sign_OFF);
                   Left_Direction_voidSet_State(Sign_OFF);
                   State_u8Flag = 1;
              }
              break;
            }
            case Right_Dir_State:
            {
              if( State_u8Flag )
              {
                     Right_Direction_voidSet_State(Sign_ON);
                     Left_Direction_voidSet_State(Sign_OFF);
                     State_u8Flag = 0;
              }else
              {
                     Right_Direction_voidSet_State(Sign_OFF);
                     Left_Direction_voidSet_State(Sign_OFF);
                     State_u8Flag = 1;
              }
              break;
            }
            case Left_Dir_State:
            {
              if( State_u8Flag )
              {
                    Right_Direction_voidSet_State(Sign_OFF);
                    Left_Direction_voidSet_State(Sign_ON);
                    State_u8Flag = 0;
              }else
              {
                    Right_Direction_voidSet_State(Sign_OFF);
                    Left_Direction_voidSet_State(Sign_OFF);
                    State_u8Flag = 1;
              }
              break;
            }
          }  
    }

  
}
///////////////////////////////////////////////////////////////
static void Right_Direction_voidSet_State(u8 Copy_u8State )
{
   Board_1.Right_u8Sign = Copy_u8State;
}
/////////////////////////////////////////////////////////////////
static void Left_Direction_voidSet_State(u8 Copy_u8State )
{
   Board_1.Left_u8Sign = Copy_u8State;
}
///////////////////////////////////////////////////////////////////
void CurrentState_voidUpdate(void)
{
  if( Get_u8Button_State( Waiting_I )== GET_PRESSED )
  {
    if( Direction_u8ArrFlags[Waiting_Flag] )
    {
          Current_enumState = Waiting_State;
          Direction_u8ArrFlags[Waiting_Flag] = 0;
          Direction_u8ArrFlags[Right_Dir_Flag] = 1;
          Direction_u8ArrFlags[Left_Dir_Flag] = 1;
    }else
    {
      Current_enumState = OFF_State;
      Direction_u8ArrFlags[Waiting_Flag] = 1;
    }
  }else if( Get_u8Button_State( Right_I )== GET_PRESSED )
  {
    if( Current_enumState != Waiting_State )
    {
          if( Direction_u8ArrFlags[Right_Dir_Flag] )
          {
               Current_enumState = Right_Dir_State;
               Direction_u8ArrFlags[Right_Dir_Flag] = 0;
               
               Direction_u8ArrFlags[Left_Dir_Flag] = 1;
               Direction_u8ArrFlags[Waiting_Flag] = 1;
          }
          else
          {
               Current_enumState = OFF_State;
               Direction_u8ArrFlags[Right_Dir_Flag] = 1;
          }
    }

  }else if( Get_u8Button_State( Left_I )== GET_PRESSED )
  {
    if( Current_enumState != Waiting_State )
    {
          if( Direction_u8ArrFlags[Left_Dir_Flag] )
          {
                Current_enumState = Left_Dir_State;
                Direction_u8ArrFlags[Left_Dir_Flag] = 0;
                Direction_u8ArrFlags[Waiting_Flag] = 1;
                Direction_u8ArrFlags[Right_Dir_Flag] = 1;
          }else
          {
                Current_enumState = OFF_State;
                Direction_u8ArrFlags[Left_Dir_Flag] = 1;
          }
    }
  }
}

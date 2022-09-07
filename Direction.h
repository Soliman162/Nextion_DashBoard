#ifndef DIRECTION_H
#define DIRECTION_H


#define Sign_ON     1
#define Sign_OFF    0

#define Waiting_Flag      0
#define Right_Dir_Flag    1
#define Left_Dir_Flag     2


typedef enum{

  OFF_State=0,
  Waiting_State,
  Right_Dir_State,
  Left_Dir_State
  
}Direction_enumState;

void Direction_voidInit(void);
void Direction_voidUpdate(void);
static void Right_Direction_voidSet_State(u8 Copy_u8State );
static void Left_Direction_voidSet_State(u8 Copy_u8State );
void CurrentState_voidUpdate(void);



#endif

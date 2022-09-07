#ifndef DISPLAY_H
#define DISPLAY_H

#define   BAUD_RATE   9600

typedef struct{

  u8 Speed_u8Monitor;
  u8 KM_f32Counter;
  u8 Right_u8Sign;
  u8 Left_u8Sign;
 /* u8 Park_u8;
  u8 High_u8Light;
  u8 Running_u8Light;*/
  
 }Dash_Board; 

 Dash_Board Board_1;

void Dispaly_voidInit(void);
void Display_voidUpdate(void);


#endif

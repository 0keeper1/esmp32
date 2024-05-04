#include <Arduino.h>

void menuSelector();
void drawMenu(); // TODO

// btns
#define BTN_K1 23
#define BTN_K2 22

// vars
int upBtnState;
int downBtnState;

typedef enum Menu { WELCOME, SELECT, PLAYER, VOLUME  } Menu;

// Menu
#define MENU_DELAY 330
Menu menuState = WELCOME;

void setup()
{
  Serial.begin(9600);


  pinMode(BTN_K1, INPUT_PULLUP);
  pinMode(BTN_K2, INPUT_PULLUP);
}

void loop()
{
  menuSelector();
}


void menuSelector()
{
  upBtnState = digitalRead(BTN_K2);
  downBtnState = digitalRead(BTN_K1);
  if (upBtnState == LOW)
  {
    if (menuState == WELCOME)
    {
      menuState = SELECT;
    } 
    else if (menuState == SELECT)
    {
      menuState = PLAYER;
    }
    else if (menuState == PLAYER)
    {
      menuState = VOLUME;
    } 
    Serial.printf("UP | State: %d\n", menuState);
    delay(MENU_DELAY);
  } else if (downBtnState == LOW)
  {
    if (menuState == VOLUME)
    {
      menuState = PLAYER;
    } 
    else if (menuState == PLAYER)
    {
      menuState = SELECT;
    }
    Serial.printf("DOWN | State: %d\n", menuState);
    delay(MENU_DELAY);
  }
}

void drawMenu()
{
}
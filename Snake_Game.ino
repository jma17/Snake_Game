/*
  MeggyJr_Blink.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

int marker = 3;
int xapple = random(8);
int yapple = random(8);
int dir = 0;

int i = 0;// posible values are 0,90,180,270

struct Point
{
  int x;
  int y;
};
Point p1 = {3,4};
Point p2 = {4,4};
Point p3 = {5,4};
Point p4 = {6,4};

Point snakeArray[64] = {p1,p2,p3,p4};



void drawSnake()
{
  for(int i=0; i<marker; i++)
    {
      DrawPx(snakeArray[i].x, snakeArray[i].y, Red);
    }
}    

void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void updateSnake()
{
  for(int i = marker - 1; i > 0; i--)
  {
    snakeArray[i] = snakeArray[i - 1];
  }
}


void loop()                     // run over and over again
/*
  Draw player
  Display slate
  Delay
  Check buttons
  update direction if a button is pressed
  update player based on direction
  Correct for wrap
*/

{
  Serial.print("X is");
  Serial.println(snakeArray[0].x);
  Serial.print("Y is");
  Serial.println(snakeArray[0].y);
  Serial.println();
  
  
  drawSnake();
  DrawPx(snakeArray[0].x, snakeArray[0].y, Orange);
  DisplaySlate();
  delay(150);
  ClearSlate();
  updateSnake();
  DrawPx(xapple,yapple,Green);
  
  CheckButtonsPress();
  if (Button_Right)
  {
    dir = 90;
  }
  if(dir==0)
  {
    snakeArray[0].y ++;
  }  
  if (Button_Left)
  {
    dir = 270;
  }
  if(dir==90)
  {
    snakeArray[0].x ++;
  }  
  if (Button_Up)
  {
    dir = 0;
  }
  if(dir==180)
  {
    snakeArray[0].y --;
  }  
  
  if (Button_Down)
  {
    dir = 180;
  }
  if(dir==270)
  {
    snakeArray[0].x --;
  }  
  if(snakeArray[0].x > 7)
  {
    snakeArray[0].x = 0;
  }  
  if(snakeArray[0].y > 7)
  {
    snakeArray[0].y = 0;
  }   
  if(snakeArray[0].x < 0)
  {
    snakeArray[0].x = 7;
  }  
  if(snakeArray[0].y < 0)
  {
    snakeArray[0].y = 7;
  } 
  if (xapple == snakeArray[0].x)
  {
    if(yapple == snakeArray[0].y)
    {
       xapple = random(8);
       yapple = random(8);
       marker ++;
       Tone_Start(4000, 50);
       
    }
  }  
}

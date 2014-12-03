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
int xplayer = 3;              //coordinates of player dot
int yplayer = 4;
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
Point p2 = {4,3};
Point p3 = {5,4};

Point snakeArray [64] = {p1,p2,p3};

void drawsnake()
{
  for(int i=0; i<marker; i++);
    {
      DrawPx(snakeArray [i].x, snakeArray [i].y, Red);
    }
}    

void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
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
  Serial.println(xplayer);
  Serial.print("Y is");
  Serial.println(yplayer);
  Serial.println();
  
  DrawPx(xplayer,yplayer,Red);
  DrawPx(xapple,yapple,Green);
  DisplaySlate();
  delay(300);
  ClearSlate();
  CheckButtonsPress();
  if (Button_Right)
  {
    dir = 90;
  }
  if(dir==0)
    {
      yplayer ++;
    }  
  if (Button_Left)
  {
    dir = 270;
  }
  if(dir==90)
    {
      xplayer ++;
    }  
  if (Button_Up)
  {
    dir = 0;
  }
  if(dir==180)
    {
      yplayer --;
    }  
  
  if (Button_Down)
  {
    dir = 180;
  }
  if(dir==270)
    {
      xplayer --;
    }  
  if(xplayer > 7)
    {
      xplayer=0;
    }  
  if(yplayer > 7)
    {
      yplayer=0;
    }   
  if(xplayer < 0)
    {
      xplayer=7;
    }  
  if(yplayer < 0)
    {
      yplayer=0;
    } 
  if (xapple==xplayer)
    {
      if(yapple==yplayer)
        {
          xapple = random(8);
          yapple = random(8);
        }
    }
    
 
    
}

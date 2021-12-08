/*
Zarpli - Tecnología Interactiva
02122021 Alejandro Zárate
https://github.com/zarpli/CFSound/

DESCRIPTION
====================
  
Example of the CFSound library that play cyclically a series of eight 
audios 1.wav, 2.wav ... 8.wav, waiting for each one to finish.

LCD 16x2 is Optional and requires the library:
https://github.com/arduino-libraries/LiquidCrystal
  
The CFSuControl Script must be installed in the CFSound unit 
memory unit and must be connected to the Serial1 port.  
https://github.com/zarpli/CFSuControl/

Media Files for Testing
https://github.com/zarpli/Media/
*/

#include <CFSound.h>
#include <LiquidCrystal.h>

// Instantiate a CFSound object and Attach to Serial1
CFSound CFS(Serial1);

// Instantiate a LiquidCrystal object.
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

unsigned char current_track = 1;

void setup(){

CFS.debug();          // Enable debug msg over Serial

lcd.begin(16, 2);
lcd.print("CFSuControl");
lcd.setCursor(0,1);
lcd.print("Waiting Power-UP");

Serial.begin(9600);
while(!Serial);

Serial.println("Waiting CFSound Power-Up");
while(!CFS.online())CFS.update(); 

lcd.clear();
lcd.print("CFSuControl");

CFS.volume(50);       //Set Volume to 50%
delay(2);             //In some versions of CF Sound units is need a time between commands.
}

void loop(){
CFS.update();        // Update the CFSound instance

if(CFS.media_ended()){
  CFS.play((String)current_track + ".wav");
  lcd.setCursor(0,1);
  lcd.print("PLAY " + (String)current_track + ".wav");
  Serial.println("PLAY " + (String)current_track + ".wav");
 
  current_track ++;
  if(current_track == 9)current_track = 1;
  }
}

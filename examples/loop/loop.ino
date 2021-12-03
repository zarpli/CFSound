/*
Zarpli - Tecnología Interactiva
12112021 Alejandro Zárate
https://github.com/zarpli/CFSound/

DESCRIPTION
====================
  
Simple example of the CFSound library that play a media file 
and wait for it to finish to run again.
  
The CFSuControl Script must be installed in the CFSound unit 
memory unit and must be connected to the Serial1 port.  

https://github.com/zarpli/CFSuControl/

Media Files for Testing
https://github.com/zarpli/Media/
*/

#include <CFSound.h>

// Instantiate a CFSound object and Attach to Serial1
CFSound CFS(Serial1);   

void setup(){

// Enable debug msg over Serial
CFS.debug();   

Serial.begin(9600);
while(!Serial);

Serial.println("Waiting CFSound Power-Up");
while(!CFS.online())CFS.update();

//Set Volume to 50% 
CFS.volume(50);            
}

void loop(){
// Update the CFSound instance
CFS.update();
if(CFS.media_ended()) CFS.play("audio.wav");
}

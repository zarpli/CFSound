# CFSound

CFSound audio players can send and receive commands over serial using a custom script.

This Arduino Library is for use with [CFSuControl](https://github.com/zarpli/CFSuControl) Script

# Installation & Download

Download the latest version [here](https://github.com/zarpli/CFSound/archive/refs/heads/main.zip) and put the "CFSound" folder in your "libraries" folder.

# Basic Usage
```C++
CFSound CFS(Serial1)
```
Instantiate a CFSound object and attach to Serial1, You may create multiple CFSound objects.

```C++
CFS.update()
```
Read the CFSound and update its status. This update() function must be called regularly.

```C++
CFS.debug()  
```
Enable debug messages on serial port :

|Debug Messages|Description|
|---|---|
|CFS : online|The unit starts up and has the script installed|
|CFS : media_ended|A file has finished playing|

```C++
CFS.play("audio.wav")
```
Play audio file called "audio.wav" in root directory.

```C++
CFS.volume(INT)
```
Set the volume to INT percent of normal.

```C++
CFS.stop()
```
Stop the currently playing media.

```C++
CFS.ptt(INT)
```
0 : Disable built-in PTT Relay <br>
1 : Enable built-in PTT Relay

```C++
boolean CFS.online()
```
return TRUE when the unit starts up and has the script installed.

```C++
boolean CFS.media_ended()
```
return TRUE when a media file has finished playing.

# Loop Example

Simple example of the CFSound library that play a audio file "audio.wav" and wait for it to finish to run again.
  
The CFSuControl Script must be installed in the CFSound unit memory unit and must be connected to the Serial1 port of the arduino board.  

```C++
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
```
# Media Files for Testing

[Media](https://github.com/zarpli/Media)

# YouTube

<a href="http://www.youtube.com/watch?feature=player_embedded&v=j8EwE3pnMcg" target="_blank"><img src="http://img.youtube.com/vi/j8EwE3pnMcg/0.jpg" alt="YouTube" width="400" border="10"/></a>

#include "Arduino.h"

#define BAUD_RATE     115200
#define STX           0x02
#define ETX           0x03

#define ONLINE        0x02
#define MEDIA_ENDED   0x08

#define	MAX_VOL		  63		// db linear in sixty-four, 1db increments from  -66db (0) → 0db (63) 

class CFSound
{
public:
CFSound(HardwareSerial &serial);
void    play(String file);
void    volume(int percentage);
void    ptt(int state);
void    stop();
void    update();
void    debug()               {cfs_debug = true;}
boolean online()              {return cfs_online;}
boolean media_ended()         {return cfs_media_ended;}

private:
HardwareSerial* cfs_serial;
boolean cfs_online = false;
boolean cfs_media_ended = true;
boolean cfs_debug = false;
};
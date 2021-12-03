#include "CFSound.h"

CFSound::CFSound(HardwareSerial &serial) {
    cfs_serial = &serial;
    cfs_serial->begin(BAUD_RATE);
}

void CFSound::update(){

    if (cfs_serial->available()>2)
    {
          if (cfs_serial->read() != STX) return;
          byte cmd = cfs_serial->read(); 
          if (cfs_serial->read() == ETX)
          {
            if(cmd == ONLINE) {
                if(cfs_debug) Serial.println("CFS : online"); 
                cfs_online = true;
            }
            if(cmd == MEDIA_ENDED) {
                if(cfs_debug) Serial.println("CFS : media_ended");
                cfs_media_ended = true;
            }
          }
    }   
}

void CFSound::play(String file){
cfs_serial->write(STX);
cfs_serial->print("PLAY " + file);
cfs_serial->write(ETX);
cfs_media_ended = false;
}

void CFSound::volume(int percentage){
percentage = map(percentage, 0, 100, 0, MAX_VOL);
cfs_serial->write(STX);
cfs_serial->print("VOLUME " + (String)percentage);
cfs_serial->write(ETX);
}

void CFSound::ptt(int state){
cfs_serial->write(STX);
cfs_serial->print("PTT " + (String)state);
cfs_serial->write(ETX);
}

void CFSound::stop(){
cfs_serial->write(STX);
cfs_serial->print("STOP");
cfs_serial->write(ETX);
}
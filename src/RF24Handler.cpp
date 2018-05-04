#include "RF24Handler.h"

inline RF24Handler::RF24Handler(RF24* radio)
{
    this->address = DEFAULT_NETWORK_ADDRESS;
    
    /*
  radio.begin();
  radio.setAutoAck(false);
  radio.setRetries(0,0);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_2MBPS);
  radio.openReadingPipe(1,pipes[1]);
  radio.openWritingPipe(pipes[0]);
    */
}

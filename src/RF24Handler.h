#ifndef _RF24Handler_h
#define _RF24Handler_h

/*
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
*/
#include "Pack.h"
#include  "ParamsHandler.h"

class RF24;

class RF24Handler
{
    public:
    
    inline RF24Handler(RF24* radio);
    inline RF24Handler(NetworkAddress myAddress);
    PipelineAddress ReceivePack(byte*);
    bool SendPack(NetworkAddress, const byte*);
    
    inline const NetworkAddress GetAddress() const
    {
        return (this->address);
    }
    
    inline void SetAddress(NetworkAddress address)
    {
        this->address = address;
    }
    
    inline const PipelineAddress GetPipeline() const
    {
        return (this->myPipe);
    }
    
    inline void SetPipeline(PipelineAddress pipeline)
    {
        this->myPipe = pipeline;
    }
    
    inline bool Ready()
    {
        return address != DEFAULT_NETWORK_ADDRESS && myPipe != DEFAULT_PIPELINE_ADDRESS;
    }
    
    protected:
    RF24* radio;
    NetworkAddress address;
    PipelineAddress myPipe;
    PipelineAddress broadcastPipe;
    PipelineAddress pipes[4];
};

#endif
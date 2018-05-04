#ifndef _ParamsHandler_h
#define _ParamsHandler_h

//--------------------------PROCESS HANDLER PARAMS------------------------------
#define MAX_PRIORITY_VALUE  99
#define MIN_PRIORITY_VALUE  0

#define MAX_BUSY_VALUE 99
#define MIN_BUSY_VALUE 0

#define BUSY_VALUE_TO_SLEEP 50
//-------------------------------PACK PARAMS------------------------------------
typedef char byte;

#pragma pack(push)
#pragma pack(1)
typedef struct _controlHeader
{
    int ID : 8;
    int timeToLive : 6;
    
    int sourceAddress : 9;
    int destinyAddress : 9;
    
}ControlHeader;
#pragma pack(pop)

typedef struct _voiceHeader
{
    char IDFluxo;
    
}VoiceHeader;

#define PACK_SIZE 32

//--------------------------NETWORK HANDLER PARAMS------------------------------
typedef int NetworkAddress;
typedef unsigned long int PipelineAddress;

#define DEFAULT_NETWORK_ADDRESS 0
#define PORTER_ADDRESS 1
#define BROADCAST_ADDRESS 255

#define DEFAULT_PIPELINE_ADDRESS 0xF0F0F0F0F0

//------------------------------------------------------------------------------
#endif
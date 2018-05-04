#ifndef _IProcess_h
#define _IProcess_h

#include "ProcessHandler.h"
#include "ParamsHandler.h"

class ProcessHandler;

class IProcess
{
    public:
    
    IProcess(ProcessHandler* owner, int minPriority, int maxPriority, bool persistent)
    {
        this->owner = owner;
        this->minPriority = minPriority;
        this->maxPriority = maxPriority;
        this->priority = maxPriority;
        this->persistent = persistent;
    }
    
    //Retorna a prioridade do processo
    virtual int GetPriority(int) = 0;
    
    //Executa o processo
    virtual int Execute() = 0;
    
    //Retorna caso o processo seja persistente
    inline bool Persistent()
    {
        return this->persistent;
    }
    
    protected:
    bool persistent;
    int minPriority;
    int maxPriority;
    int priority;
    int busyLvl;
    ProcessHandler* owner;
    
    inline void SetPriority(int value)
    {
        if (value > maxPriority)
            priority = maxPriority;
        else if (value < minPriority)
            priority = minPriority;
        else
            priority = value;
    }

    inline void SetBusyLvl(int value)
    {
        if (value > busyLvl)
            busyLvl = MAX_BUSY_VALUE;
        else if (value < MIN_BUSY_VALUE)
            busyLvl = MIN_BUSY_VALUE;
        else
            busyLvl = value;
    }
};

#endif
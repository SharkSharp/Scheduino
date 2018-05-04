#ifndef _SleepProcess_h
#define _SleepProcess_h

#include "IProcess.h"

class SleepProcess : public IProcess
{
    public:
    SleepProcess(ProcessHandler*, bool);
    int GetPriority(int);
    int Execute();
    inline bool Persistent();
    
    private:
    int sleepTime;
    int averageBackUp;
};

#endif
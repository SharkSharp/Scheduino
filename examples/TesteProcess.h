#ifndef _TesteProcess_h
#define _TesteProcess_h

#include "IProcess.h"

class TesteProcess : public IProcess
{
    public:
    TesteProcess(ProcessHandler*, int, int, bool, char*);
    int GetPriority(int);
    int Execute();
    inline bool Persistent();
    
    private:
    char* message;
    int count;
    int sleepCount;
    int reboot;
};

#endif
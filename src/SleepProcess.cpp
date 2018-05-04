#include "SleepProcess.h"

SleepProcess::SleepProcess(ProcessHandler* owner, bool persistent) 
: IProcess(owner, 0, 0, persistent)
{
    this->sleepTime = 1;
    this->persistent = persistent;
}

int SleepProcess::GetPriority(int averageBusyLvl)
{
    this->averageBackUp = averageBusyLvl;
    this->sleepTime = 99 - averageBusyLvl;
    return priority;
}

int SleepProcess::Execute()
{
    printf("Dormi %dms\n", sleepTime);
    return this->averageBackUp;
}
#include "TesteProcess.h"

TesteProcess::TesteProcess(ProcessHandler* owner, int minPriority, int maxPriority, bool persistent, char* message) 
: IProcess(owner, minPriority, maxPriority, persistent)
{
    this->message = message;
    this->busyLvl = 99;
    this->count = 0;
    this->sleepCount = 99;
    this->reboot = 0;
}

int TesteProcess::GetPriority(int totalPrice)
{
    if(count < 99)
    {
        count++;
    }
    else if(sleepCount > 0)
    {
        sleepCount -= 1;
        
        if(sleepCount == 1 && reboot == 0)
        {
            count = 0;
            sleepCount = 99;
            reboot = 1;
        }
    }
    return priority;
}

int TesteProcess::Execute()
{
    printf("%s\n", this->message);
    return (count < 99) ? 99 : sleepCount;
    this->owner->
}
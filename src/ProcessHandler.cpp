#include "ProcessHandler.h"

ProcessHandler::ProcessHandler(int maxProcess)
{
    this->processHeap = new MaxHeap<IProcess>(maxProcess);
    this->averageBusyLvl = MAX_BUSY_VALUE;
}

void ProcessHandler::AddProcess(IProcess* newProcess)
{
    this->processHeap->Add(newProcess->GetPriority(MAX_BUSY_VALUE), newProcess);
}

void ProcessHandler::Execute()
{
    while(this->processHeap->GetTam() > 0)
    {
        IProcess* atualProcess = this->processHeap->Peek();
        
        int processBusyLvl = atualProcess->Execute();
        
        if(atualProcess->Persistent())
        {
            int atualPriority = atualProcess->GetPriority(this->averageBusyLvl);
            this->processHeap->RaiseIndexs((averageBusyLvl <= BUSY_VALUE_TO_SLEEP) ? 1 : 0);
            this->processHeap->Add(atualPriority, atualProcess);   
        }
        
        if(processBusyLvl == MAX_BUSY_VALUE)
        {
            this->averageBusyLvl = MAX_BUSY_VALUE;
        }
        else
        {
            this->averageBusyLvl = (processBusyLvl + this->averageBusyLvl) >> 2;
        }
        
        //Código de teste. REMOVER!
        if(this->averageBusyLvl == 0)
            break;
    }
}
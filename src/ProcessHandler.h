#ifndef _ProcessHandler_h
#define _ProcessHandler_h

#include "MaxHeap.h"
#include "IProcess.h"
#include "ParamsHandler.h"

//Classe abstrata para derivação de novos processos
class IProcess;

//Gerenciador e escalonador de Processos
class ProcessHandler
{
    public:
    ProcessHandler(int maxProcess);
    
    //Adiciona um novo processo a Heap do escalonador
    void AddProcess(IProcess*);
    
    //Inicia a execução do escalonador de processos
    void Execute();
    
    
    private:
    int averageBusyLvl;
    MaxHeap<IProcess>* processHeap;
};

#endif
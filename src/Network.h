#ifndef __Network_h
#define __Network_h

#include "Pack.h"



typedef struct Node
{
    char num;
    Node *vizinhos;
}node;


typedef struct Flow
{
    node *flow_nodes;
}flow;

class Network
{
    
    public:
        
        //Constructor
        Network()
        {
            
        }
        
        
        //Destructor
        ~Network()
        {
            
            
        }
    
        //methods
        flow* buildFlow(node*, node*);      // constrói um fluxo entre 2 nodes
        bool destroyFlow(flow&);            // destrói um fluxo entre 2 nodes
        bool route(flow*/*, Pack&*/);       // dado um fluxo, envia as mensagens para o próximo node
        int auth(node *);                         // porteiro autentica um novo node
        bool controlPacket();               // pacotes de controle
        void syncNodes();                   // sincronizar os nodes, tempo de enviar e receber
        bool beginConv(node *, node*);                   // inicia uma conversa (monta o fluxo e faz a comunicação)
        bool endConv();                     // termina uma conversa (destrói o fluxo e termina a comunicação)
        node *getNodeList();                // getter
        void setNodeList();                 // setter
        
    
    private:
        
        node *node_list;
    
    
};


























#endif
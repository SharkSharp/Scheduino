#ifndef _MaxHeap_h
#define _MaxHeap_h

#include "HNode.h"

template<typename THeap>
class MaxHeap
{
	public:
	
		MaxHeap(int tam)
		{
			this->tam = 0;
			this->tamMax = tam;
			this->nodes = new HNode<THeap>[tam];
		}
		
		void Add(int index, THeap* value)
		{
			if(this->tam < this->tamMax)
			{
				this->nodes[this->tam].index = index;
				this->nodes[this->tam].value = value;
				Sobe(this->tam);
				this->tam++;	
			}
		}
		
		THeap* Peek()
		{
			if(this->tam > 0)
			{
				THeap* retorno;
				retorno = this->nodes[0].value;
				
				this->nodes[0].value = 0;
				
				Swap(0, (this->tam - 1));
				this->tam--;
			
				Desce(0);
				return retorno;	
			}
			else
			{
				return 0;
			}
		}
		
		void RaiseIndexs(int value)
		{
			for (int i = 0; i < this->tam; i++) 
			{
				this->nodes[i].index = (this->nodes[i].index << 1) + value;
			}
		}
		
		inline int GetTam()
		{
			return this->tam;
		}
		
	private:
		int tam;
		int tamMax;
		HNode<THeap>* nodes;
		
		inline int FilhoEsquerdo(int node)
		{
			return (2 * node) + 1;
		}
		
		inline int FilhoDireito(int node)
		{
			return (2 * node) + 2;
		}
		
		inline int Pai(int node)
		{
			return (node - 1) / 2;
		}
		
		void Desce(int node)
		{
			int f1, f2, aux;
			f1 = FilhoEsquerdo(node);
			f2 = FilhoDireito(node);
		
			if (f2 < this -> tam)
			{
				aux = (this->nodes[f1].index > this->nodes[f2].index) ? f1 : f2;
			 	if (this->nodes[aux].index > this->nodes[node].index)
				{
					Swap(node, aux);
					Desce(aux);
				}
			}
			else
			{
				if (f1 < this->tam)
				{
					if (this->nodes[f1].index > this->nodes[node].index)
					{
				 		Swap(node, f1);
						Desce(f1);
					}
				}
			}
		}

		void Sobe(int node)
		{
			if (node != 0)
			{
				double vn, vp;
				vn = this->nodes[node].index;
				vp = this->nodes[Pai(node)].index;
				if (vn > vp)
				{
					Swap(node, Pai(node));
					Sobe(Pai(node));
				}
			}
		}
		
		inline void Swap(int node1, int node2)
		{
			HNode<THeap> aux;
			aux = this->nodes[node1];
			this->nodes[node1] = this->nodes[node2];
			this->nodes[node2] = aux;
		}	
};

#endif
#include "Grafo.h"

Grafo::Grafo(){

}

Grafo::Grafo(Set){
}


void Grafo::setSet(Set _set)
{

	set = _set;
	int tam = set.getSeq_V().value_v.size();
	adj = new list<int>[tam];
}

Set Grafo::getSet()
{
	return set;
}

int Grafo::degree(int _vertice)
{
	int degreeValue = 0;

	for (auto it : set.getSeq_E().value_e) {
		if (it.v1 == _vertice )
			degreeValue++;
		if (it.v2 == _vertice && it.v1 != _vertice)
			degreeValue++;
	}
	return degreeValue;
}

void Grafo::addEdge(){
	for (auto it: set.getSeq_E().value_e)
	{
		adj[it.v1].push_back(it.v2);

		adj[it.v2].push_back(it.v1);
	}
}

void Grafo::MayorMenor()
{
	int aux=0;
	for (auto it : set.getSeq_V().value_v) {
		aux= degree(it.v);

		if (min == -1 || min > aux)
		{
			min = aux;
		}

		if (max == -1 || max < aux) {
			max = aux;
		}
	}
}

bool Grafo::TieneCiclosUtil(int v, bool visitado[], int padre) {
	
	visitado[v] = true;

	list<int>::iterator i;
	
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if (!visitado[*i])
		{
			if (TieneCiclosUtil(*i, visitado, v))
				return true;
		}

		else if (*i != padre)
			return true;
	}
	return false;
}

bool Grafo::TieneCiclos()
{
	int tam = set.getSeq_V().value_v.size();
	bool* visitado = new bool[tam];
	for (int i = 0; i < tam; i++)
		visitado[i] = false;

	for (int u = 0; u < tam; u++)
	{
		if (!visitado[u])
			if (TieneCiclosUtil(u, visitado, -1))
				return true;
	}
	return false;
}

void Grafo::printGrafo()
{
		
}

void Grafo::etiquetarGrafo()
{
}

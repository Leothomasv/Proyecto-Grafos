#include "Grafo.h"

Grafo::Grafo()
{
}

Grafo::Grafo(Set)
{
}

void Grafo::setSet(Set _set)
{
	set = _set;
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

void Grafo::printGrafo()
{
		
}

void Grafo::etiquetarGrafo()
{
}

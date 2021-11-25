#pragma once
#ifndef GRAFO_H
#define GRAFO_H

#include "Set.h"
#include <iostream>
#include <list>
class Grafo {
public:
    Grafo();
    Grafo(Set);
    Set set;

    int min =-1;
    int max=-1;
    
    list<int>* adj;
    list<int> camino;

    void addEdge();

    void setSet(Set);
    Set getSet();


    int degree(int);
    void MayorMenor();
    bool EncontrarCamino(int, int);
    bool encontrarCaminoBIEN(int , int, vector<bool>&, vector<int>&);
    bool TieneCiclosUtil(int v,bool visitado[], int padre);
    bool TieneCiclos();
};
#endif // !GAFO_H

//hecho por bradley 



#pragma once
#ifndef GRAFO_H
#define GRAFO_H

#include "Set.h"
#include <iostream>
class Grafo {
public:
    Grafo();
    Grafo(Set);
    Set set;
    
    void setSet(Set);
    Set getSet();

    void printGrafo();
    void etiquetarGrafo();
};
#endif // !GAFO_H

//hecho por bradley 



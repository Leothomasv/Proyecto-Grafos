#pragma once
#include "SFML/Graphics.hpp";

class Vertice : public sf::CircleShape {
public:
    Vertice(float radio) {
        setRadius(radio);
    };
    int vertice = 0;
};

#include "SFML/Graphics.hpp";
#include "Grafo.h"

class Vertice : public sf::CircleShape {
    public:
        Vertice(float radio) {
            setRadius(radio);
        };
        int vertice = 0;
};

int main()
{
    Grafo grafo;
    V vertex1(1);
    V vertex2(2);
    V vertex3(3);
    V vertex4(4);
    E e(1,2,3);
    E e2(2, 3, 4);
    E e3(4, 2, 5);
    vector<V> vertices = { vertex1, vertex2, vertex3, vertex4 };
    vector<E> aristas = { e, e2, e3 };
    SeqV seqV(vertices);
    SeqE seqE(aristas);
    Set set;
    set.setSeq_V(seqV);
    set.setSeq_E(seqE);
    grafo.setSet(set);
    
    sf::RenderWindow window(sf::VideoMode(1080, 780), "SFML works!");
    sf::CircleShape shape1(100.f);
    sf::CircleShape shape2(100.f);

    float pos_x = 10;
    float pos_y = 20;

    vector<Vertice> allVertices;

    for(auto it : grafo.getSet().getSeq_V().value_v)
    {
        Vertice v1(100.f);
        v1.vertice = it.v;
        allVertices.push_back(v1);
    }

    for (auto &it : allVertices) {
        it.setFillColor(sf::Color::Magenta);
        it.setPosition(pos_x, pos_y);
        pos_x += 300;
        if (pos_x > 900)
        {
            pos_x = 10;
            pos_y += 250;
        }
    }

    shape1.setFillColor(sf::Color::Cyan);
    shape2.setFillColor(sf::Color::Green);
  
    //shape1.setPosition(10, 20);
    //shape2.setPosition(800, 100);

    sf::Vertex linea[100] = {};
    int positionLinea = 0;

    for (auto it : grafo.getSet().getSeq_E().value_e) {
        float ver1_x = 0;
        float ver1_y = 0;
        float ver2_x = 0;
        float ver2_y = 0;
        for (auto& itV : allVertices) {
            if (it.v1 == itV.vertice)
            {
                ver1_x = itV.getPosition().x;
                ver1_y = itV.getPosition().y;
            }
        }
        for (auto& itV : allVertices) {
            if (it.v2 == itV.vertice)
            {
                ver2_x = itV.getPosition().x;
                ver2_y = itV.getPosition().y;
            }
        }
        int conteo = 0;
        while (conteo != 2)
        {
            linea[positionLinea] = sf::Vertex(sf::Vector2f(ver1_x + 100, ver1_y + 100));
            positionLinea++;
            linea[positionLinea] = sf::Vertex(sf::Vector2f(ver2_x + 100, ver2_y + 100));
            positionLinea++;
            conteo++;
        }
    }

    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(shape1.getPosition().x + 100, shape1.getPosition().y + 100)),
        sf::Vertex(sf::Vector2f(shape2.getPosition().x + 100, shape2.getPosition().y + 100)),
        sf::Vertex(sf::Vector2f(shape1.getPosition().x + 101, shape1.getPosition().y + 101)),
        sf::Vertex(sf::Vector2f(shape2.getPosition().x + 101, shape2.getPosition().y + 101)),
        sf::Vertex(sf::Vector2f(shape1.getPosition().x + 99, shape1.getPosition().y + 99)),
        sf::Vertex(sf::Vector2f(shape2.getPosition().x + 99, shape2.getPosition().y + 99))
    };

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
      
    
        //window.draw(shape1);
        //window.draw(shape2);
        window.draw(linea, 100, sf::Lines);
        for (auto it : allVertices) {
            window.draw(it);
        }
        
        //window.draw(line, 6, sf::Lines);
    



        window.display();
    }


    return 0;
}
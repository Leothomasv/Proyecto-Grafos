
#include "Circle.h"
#include "Grafo.h"

using namespace sf;
#define MAX_ELEMENTS 100

int main()
{
    Grafo grafo;
    V vertex1(1);
    V vertex2(2);
    V vertex3(3);
    V vertex4(4);
    V vertex5(5);
    V vertex6(6);
    V vertex7(7);
    V vertex8(8);
    V vertex9(9);
    V vertex10(10);
    E e(1, 2, 3);
    E e4(1, 4, 5);
    E e2(2, 3, 4);
    E e3(4, 2, 5);
    E e5(5, 3, 5);
    E e6(4, 5, 5);
    E e7(8, 9, 5);
    E e8(7, 4, 5);
    E e9(10, 1, 5);
    E e10(2, 8, 5);
    vector<V> vertices = { vertex1, vertex2, vertex3, vertex4, vertex5,vertex6,vertex7,vertex8,vertex9,vertex10 };
    vector<E> aristas = { e, e2, e3, e4, e5, e6, e7, e8, e9 ,  e10 };
    SeqV seqV(vertices);
    SeqE seqE(aristas);
    Set set;
    set.setSeq_V(seqV);
    set.setSeq_E(seqE);
    grafo.setSet(set);
    

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

    float pos_x = 10;
    float pos_y = 20;

    vector<Vertice> allVertices;
    RectangleShape rectangle;

    rectangle.setPosition(1620, 0);
    rectangle.setSize(sf::Vector2f(300, 1080));
    rectangle.setFillColor(sf::Color(8, 41, 55));

    for(auto it : grafo.getSet().getSeq_V().value_v)
    {
        Vertice v1(50.f);
        v1.vertice = it.v;
        allVertices.push_back(v1);
    }
    Font font;
    font.loadFromFile("fonts/Raleway-SemiBold.ttf");
    vector<Text> textArray;
    
    int zigzag = 0;
    int add = 0;
    for (auto &it : allVertices) {
        Text auxText;
        it.setFillColor(sf::Color(8, 41, 55));
        it.setPosition(pos_x + add, pos_y+zigzag);

        auxText.setFont(font);
        auxText.setPosition(pos_x+ 42 + add, pos_y +35 + zigzag);
        auxText.setCharacterSize(20);
        auxText.setString(to_string(it.vertice));
        textArray.push_back(auxText);
      
        

        pos_x += 200;
        if (zigzag == 0) {
            zigzag = 280;
        }
        else if (zigzag == 280) {
            zigzag = 0;
        }

        if (pos_x > 800)
        {
            pos_x = 10;
            pos_y += 200;
        }
    }
 
  
    sf::Vertex linea[MAX_ELEMENTS] = {};
    int positionLinea = 0;
    
    
    vector<Text> degreeArray;

    int degreePositionY=20;
    Text auxDegree;
    auxDegree.setCharacterSize(20);
    auxDegree.setFont(font);
    auxDegree.setPosition(1650, degreePositionY + 35);
    auxDegree.setString("VERTICE          GRADO");
    degreeArray.push_back(auxDegree);
    degreePositionY += 35;
    for (auto it : grafo.set.getSeq_V().value_v) {
        Text auxDegree;
        auxDegree.setCharacterSize(20);
        auxDegree.setFont(font);
        auxDegree.setPosition(1650, degreePositionY + 35); 
        auxDegree.setString("       "+to_string(it.v) + "            ->         " + to_string(grafo.degree(it.v)));
        degreeArray.push_back(auxDegree);
        degreePositionY += 35;
    }


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
            linea[positionLinea] = sf::Vertex(sf::Vector2f(ver1_x + 50, ver1_y + 50));
            linea[positionLinea].color = sf::Color::Green;
            positionLinea++;

            linea[positionLinea] = sf::Vertex(sf::Vector2f(ver2_x + 50, ver2_y + 50));
            linea[positionLinea].color = sf::Color::Green;
            positionLinea++;
            conteo++;
        }
    }




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
               
            }

        }

        window.clear();
        window.draw(rectangle);
        window.draw(linea, 100, sf::Lines);
        for (auto it : allVertices) {
            window.draw(it);

        }

       
        for (auto it : textArray) {
            window.draw(it);
        }

        for (auto it : degreeArray) {
            window.draw(it);
        }

 


        window.display();
    }


    return 0;
}
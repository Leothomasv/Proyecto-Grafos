
#include "Circle.h"
#include "Grafo.h"
#include <iostream>

using namespace sf;
using namespace std;
#define MAX_ELEMENTS 100


Grafo grafo;
Vertex linea[MAX_ELEMENTS] = {};
vector<Vertice> allVertices;
int positionLinea = 0;

void encontrarCamino(int partida,int destino) {
    //buscar camino
 
    if (grafo.EncontrarCamino(partida , destino)) {

        for (int i = 0; i < grafo.camino.size() - 1; i++) {
            float ver1_x = 0;
            float ver1_y = 0;
            float ver2_x = 0;
            float ver2_y = 0;
            for (auto& itV : allVertices) {
                auto l_front = grafo.camino.begin();
                advance(l_front, i);
                if (*l_front == itV.vertice)
                {
                    ver1_x = itV.getPosition().x;
                    ver1_y = itV.getPosition().y;
                }
            }

            for (auto& itV : allVertices) {
                auto l_front = grafo.camino.begin();
                advance(l_front, i + 1);
                if (*l_front == itV.vertice)
                {
                    ver2_x = itV.getPosition().x;
                    ver2_y = itV.getPosition().y;
                }
            }
            int conteo = 0;
            while (conteo != 2)
            {
                linea[positionLinea] = sf::Vertex(sf::Vector2f(ver1_x + 50, ver1_y + 50));
                linea[positionLinea].color = sf::Color::Red;
                positionLinea++;

                linea[positionLinea] = sf::Vertex(sf::Vector2f(ver2_x + 50, ver2_y + 50));
                linea[positionLinea].color = sf::Color::Red;
                positionLinea++;
                conteo++;
            }
        }

        cout << "\n Camino encontrado.\n";
    }
    else {
        cout << "\n No se ha encontrado un camino. \n";
    }
}

void pintarAristas() {
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
}

int main()
{
    int cant;
    cout << "Ingrese cantidad de vertices para el grafo: ";
    cin >> cant;

    vector<V> vertices = {};
    vector<E> aristas = {};

    for (int i = 0; i < cant; i++)
    {
        V vertex(i);
        vertices.push_back(vertex);
    }

    char comando = 'y';
    int v1;
    bool foundx = false;
    bool foundy = false;
    int v2;
    int peso = 1;

    do
    {
        cout << "Ingrese un vertice de E: ";
        cin >> v1;
        cout << "Ingrese el otro vertice de E: ";
        cin >> v2;
        cout << "Ingrese el peso de la arista: ";
        cin >> peso;
        cout << "\n Par Creado: ( " << v1 << " <-> " << v2 << " )\n" << endl;

        for (auto i : vertices)
        {
            if (i.v == v1)
            {
                foundx = true;
            }
            if (i.v == v2)
            {
                foundy = true;
            }

        }
        if (!foundx || !foundy)
        {
            cout << "Uno de los elementos ingresados no existe! Por favor ingresa un combinacion adecuada." << endl;
            foundx = false;
            foundy = false;
        }
        else {
            E vec(v1, v2, peso);
            aristas.push_back(vec);
            cout << "Desea continuar agregando? (y/n): ";
            cin >> comando;
            foundx = false;
            foundy = false;
        }
    } while (comando == 'y');


    
    SeqV seqV(vertices);
    SeqE seqE(aristas);
    Set set;
    set.setSeq_V(seqV);
    set.setSeq_E(seqE);
    grafo.setSet(set);
    

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Proyecto Teoria!");

    float pos_x = 10;
    float pos_y = 20;


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
    
    int zigzag_y = 0;
    int zigzag_x = 300;
    for (auto &it : allVertices) {
        Text auxText;
        it.setFillColor(sf::Color(8, 41, 55));
        it.setPosition(pos_x + zigzag_x, pos_y+zigzag_y);

        auxText.setFont(font);
        auxText.setPosition(pos_x+ 42 + zigzag_x, pos_y +35 + zigzag_y);
        auxText.setCharacterSize(20);
        auxText.setString(to_string(it.vertice));
        textArray.push_back(auxText);

        pos_x += 200;
        if (zigzag_y == 0) {
            zigzag_y = 280;
        }
        else if (zigzag_y == 280) {
            zigzag_y = 0;
        }
        if (pos_x > 800)
        {
            pos_x = 10;
            pos_y += 200;

            if (zigzag_x == 300) {
                zigzag_x = 700;
            }
            else if (zigzag_x == 700) {
                zigzag_x = 300;
            }
        }

    }
    
    //determinar los grados de cada vertices
    vector<Text> degreeArray;
    int degreePositionY=90;
    Text auxDegree;
    auxDegree.setCharacterSize(20);
    auxDegree.setFont(font);
    auxDegree.setPosition(1650, degreePositionY + 35);
    auxDegree.setString("VERTICE          GRADO");
    degreeArray.push_back(auxDegree);
    degreePositionY += 35;

    //menor y min grado de cada vertice
    Text MayorMin;
    grafo.MayorMenor();
    MayorMin.setCharacterSize(20);
    MayorMin.setFont(font);
    MayorMin.setPosition(1650, 20);
    MayorMin.setString("MIN: "+ to_string(grafo.min) + "                MAX: " + to_string(grafo.max));

    //tiene ciclos
    Text Ciclos;
    grafo.addEdge();
    string tieneciclos = grafo.TieneCiclos() ? "Si" : "No";
    Ciclos.setCharacterSize(20);
    Ciclos.setFont(font);
    Ciclos.setPosition(1650, 70);
    Ciclos.setString("Tiene ciclo(s): " + tieneciclos);
    
    //mensaje encontrar camino
    Text instruccion;
    instruccion.setCharacterSize(20);
    instruccion.setFont(font);
    instruccion.setPosition(1100,20);
    instruccion.setString("Presionar la tecla C para buscar un camino.");

    for (auto it : grafo.set.getSeq_V().value_v) {
        Text auxDegree;
        auxDegree.setCharacterSize(20);
        auxDegree.setFont(font);
        auxDegree.setPosition(1650, degreePositionY + 35); 
        auxDegree.setString("       "+to_string(it.v) + "            ->         " + to_string(grafo.degree(it.v)));
        degreeArray.push_back(auxDegree);
        degreePositionY += 35;
    }

   
    pintarAristas();

   

    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (Keyboard::isKeyPressed(Keyboard::C)) {
                    int partida, destino;
                    cout << "Ingrese punto de partida: ";
                    cin >> partida;
                    cout << "Ingrese destino: ";
                    cin >> destino;
                    pintarAristas();
                    encontrarCamino(partida,destino);
                }
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

        window.draw(MayorMin);
        
        window.draw(Ciclos);

        window.draw(instruccion);
        for (auto it : degreeArray) {
            window.draw(it);
        }



        window.display();
    }


    return 0;
}
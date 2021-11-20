
#include "SFML/Graphics.hpp";


int main()
{

    sf::RenderWindow window(sf::VideoMode(1080, 780), "SFML works!");
    sf::CircleShape shape1(100.f);
    sf::CircleShape shape2(100.f);

   

    shape1.setFillColor(sf::Color::Cyan);
    shape2.setFillColor(sf::Color::Green);
  
    shape1.setPosition(10, 20);
    shape2.setPosition(800, 100);

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
        
      
    
        window.draw(shape1);
        window.draw(shape2);
        window.draw(line, 6, sf::Lines);
    



        window.display();
    }


    return 0;
}
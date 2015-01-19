#include "utilities.hpp"
#include "Ball.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(SWIDTH,SHEIGHT), "My Pang", sf::Style::Default);

  sf::Texture textura;
  textura.loadFromFile("media/Bola.png");
  Ball ball(&textura);
  
  sf::Clock clock;
  while(window.isOpen()) { //Bucle del Juego
    sf::Time time = clock.restart();
    float deltaTime = time.asSeconds();
    // Procesar Eventos
    sf::Event event;
    while(window.pollEvent(event)) {
      switch(event.type) {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Escape) window.close();
          break;
        case sf::Event::MouseButtonPressed:
        {
          sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x,event.mouseButton.y);
          if (event.mouseButton.button == sf::Mouse::Left) ball.isClicked(mousePos);
          break;
      }
        default:
          break;
      }
    }
    // Updatear el juego
    ball.update(deltaTime);
    // Dibujar el juego
    window.clear(sf::Color(100,100,100));
    ball.draw(&window);
    window.display();
  }
  return 0;
}
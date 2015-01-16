#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

const int SWIDTH = 1280;
const int SHEIGHT = 720;
const int RADIUS = 50;


int main() {
  sf::RenderWindow window(sf::VideoMode(SWIDTH,SHEIGHT), "My Pang", sf::Style::Default);

  sf::CircleShape ball(RADIUS);
  ball.setFillColor(sf::Color::Red);
  ball.setOrigin(RADIUS,RADIUS);
  sf::Vector2f ballSpeed(250,0);
  sf::Vector2f ballPosition(SWIDTH/2, SHEIGHT/2);

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
        default:
          break;
      }
    }
    // Updatear el juego
    ballSpeed.y += 98*deltaTime;
    ballPosition += ballSpeed * deltaTime;
    if (ballPosition.y + RADIUS >= SHEIGHT) { // con el suelo
      ballSpeed.y *= -1;
      ballPosition.y = SHEIGHT - RADIUS;
    }
    else if (ballPosition.y - RADIUS <= 0) { // con el techo
      ballSpeed.y *= -1;
      ballPosition.y = RADIUS;
    }
    if (ballPosition.x + RADIUS >= SWIDTH) { // con el lado derecho
      ballSpeed.x *= -1;
      ballPosition.x = SWIDTH - RADIUS;
    }
    else if(ballPosition.x - RADIUS <= 0) { // con el lado izquierdo
      ballSpeed.x *= -1;
      ballPosition.x = RADIUS;
    }
    ball.setPosition(ballPosition);
    // Dibujar el juego
    window.clear(sf::Color(100,100,100));
    window.draw(ball);
    window.display();
  }
  return 0;
}
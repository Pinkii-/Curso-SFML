#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

const int SWIDTH = 800;
const int SHEIGHT = 600;


int main() {
  sf::RenderWindow window(sf::VideoMode(SWIDTH,SHEIGHT), "My Pang", sf::Style::Default);

  sf::Texture textura;
  textura.loadFromFile("media/Bola.png");
  sf::Sprite ball;
  ball.setTexture(textura);
  sf::FloatRect boundsRect = ball.getLocalBounds();                         
  ball.setOrigin(boundsRect.left + boundsRect.width/2.0f, boundsRect.top  + boundsRect.height/2.0f);
  int ballRadio = boundsRect.width/2.0f;
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
    if (ballPosition.y + ballRadio >= SHEIGHT) { // con el suelo
      ballSpeed.y *= -1;
      ballPosition.y = SHEIGHT - ballRadio;
    }
    else if (ballPosition.y - ballRadio <= 0) { // con el techo
      ballSpeed.y *= -1;
      ballPosition.y = ballRadio;
    }
    if (ballPosition.x + ballRadio >= SWIDTH) { // con el lado derecho
      ballSpeed.x *= -1;
      ballPosition.x = SWIDTH - ballRadio;
    }
    else if(ballPosition.x - ballRadio <= 0) { // con el lado izquierdo
      ballSpeed.x *= -1;
      ballPosition.x = ballRadio;
    }
    ball.setPosition(ballPosition);
    // Dibujar el juego
    window.clear(sf::Color(100,100,100));
    window.draw(ball);
    window.display();
  }
  return 0;
}
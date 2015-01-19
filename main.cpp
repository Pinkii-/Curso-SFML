#include "utilities.hpp"
#include "Ball.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(SWIDTH,SHEIGHT), "My Pang", sf::Style::Default);

  sf::Texture textura;
  textura.loadFromFile("media/Bola.png");
  Ball ball1(&textura, sf::Vector2f(SWIDTH/2,SHEIGHT/2), BALL_INIT_SPEED, 4.0);
  std::list<Ball*> balls;
  balls.push_back(&ball1);
  
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
          if (event.mouseButton.button == sf::Mouse::Left) {
            std::list<Ball*> ballsToAdd;
            for (auto it = balls.begin(); it != balls.end(); ++it) {
              if ((*it)->isClicked(mousePos)) {
                Ball* current = (*it);
                it = balls.erase(it);
                float newScale = current->getScale() / 2;
                if (newScale < 0.2) continue;
                sf::Vector2f newPos = current->getPos();
                float xSpeed = BALL_INIT_SPEED.x;
                Ball* auxBall1 = new Ball(&textura, newPos, sf::Vector2f( xSpeed, -30), newScale);
                Ball* auxBall2 = new Ball(&textura, newPos, sf::Vector2f(-xSpeed, -30), newScale);
                ballsToAdd.push_front(auxBall1);
                ballsToAdd.push_front(auxBall2);
              }
            }
            balls.insert(balls.end(), ballsToAdd.begin(), ballsToAdd.end());
          }
          break;
      }
        default:
          break;
      }
    }
    // Updatear el juego
    for (auto it = balls.begin(); it != balls.end(); ++it) {
      (*it)->update(deltaTime);
    }
    // Dibujar el juego
    window.clear(sf::Color(100,100,100));
    for (auto it = balls.begin(); it != balls.end(); ++it) {
      (*it)->draw(&window);
    }
    window.display();
  }
  return 0;
}
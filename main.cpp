#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


int main() {
  sf::RenderWindow window(sf::VideoMode(1280,720), "My Pang", sf::Style::Default);
  while(window.isOpen()) { //Bucle del Juego
    // Procesar Eventos

    // Updatear el juego

    // Dibujar el juego
    window.clear(sf::Color(100,100,100));
    // Aquí se hará el draw de cada elemento
    window.display();
  }
  return 0;
}
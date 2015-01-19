#include "Ball.hpp"

Ball::Ball(sf::Texture *textura) {
	sprite.setTexture(*textura); //Pasamos un puntero para arreglar el famoso cuadrado blanco
	sf::FloatRect boundsRect = sprite.getLocalBounds(); 
	sprite.setOrigin(boundsRect.left + boundsRect.width/2.0f, boundsRect.top  + boundsRect.height/2.0f);
	speed = sf::Vector2f(250,0);;
	radius = boundsRect.width/2;
}

Ball::~Ball() {}

void Ball::update(float deltaTime) {
	speed.y += 98*deltaTime;
	sf::Vector2f ballPosition = sprite.getPosition();
	ballPosition += speed * deltaTime;
    if (ballPosition.y + radius >= SHEIGHT) { // con el suelo
      speed.y *= -1;
      ballPosition.y = SHEIGHT - radius;
    }
    else if (ballPosition.y - radius <= 0) { // con el techo
      speed.y *= -1;
      ballPosition.y = radius;
    }
    if (ballPosition.x + radius >= SWIDTH) { // con el lado derecho
      speed.x *= -1;
      ballPosition.x = SWIDTH - radius;
    }
    else if(ballPosition.x - radius <= 0) { // con el lado izquierdo
      speed.x *= -1;
      ballPosition.x = radius;
    }
    sprite.setPosition(ballPosition);
}

void Ball::draw(sf::RenderWindow *window) {
	window->draw(sprite);
}

bool Ball::isClicked(sf::Vector2f mousePos) {
	sf::Vector2f posBall = sprite.getPosition();
	if (mousePos.x > posBall.x - radius and mousePos.x < posBall.x + radius and mousePos.y > posBall.y - radius and mousePos.y < posBall.y + radius) {
		speed.y -= 200;
		return true;
	}
	return false;
}
#include "Ball.hpp"
#include <iostream>

Ball::Ball(sf::Texture *textura, sf::Vector2f pos, sf::Vector2f speed, float scale) {
	sprite.setTexture(*textura); //Pasamos un puntero para arreglar el famoso cuadrado blanco
	sf::FloatRect boundsRect = sprite.getLocalBounds(); 
	sprite.setOrigin(boundsRect.left + boundsRect.width/2.0f, boundsRect.top  + boundsRect.height/2.0f);
	sprite.setPosition(pos);
	this->speed = speed;
	initRadius = boundsRect.width/2;
	this->scale = scale;
	sprite.setScale(scale,scale);
	std::cout << scale << std::endl;
}

Ball::~Ball() {}

void Ball::update(float deltaTime) {
	speed.y += 98*deltaTime;
	sf::Vector2f ballPosition = sprite.getPosition();
	ballPosition += speed * deltaTime;
	int bounceSpeed = MAX_BOUNCE_SPEED * (0.5 + std::log10(10*scale)*0.5);
	float radius = initRadius * scale;
    if (ballPosition.y + radius >= SHEIGHT) { // con el suelo
      speed.y = -bounceSpeed;
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
	int radius = initRadius * scale;
	if (mousePos.x > posBall.x - radius and mousePos.x < posBall.x + radius and mousePos.y > posBall.y - radius and mousePos.y < posBall.y + radius) {
		return true;
	}
	return false;
}

sf::Vector2f Ball::getPos() {
	return sprite.getPosition();
}

float Ball::getScale() {
	return scale;
}
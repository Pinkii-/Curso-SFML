#include "utilities.hpp"

class Ball {
private:
	sf::Sprite sprite;
	sf::Vector2f speed;
	int initRadius;
	float scale;
public:
	Ball(sf::Texture *textura, sf::Vector2f pos, sf::Vector2f, float scale);
	~Ball();
	void update(float deltaTime);
	void draw(sf::RenderWindow* window);
	bool isClicked(sf::Vector2f mousePos);
	sf::Vector2f getPos();
	float getScale();
};
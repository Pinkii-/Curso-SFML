#include "utilities.hpp"

class Ball {
private:
	sf::Sprite sprite;
	sf::Vector2f speed;
	int radius;
public:
	Ball(sf::Texture *textura);
	~Ball();
	void update(float deltaTime);
	void draw(sf::RenderWindow* window);
	bool isClicked(sf::Vector2f mousePos);
};
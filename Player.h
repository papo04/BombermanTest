#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

using namespace sf;

class Player : public Colisionable, public Drawable
{
public:
	Player();
	void cmd();
	void choqueBloque();
	void caminar();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	FloatRect getBounds() const;
	Sprite getSprite();
private:
	Vector2f _velocidad;
	Texture _txt[4];
	Sprite _sprite;
	Event _event;

};
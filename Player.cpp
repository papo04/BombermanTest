#include "Player.h"

Player::Player()
{
	_velocidad = { 0,0 };
	_txt[0].loadFromFile("down1.png");
	_txt[1].loadFromFile("up1.png");
	_txt[2].loadFromFile("right1.png");
	_txt[3].loadFromFile("left1.png");

	_sprite.setTexture(_txt[1]);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}

void Player::cmd()
{
	float mov = 2;
	_velocidad = {};

	if (Keyboard::isKeyPressed(Keyboard::Up)) {

		_velocidad.y = -1*mov;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down)) {

		_velocidad.y = mov;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left)) {

		_velocidad.x = -1*mov;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right)) {

		_velocidad.x = mov;

	}
	_sprite.move(_velocidad);

	if (_velocidad.x < 0) {
		_sprite.setTexture(_txt[3]);
	}
	else if (_velocidad.x > 0) {
		_sprite.setTexture(_txt[2]);
	}
	else if (_velocidad.y < 0) {
		_sprite.setTexture(_txt[1]);
	}
	else if (_velocidad.y > 0) {
		_sprite.setTexture(_txt[0]);
	}

	//BORDES
	float margenAncho = 45 + _sprite.getGlobalBounds().width / 2, margenAlto = 45 + _sprite.getGlobalBounds().height / 2;
	if (_sprite.getPosition().x < margenAncho) {
		_sprite.setPosition(margenAncho, _sprite.getPosition().y);
	}
	if (_sprite.getPosition().x > 800 - margenAncho) {
		_sprite.setPosition(800 - margenAncho, _sprite.getPosition().y);
	}
	if (_sprite.getPosition().y < margenAlto) {
		_sprite.setPosition(_sprite.getPosition().x, margenAlto);
	}
	if (_sprite.getPosition().y > 600 - margenAlto) {
		_sprite.setPosition(_sprite.getPosition().x, 600 - margenAlto);
	}
}

//void Player::caminar() {
//	_sprite.getPosition().x
//}

void Player::choqueBloque()
{
	_sprite.move(-_velocidad);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

FloatRect Player::getBounds() const
{
	return _sprite.getGlobalBounds();
}

Sprite Player::getSprite()
{
	return _sprite;
}

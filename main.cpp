#include <SFML/Graphics.hpp>
#include "BloqueFijo.h"
#include "Bomba.h"
#include <iostream>
#include "Player.h"
#include "Fuego.h"
#include "Mapa.h"
using namespace sf;



int main() {
	srand(time(NULL));
	RenderWindow* ventana1 = new RenderWindow(VideoMode(800, 600), "Bomberman");
	ventana1->setFramerateLimit(60);

	
	Sprite fondo;
	Texture txtFondo;
	txtFondo.loadFromFile("FondoSinMedio.png");
	fondo.setTexture(txtFondo);
	//fondo.setOrigin(fondo.getGlobalBounds().width / 2, fondo.getGlobalBounds().height / 2);
	fondo.setPosition(0,0 );

	Player  player1;

	BloqueDestruibles * bloquesito = new BloqueDestruibles(13,11);


	Bomba* bomba = new Bomba;
	int timer = 0;

	Fuego* fuego = new Fuego;
	int timer2 = 0;

	Mapa* mapa1 = new Mapa;

	//BloqueFijo* bf[6][5];
	//for (int i = 0; i < 6; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		bf[i][j] = new BloqueFijo(i, j);
	//	}
	//}

	while (ventana1->isOpen()) {
		sf::Event event;
		while (ventana1->pollEvent(event)) {
			if (event.type == Event::Closed) {
				ventana1->close();
			}
		}
		//CMD
		player1.cmd();
		if (mapa1->comprobarColisionAmbos(player1)) {
			player1.choqueBloque();
		}
		mapa1->comprobarColisionDestruir(*fuego);

		//Choque con bloques fijos
		//for (int i = 0; i < 6; i++) {
		//	for (int j = 0; j < 5; j++) {
		//		if (player1.isColision(*bf[i][j])) {
		//			player1.choqueBloque();
		//		}
		//	}
		//}
		//plantar bomba
		if (Keyboard::isKeyPressed(Keyboard::Space) && timer == 0) {
			timer = 60 * 5;
			bomba->setSpritePosition(player1.getSprite().getPosition());
		}
		if (timer > 0) {
			timer--;
		}
		//fuego al estallar bomba (no funciona)
		if (timer == 1) {
			timer2 = 60 * 2;
			fuego->setSpritePosition(bomba->getSprite().getPosition());

		}
			if (timer2 > 0) {
				timer2--;
			}

			ventana1->clear();
			ventana1->draw(fondo);
			mapa1->dibujarDestruibles(ventana1);
			if (timer2 > 0) {
				ventana1->draw(*fuego);
			}
			mapa1->dibujarFijos(ventana1);

			if (timer > 0) {
				ventana1->draw(*bomba);
			}
			ventana1->draw(player1);
			ventana1->display();
		}


		return 0;
	}
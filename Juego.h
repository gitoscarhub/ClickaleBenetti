#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include "PlayerJuegoCross.h"
#include "Enemigo.h"

using namespace sf;

class Juego
{
private:
	RenderWindow *_wnd;
	PlayerJuegoCross *_player;
	Enemigo *_enemigos;
	Text _puntaje;
	Font _fuente;
	int _puntos;
	

	void _actualizarPuntaje(){
		std::string str = std::to_string(_puntos);
		_puntaje.setString(str);	
	}
public:


	Juego(){
		_wnd = new RenderWindow(VideoMode(800, 600), "ClickaleBenetti");
		_player = new PlayerJuegoCross();
		_enemigos = new Enemigo[5];
		_puntos = 0;
		_actualizarPuntaje();
		_fuente.loadFromFile("arial.ttf");
		_puntaje.setFont(_fuente);
		_puntaje.setPosition(0.0f, 0.0f);
		_puntaje.setCharacterSize(50.0f);
		_puntaje.setFillColor(Color::Black);

		
	}


	void Loop(){

		while (_wnd->isOpen()){
			ProcesarEventos();
			Actualizar();
			Dibujar();

		}
	}

	void ProcesarEventos(){
		Event evt;
		while (_wnd->pollEvent(evt)){
			switch (evt.type){
			case Event::Closed:
				_wnd->close();
				break;
			case Event::MouseMoved:
				_player->Posicionar(evt.mouseMove.x, evt.mouseMove.y);
				break;
			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Button::Left)
					Disparar();
				break;
			}
		}
	}

	void Actualizar(){

		//Actualizamos la posicion del crosshair
		//Vector2i mousePos = Mouse::getPosition(*_wnd);
		//_player->Posicionar(mousePos.x, mousePos.y);
		for (size_t i = 0; i < 10; i++)
		{
			_enemigos[i].Actualizar(_wnd);
		}
		
	}

	void Disparar(){
		//chequeamos colisiones con el disparo
		Vector2f playerPos = _player->ObtenerPosicion();
		for (int i = 0; i < 10; i++){
			if (_enemigos[i].EstaActivo()){
				if (_enemigos[i].EstaEncima(playerPos.x, playerPos.y)){
					_enemigos[i].Derrotar();
					_puntos++;
				}
			}
		}
		_actualizarPuntaje();
	}

	void Dibujar(){
		_wnd->clear(Color::White);
		//Dibujar los elementos de Juego
		
		for (int i = 0; i <10; i++)
		{
			if (_enemigos[i].EstaActivo())
				_enemigos[i].Dibujar(_wnd);
		}
		_wnd->draw(_puntaje);
		_player->Dibujar(_wnd);
		_wnd->display();
	}


	~Juego(){
	
		delete _enemigos;
		delete _player;
		delete _wnd;
	}
};

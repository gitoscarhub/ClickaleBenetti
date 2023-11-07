#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Enemigo{
	
	Texture _enemyTex;
	Sprite _enemySprite;
	bool _estaVivo;
	bool _estaVisible;
	sf::Clock _clock;
	float _tiempoVisible;
	float _tiempoApagado;

	Vector2f _randomPos(Vector2u maxPos){

		Vector2f random((float) (rand() % (int)maxPos.x) , (float) (rand() %  (int)maxPos.y));
		return random;
	}
	
public:

	Enemigo(){

		_enemyTex.loadFromFile("etpequeño.png");
		_enemySprite.setTexture(_enemyTex);
		_enemySprite.setScale(0.2f, 0.2f);
		_estaVivo = true;
		_estaVisible = false; 
		_tiempoVisible = 0.5f;
		_tiempoApagado = 0.5f;
	}



	bool EstaVivo(){
		return _estaVivo;

	}
	bool EstaActivo(){
		return _estaVivo && _estaVisible;
	}
	
	bool EstaEncima(float x, float y){
		FloatRect bounds = _enemySprite.getGlobalBounds();
			return bounds.contains(x, y);
	}

	void Derrotar(){
		_estaVivo = false;
	}
	void Dibujar(RenderWindow *wnd){
		wnd->draw(_enemySprite); 
	}

	void Actualizar(RenderWindow* wnd){
		if (!_estaVivo)
			return;

		if (!_estaVisible){//tiramos una probabilidad para ver si lo activamos
			if (_clock.getElapsedTime().asSeconds() > _tiempoApagado){
				_clock.restart();
				if (rand() % 100 < 25){
					_estaVisible = true;
					_enemySprite.setPosition(_randomPos(wnd->getSize()));
				}
			}
			}
		
		else{
			if (_clock.getElapsedTime().asSeconds() > _tiempoVisible){
				_estaVisible = false;
				_clock.restart();
			}
		}
	}
};
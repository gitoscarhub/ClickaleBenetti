#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;

class PlayerJuegoCross{

	Texture _crossTex;
	Sprite _crossSprite;

public:

	PlayerJuegoCross(){

		_crossTex.loadFromFile("crosshair.png");
		_crossSprite.setTexture(_crossTex);
		_crossSprite.setScale(0.3f, 0.3f);
		 Vector2u size = _crossTex.getSize();
		_crossSprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	}
	 
	void Dibujar(RenderWindow *wnd){

		wnd->draw(_crossSprite);
	}
	
	void Posicionar(float x, float y){
		_crossSprite.setPosition(x, y);

	}

	Vector2f ObtenerPosicion(){
		return _crossSprite.getPosition();
	}
	
};

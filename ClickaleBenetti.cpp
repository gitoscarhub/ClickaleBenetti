// ClickaleBenetti.cpp: define el punto de entrada de la aplicación de consola.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <tchar.h>
#include "Juego.h" 

int _tmain(int argc, _TCHAR* argv[])
{       
	Juego ClickaleBenetti;
	ClickaleBenetti.Loop();
	return 0;
}


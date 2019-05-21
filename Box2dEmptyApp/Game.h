#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "SFMLRenderer.h"
#include "SFMLObject.h"
#include <list>

using namespace sf;
using namespace std;
class Game
{
private:
	//Propiedades de la ventana
	int alto;
	int ancho;
	RenderWindow *wnd;
	Color clearColor;

	//objetos de box2d
	b2World *phyWorld;
	SFMLRenderer *debugRender;

	//tiempo de frame
	float frameTime;
	int fps;

	//cuerpo de box2d 
	b2Body* controlBody;
	std::list<SFMLObject*> objects;
	std::list<SFMLObject*>::iterator it;

		

public:

	//Constructores, destructores e inicializadores
	Game(int ancho, int alto,std::string titulo);
	void CheckCollitions();
	void CreateEnemy(int x, int y);
	~Game(void);
	void InitPhysics();
	

	//Main game loop
	void Loop();
	void DrawGame();
	void UpdatePhysics();
	void DoEvents();
	void SetZoom();
	void shoot(sf::Event evt);
	
};


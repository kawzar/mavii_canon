#include "StdAfx.h"
#include "Game.h"
#include "Box2DHelper.h"
#include "Target.h"
#include "Arrow.h"
#include "Ball.h"

Game::Game(int ancho, int alto,std::string titulo)
{
	wnd= new RenderWindow(VideoMode(ancho,alto),titulo);
	wnd->setVisible(true);
	fps=60;
	wnd->setFramerateLimit(fps);
	frameTime=1.0f/fps;
	clearColor = Color::White;
	SetZoom();
	InitPhysics();
}


void Game::Loop(){

	
	while(wnd->isOpen()){
		
		wnd->clear(clearColor);
		DoEvents();
		CheckCollitions();
		UpdatePhysics();
		DrawGame();
		wnd->display();
	
	}

}

void Game::UpdatePhysics() {

	phyWorld->Step(frameTime, 8, 8);
	phyWorld->ClearForces();
	phyWorld->Step(frameTime, 8, 8);

	for (it = objects.begin(); it != objects.end(); ++it)
	{
		(*it)->updatePosition();
	}
}

void Game::DrawGame(){
	phyWorld->DrawDebugData();
	//p1->draw();
	for (it = objects.begin(); it != objects.end(); ++it)
	{
		(*it)->draw();
	}
}

void Game::DoEvents(){

	Event evt;
	while(wnd->pollEvent(evt)){
	
		switch(evt.type){
			case Event::Closed:
				wnd->close();
				break;
			case Event::MouseButtonPressed:
				shoot(evt);
				break;
		}

		
	}
}

void Game::CheckCollitions(){

	//veremos mas adelante

}

//Definimos el area del mundo que veremos en nuestro juego
//Box2D tiene problemas para simular magnitudes muy grandes
void Game::SetZoom(){

	View camara;
	//posicion del view
	camara.setSize(160, 100);
	camara.setCenter(80.0f, 50.0f);
	wnd->setView(camara); //asignamos la camara
	

}
void Game::shoot(sf::Event evt)
{
	Vector2f pos = wnd->mapPixelToCoords(Vector2i(evt.mouseButton.x, evt.mouseButton.y));
	Ball* b = new Ball(phyWorld, wnd, "canonball.png", 0.01, 30, 80);
	objects.push_back(b);

	b->applyImpulse(b2Vec2(pos.x, pos.y));
}


void Game::InitPhysics(){

	//inicializamos el mundo con la gravedad por defecto
	phyWorld= new b2World(b2Vec2(0.0f,9.8f));
	
	/*MyContactListener* l= new MyContactListener();
	phyWorld->SetContactListener(l);*/
	//Creamos el renderer de debug y le seteamos las banderas para que dibuje TODO
	debugRender= new SFMLRenderer(wnd);
	debugRender->SetFlags(UINT_MAX);
	phyWorld->SetDebugDraw(debugRender);


	//creamos un piso y paredes
	b2Body* groundBody = Box2DHelper::CreateRectangularStaticBody(phyWorld,160,10);
	groundBody->SetTransform(b2Vec2(80.0f,100.0f),0.0f);		


	//*****
	
	Target* target = new Target(phyWorld, wnd, "box.jpg", 0.05f, 115, 100);
	objects.push_back(target);

	Target* target2 = new Target(phyWorld, wnd, "box.jpg", 0.05f, 118, 100);
	objects.push_back(target2);

	Target* target3 = new Target(phyWorld, wnd, "box.jpg", 0.05f, 121, 100);
	objects.push_back(target3);

	Target* target4 = new Target(phyWorld, wnd, "box.jpg", 0.05f, 117, 90);
	objects.push_back(target4);

	Target* target5 = new Target(phyWorld, wnd, "box.jpg", 0.05f, 120, 90);
	objects.push_back(target5);

	Target* target6 = new Target(phyWorld, wnd, "box.jpg", 0.05f, 118, 85);
	objects.push_back(target6);



	int fps = 60;
	wnd->setFramerateLimit(fps);
	float frameTime = 1.0f / fps;
}


Game::~Game(void)
{
}

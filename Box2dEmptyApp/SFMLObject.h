#pragma once
#include "stdafx.h"
#include "Box2DHelper.h"
#include "SFMLRenderer.h"
class SFMLObject
{
protected:
	//sprite y su imagen la para representaci�n gr�fica
	Sprite *_sprite;
	Texture  *_image;
	RenderWindow *wnd;
	//body para representaci�n f�sica
	b2Body* _body;
	b2PolygonShape _dynamicBox;

	void createFixtureDefinition(float density, float friction, float restitution);
	//...
public:
	SFMLObject(b2World* _world, RenderWindow *_wnd, std::string path, float scale, float posX, float posY);
	void updatePosition();
	void draw();
};




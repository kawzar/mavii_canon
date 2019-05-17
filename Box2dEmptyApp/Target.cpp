#include "stdafx.h"
#include "Target.h"


Target::Target(b2World* _world, RenderWindow *_wnd, std::string path, float scale, float posX, float posY) : SFMLObject(_world, _wnd, path, scale, posX, posY)
{
	const float density = 1.0f; 
	const float friction = 0.5f;
	const float restitution = 0.1f;

	_body = Box2DHelper::CreateRectangularDynamicBody(_world, 10, 10, density, friction, restitution);
	_body->SetTransform(b2Vec2(posX, posY), 0.0f);

	_dynamicBox.SetAsBox(_sprite->getGlobalBounds().width / 2.f, _sprite->getGlobalBounds().height / 2.f);	
	createFixtureDefinition(density, friction, restitution);
}


Target::~Target()
{
}


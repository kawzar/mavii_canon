#include "stdafx.h"
#include "Ball.h"


Ball::Ball(b2World* _world, RenderWindow *_wnd, std::string path, float scale, float posX, float posY) : SFMLObject(_world, _wnd, path, scale, posX, posY)
{	
	_body = Box2DHelper::CreateRectangularDynamicBody(_world, 1, 1, 10.0f, 0.3f, 0.1f);
	_body->SetTransform(b2Vec2(posX, posY), 0.0f);

	_dynamicBox.SetAsBox(_sprite->getGlobalBounds().width / 2.f, _sprite->getGlobalBounds().height / 2.f);
	createFixtureDefinition(10.0f, 0.3f, 0.1f);
}


Ball::~Ball()
{
}

void Ball::applyImpulse(b2Vec2 impulse) {
	b2Vec2 newImpulse = b2Vec2((impulse.x - _body->GetPosition().x) * 50, (impulse.y - _body->GetPosition().y) * 50);
	_body->ApplyLinearImpulse(newImpulse, _body->GetPosition(), true);
}

#include "stdafx.h"
#include "SFMLObject.h"


SFMLObject::SFMLObject(b2World* _world, RenderWindow *_wnd, std::string path, float scale, float posX, float posY) {
	wnd = _wnd;
	_image = new Texture();
	_image->loadFromFile(path);
	_sprite = new Sprite(*_image);
	_sprite->setOrigin(_sprite->getLocalBounds().width / 2.f, _sprite->getLocalBounds().height / 2.f);
	_sprite->setScale(scale, scale);
}

void SFMLObject::updatePosition() {
	b2Vec2 pos = _body->GetPosition();
	_sprite->setPosition(pos.x, pos.y);
}

void SFMLObject::draw() {
	wnd->draw(*_sprite);
}

void SFMLObject::createFixtureDefinition(float density, float friction, float restitution) {

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &_dynamicBox;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;
	_body->CreateFixture(&fixtureDef);
}
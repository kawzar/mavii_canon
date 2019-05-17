#include "stdafx.h"
#include "Arrow.h"


Arrow::Arrow(b2World* _world, RenderWindow *_wnd, std::string path, float scale, float posX, float posY): SFMLObject(_world, _wnd, path, scale, posX, posY)
{
	_sprite->setPosition(posX, posY);
}


Arrow::~Arrow()
{
}

void Arrow::updatePosition() {
	sf::Vector2f curPos = _sprite->getPosition();
	sf::Vector2i position = sf::Mouse::getPosition(*wnd);

	// now we have both the sprite position and the cursor
	// position lets do the calculation so our sprite will
	// face the position of the mouse
	const float PI = 3.14f;

	float dx = curPos.x - position.x;
	float dy = curPos.y - position.y;

	float rotation = ((atan2(dy, dx)) * 180 / PI);

	_sprite->setRotation(rotation);
}
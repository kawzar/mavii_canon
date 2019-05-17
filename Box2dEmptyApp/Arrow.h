#pragma once
#include "SFMLObject.h"
class Arrow : public SFMLObject
{
public:
	Arrow(b2World* _world, RenderWindow *_wnd, std::string path, float scale, float posX, float posY);
	~Arrow();
	void updatePosition();
};


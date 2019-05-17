#pragma once
#include "SFMLObject.h"

class Target : public SFMLObject
{
public:
	Target(b2World* _world, RenderWindow *_wnd, std::string path, float scale, float posX, float posY);
	~Target();
};


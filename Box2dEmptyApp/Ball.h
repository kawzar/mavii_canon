#pragma once
#include "SFMLObject.h"

class Ball :  public SFMLObject
{ 
public:
	Ball(b2World* _world, RenderWindow *_wnd, std::string path, float scale, float posX, float posY);
	~Ball();
	void applyImpulse(b2Vec2 impulse);
};


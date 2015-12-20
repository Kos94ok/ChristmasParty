
#pragma once

#include "stdafx.h"

class cWindowMain
{
public:
	sf::RenderWindow handle;
	sf::RenderTexture texHandle;

	void init();
	void display();
};

extern cWindowMain window;
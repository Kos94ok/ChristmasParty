
#include "stdafx.h"
#include "window.h"

cWindowMain window;

void cWindowMain_init(int id, adv::cArgs args)
{
	// Thread routine
	advCore.threadState[id] = STATE_UP;
	// Create a window
	vec2i size(advUI.desktopSize.x, advUI.desktopSize.y);
	sf::ContextSettings settings;
	window.handle.create(sf::VideoMode(size.x, size.y), "Window", sf::Style::None, settings);
	window.texHandle.create(size.x, size.y);
	// Manage a window
	while (advCore.isThreadGood(id)) {
		// Events
		sf::Event eventPoll;
		while (window.handle.pollEvent(eventPoll)) {
			advEvent.handle(eventPoll, &window.handle);
		}
		// Display
		window.display();
	}
	advCore.threadState[id] = STATE_DOWN;
}

void cWindowMain::init()
{
	advCore.addThread(cWindowMain_init, NULL);
}

void cWindowMain::display()
{
	texHandle.clear();

	if (!advCore.isInitializing()) {
		advUI.paint(&texHandle);
	}

	texHandle.display();
	sf::Sprite spr(texHandle.getTexture());
	handle.clear();
	handle.draw(spr);
	handle.display();
}
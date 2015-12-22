
#include "stdafx.h"
#include "window.h"
#include "stage.h"

//#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

void module_govnokod();

int main()
{
	// Core initialization
	advCore.init();

	stage.init();
	window.init();

	advCore.postInit();

	// Go to main loop
	advCore.mainLoop();

	// Shutdown
	advCore.shut();
	return 0;
}
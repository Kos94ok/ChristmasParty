
#include "stdafx.h"
#include "..\AdvLib\advlib.h"

/*using namespace adv;
using namespace std;

bool OVERCHARGE = false;
float overtimer;

class cBG : public adv::cDrawable
{

};

class cBase : public adv::cDrawable
{
public:
	vec2f test;
	bool isAlive = true;
	void kill() { isAlive = false; }

	void updateBrush() {
		cDrawable::updateBrush();

		brushRect.setFillColor(color(255, 255, 255));
		if (OVERCHARGE) { brushRect.setFillColor(color(255, 0, 0)); }
	}
};

class cGun : public adv::cDrawable
{
public:

};

class cBullet : public adv::cDrawable
{
public:
	vec2f moveVector;
};

class cAsteroid : public adv::cDrawable
{
public:
	vec2f moveVector;
	float angleVector;
	bool isAlive = true;

	void kill() { isAlive = false; }
};

int HP = 3;
cBG background;
cBase base;
cGun gun;
vectox<cBullet> bullet;
vectox<cAsteroid> asteroid;
cAsteroid ammo;
cAsteroid shield;
int score = 0;
int bullets = 10;
float asteroidDelay = 1.00f;

void windowThread(int id, cArgs args)
{
	sf::RenderWindow winHandle;
	sf::ContextSettings settings;
	winHandle.create(sf::VideoMode(800, 800), "Taiga 5: Test Project", 7U, settings);
	winHandle.setVerticalSyncEnabled(true);
	sf::RenderTexture texHandle;
	texHandle.create(800, 800);

	advCore.threadState[id] = STATE_UP;
	do
	{
		// Polling events
		sf::Event eventPoll;
		while (winHandle.pollEvent(eventPoll)) {
			advEvent.handle(eventPoll, &winHandle);
		}
		// Painting
		texHandle.clear(color(255, 255, 255));
		winHandle.clear(color(0, 0, 0));

		background.paint(&texHandle);
		if (base.isAlive) { base.paint(&texHandle); gun.paint(&texHandle); }
		asteroid.access.lock();
		for (int i = 0; i < (int)asteroid.size(); i++) {
			if (asteroid[i].isAlive) { asteroid[i].paint(&texHandle); }
		}
		asteroid.access.unlock();
		bullet.access.lock();
		for (int i = 0; i < (int)bullet.size(); i++) {
			bullet[i].paint(&texHandle);
		}
		bullet.access.unlock();
		if (ammo.isAlive) { ammo.paint(&texHandle); }
		if (shield.isAlive) { shield.paint(&texHandle); }
		advUI.paint(&texHandle);

		texHandle.display();
		winHandle.draw(sf::Sprite(texHandle.getTexture()));
		winHandle.display();
		Sleep(5);

	} while (advCore.isThreadGood(id));
	advCore.threadState[id] = STATE_DOWN;
}

void asteroidSpawn(cEventArgs args)
{
	float speed = math.randf(50, 100 / min(1.00f, asteroidDelay + 0.5f));
	float size = math.randf(20, 70 / min(1.00f, max(0.50f, asteroidDelay + 0.25f)));
	cAsteroid newAst;
	newAst.moveto(math.polar(vec2f(400, 400), 570, math.randAngle()));
	newAst.resize(vec2f(size, size));
	newAst.centralize(vec2f(size / 2, size / 2));
	newAst.moveVector = math.polar(newAst.pos(), speed, math.getAngle(newAst.pos(), base.pos()) + math.srandf(30.00f)) - newAst.pos();
	newAst.angleVector = math.srandf(100.00f);
	newAst.texturize(advTexture.add("asteroid.png"));
	asteroid.add(newAst);

	if (base.isAlive) { score += 10; }
	advUI.getWindow("main")->setLabelText("counter", "Score: " + to_string(score));

	advTimer.start(asteroidDelay, "asteroidSpawn");
}

void asteroidDelayTimer(cEventArgs args)
{
	asteroidDelay -= 0.01f;
	if (asteroidDelay < 0.05) { asteroidDelay = 0.05f; }
}

void asteroidMove(cEventArgs args)
{
	float timeMod = (float)args.timer_tickTime / 1000.00f;
	asteroid.access.lock();
	for (int i = 0; i < (int)asteroid.size(); i++) {
		asteroid[i].move(asteroid[i].moveVector * timeMod);
		asteroid[i].rotate(asteroid[i].angleVector * timeMod);
	}
	for (int i = 0; i < (int)bullet.size(); i++) {
		bullet[i].move(bullet[i].moveVector * timeMod);
	}
	asteroid.access.unlock();
	if (ammo.isAlive) {
		ammo.move(ammo.moveVector * timeMod);
	}
	if (shield.isAlive) {
		shield.move(shield.moveVector * timeMod);
	}
}

void baseMove(cEventArgs args)
{
	float timeMod = (float)args.timer_tickTime / 1000.00f;

	float spd = 1000.00f * timeMod;
	bool moveGun = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { base.move(vec2f(0, -spd)); base.faceto(-90.00f); moveGun = true; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { base.move(vec2f(-spd, 0)); base.faceto(180.00f); moveGun = true; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { base.move(vec2f(0, spd)); base.faceto(90.00f); moveGun = true; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { base.move(vec2f(spd, 0)); base.faceto(0.00f); moveGun = true; }

	if (moveGun) { gun.moveto(base.pos()); }
}

void gunRotate(cEventArgs args)
{
	gun.faceto(math.getAngle(gun.pos(), advMouse.posF));

	if (OVERCHARGE && overtimer > 0.00f) {
		overtimer -= args.timer_tickDelay;
		advUI.getWindow("main")->setLabelText("shield", "Shield: OVERCHARGE [" + to_string(overtimer) + "]");
		advUI.getWindow("main")->setLabelColor("shield", color(255, 0, 0));
	}
	else if (OVERCHARGE) {
		if (HP <= 1) { advUI.getWindow("main")->setLabelText("shield", "Shield: Paper"); }
		else if (HP == 2) { advUI.getWindow("main")->setLabelText("shield", "Shield: Plastic"); }
		else if (HP == 3) { advUI.getWindow("main")->setLabelText("shield", "Shield: Izolenta"); }
		advUI.getWindow("main")->setLabelColor("shield", color(255, 255, 255));
		OVERCHARGE = false;
		base.update();
	}
}

void gunShoot(cEventArgs args)
{
	if (bullets > 0) {
		bullets -= 1;
		advUI.getWindow("main")->setLabelText("bullets", "Bullets: " + to_string(bullets));

		float angle = math.getAngle(gun.pos(), advMouse.posF);
		cBullet blt;
		blt.moveto(gun.pos());
		blt.resize(vec2f(6, 6));
		blt.faceto(gun.angle());
		blt.texturize(advTexture.add("asteroid.png"));
		blt.moveVector = math.polar(vec2f(0, 0), 1000.00f, angle);
		bullet.add(blt);
	}
}

void shieldDown(cEventArgs args)
{

}

void shieldUp()
{
	OVERCHARGE = true;
	base.update();
	overtimer = 7.93f;
}

void collision(cEventArgs args)
{
	for (int i = 0; i < (int)asteroid.size(); i++) {
		bool stahp = false;
		cAsteroid* ast = &asteroid[i];
		vec2f position = ast->pos();
		if (base.isAlive)
		{
			if (math.getDistance(position, base.pos()) <= ast->size().x / 2 + base.size().x / 2) {
				if (!OVERCHARGE) {
					if (HP == 1) {
						base.kill();
						advUI.getWindow("main")->setLabelText("shield", "Shield: T_T");
						advUI.getWindow("main")->setLabelColor("shield", color(255, 0, 0));
					}
					else {
						HP -= 1;
						if (HP <= 1) { advUI.getWindow("main")->setLabelText("shield", "Shield: Paper"); }
						else if (HP == 2) { advUI.getWindow("main")->setLabelText("shield", "Shield: Plastic"); }
						else if (HP == 3) { advUI.getWindow("main")->setLabelText("shield", "Shield: Izolenta"); }
					}
				}
				else {
					score += 25;
					advUI.getWindow("main")->setLabelText("counter", "Score: " + to_string(score));
				}
				asteroid.remove(i);
				stahp = true;
			}
		}
		if (!stahp && !math.isPointInRect(position.x, position.y, -200, -200, 1200, 1200)) {
			asteroid.remove(i);
			stahp = true;
		}
		for (int y = 0; y < (int)bullet.size(); y++) {
			if (!stahp && math.getDistance(bullet[y].pos(), asteroid[i].pos()) <= bullet[y].size().x / 2 + asteroid[i].size().x / 2) {
				asteroid.remove(i);
				bullet.remove(y);
				stahp = true;

				score += 15;
				advUI.getWindow("main")->setLabelText("counter", "Score: " + to_string(score));
			}
		}
	}

	if (base.isAlive && ammo.isAlive && math.getDistance(base.pos(), ammo.pos()) < base.size().x / 2 + ammo.size().x / 2) {
		ammo.kill();
		bullets += 10;
		advUI.getWindow("main")->setLabelText("bullets", "Bullets: " + to_string(bullets));
	}
	if (base.isAlive && shield.isAlive && math.getDistance(base.pos(), shield.pos()) < base.size().x / 2 + shield.size().x / 2) {
		shield.kill();
		shieldUp();
	}
}

void ammoRestock(cEventArgs args)
{
	ammo.isAlive = true;
	ammo.resize(vec2f(20, 20));
	ammo.centralize(vec2f(10, 10));
	ammo.moveto(vec2f(810.00f, 400.00f + math.srandf(300.00f)));
	ammo.texturize(advTexture.add("ui_icon_empty_orange_24.png"));
	ammo.moveVector = vec2f(-50.00f, 0.00f);
}

void shieldRestock(cEventArgs args)
{
	shield.isAlive = true;
	shield.resize(vec2f(20, 20));
	shield.centralize(vec2f(10, 10));
	shield.moveto(vec2f(-10.00f, 400.00f + math.srandf(300.00f)));
	shield.texturize(advTexture.add("ui_icon_empty_white_24.png"));
	shield.moveVector = vec2f(50.00f, 0.00f);
}

void module_govnokod()
{
	advTimer.start(asteroidDelay, "asteroidSpawn");
	advTimer.start(0.01f, "asteroidMove", true);
	advTimer.start(0.002f, "baseMove", true);
	advTimer.start(0.05f, "collision", true);
	advTimer.start(1.00f, "asteroidDelay", true);
	advTimer.start(0.01f, "gunRotate", true);
	advTimer.start(15.00f, "ammoRestock", true);
	advTimer.start(43.28f, "shieldRestock", true);
	advEvent.listen(EVENT_TIMER_END, asteroidSpawn, "asteroidSpawn");
	advEvent.listen(EVENT_TIMER_TICK, asteroidMove, "asteroidMove");
	advEvent.listen(EVENT_TIMER_TICK, baseMove, "baseMove");
	advEvent.listen(EVENT_TIMER_TICK, collision, "collision");
	advEvent.listen(EVENT_TIMER_TICK, asteroidDelayTimer, "asteroidDelay");
	advEvent.listen(EVENT_TIMER_TICK, gunRotate, "gunRotate");
	advEvent.listen(EVENT_MOUSE_PRESS, gunShoot, sf::Mouse::Left);
	advEvent.listen(EVENT_TIMER_TICK, ammoRestock, "ammoRestock");
	advEvent.listen(EVENT_TIMER_TICK, shieldRestock, "shieldRestock");
	advEvent.listen(EVENT_TIMER_END, shieldDown, "shieldDown");

	// Initialize background
	background.moveto(vec2f(0, 0));
	background.resize(vec2f(800, 800));
	background.texturize(advTexture.add("background.png"));
	// Initialize our base
	base.moveto(vec2f(400, 400));
	base.resize(vec2f(30, 34));
	base.centralize(vec2f(15, 17));
	base.texturize(advTexture.add("base.png"));
	// Initialize our gun
	gun.moveto(vec2f(400, 400));
	gun.resize(vec2f(20, 6));
	gun.centralize(vec2f(3, 3));
	gun.texturize(advTexture.add("ui_icon_empty_orange_24.png"));

	// Create test UI
	advUI.addFont("font_main_16", "consola.ttf", 16);
	advUI.addFont("font_main_24", "consola.ttf", 24);
	advUI.addFont("font_main_32", "consola.ttf", 32);
	cUIWindow* wnd = advUI.addWindow("main", vec2f(0, 0));
	wnd->addLabel("counter", vec2f(5, 0), "Score: 0", "font_main_16", color(255, 255, 255));
	wnd->addLabel("bullets", vec2f(5, 20), "Bullets: " + to_string(bullets), "font_main_16", color(255, 255, 255));
	wnd->addLabel("shield", vec2f(5, 40), "Shield: Izolenta", "font_main_16", color(255, 255, 255));

	// Create window
	advCore.addThread(windowThread, -1);
}*/
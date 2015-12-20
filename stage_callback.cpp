
#include "stdafx.h"
#include "stage.h"

using namespace std;

void mouse_resetActive(adv::cEventArgs args)
{
	string id = to_string(stage.selected.x) + to_string(stage.selected.y);
	adv::cUIWindow* wnd = advUI.getWindow("wndStage1Content");
	wnd->setButtonTexture(id, advTexture.add("ui_bigbtn.png"));
	wnd->setButtonHoverTexture(id, advTexture.add("ui_bigbtn_hover.png"));
	wnd->setButtonTextColor(id, color(200, 200, 200));
	wnd->setButtonHoverTextColor(id, color(255, 255, 255));
	stage.selected = vec2i(-1, -1);
}

void key_hotkeys(adv::cEventArgs args)
{
	if (args.id == sf::Keyboard::F1) { stage.set(0); }
	else if (args.id == sf::Keyboard::F2) { stage.set(1); }
	else if (args.id == sf::Keyboard::F3) { stage.set(2); }
	// Hide or unhide
	else if (args.id == sf::Keyboard::Delete && !sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
		adv::cUIWindow* wnd = advUI.getWindow("wndStage1Content");
		wnd->showElement(to_string(stage.selected.x) + to_string(stage.selected.y), TYPE_BUTTON, toggle);
		stage.s1_musicActive = vec2i(-1, -1);
		stage.s1_updateStatusLabel();
	}
	// Full restore
	else if (args.id == sf::Keyboard::Delete && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		adv::cUIWindow* wnd = advUI.getWindow("wndStage1Content");
		for (int y = 0; y < 7; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				wnd->showElement(to_string(x) + to_string(y), TYPE_BUTTON, true);
			}
		}
	}
	// Start music [Stage 1]
	else if (args.id == sf::Keyboard::Space && stage.current == 1) {
		stage.s1_toggleMusic(stage.selected);
	}
	// Show answer
	else if (args.id == sf::Keyboard::Return) {
		stage.s1_showAnswer(stage.selected);
	}
}

void uibtn_offsetTo(adv::cEventArgs args)
{
	if (stage.current == 2) { return; }

	vector<adv::cUIElement*> data = advUI.findByName(args.name, TYPE_BUTTON);
	for (int i = 0; i < (int)data.size(); i++) {
		data[i]->move(vec2f(1, 1));
	}
}

void uibtn_offsetFrom(adv::cEventArgs args)
{
	if (stage.current == 2) { return; }

	vector<adv::cUIElement*> data = advUI.findByName(args.name, TYPE_BUTTON);
	for (int i = 0; i < (int)data.size(); i++) {
		data[i]->move(vec2f(-1, -1));
	}
}

void uibtn_addScore(adv::cEventArgs args)
{
	int mod = 1;
	if (args.id == sf::Mouse::Right) { mod = -1; }

	int score = 100;
	if (stage.selected != vec2i(-1, -1)) { score *= (float)stage.selected.x + 1; }
	score *= mod;
	// Change the score
	if (args.name == "nameA") { stage.score[0] += score; }
	else if (args.name == "nameB") { stage.score[1] += score; }
	else if (args.name == "nameC") { stage.score[2] += score; }
	else if (args.name == "nameD") { stage.score[3] += score; }

	// Update the interface
	adv::cUIWindow* wnd = advUI.getWindow("wndScore");
	wnd->setLabelText("scoreA", to_wstring(stage.score[0]));
	wnd->setLabelText("scoreB", to_wstring(stage.score[1]));
	wnd->setLabelText("scoreC", to_wstring(stage.score[2]));
	wnd->setLabelText("scoreD", to_wstring(stage.score[3]));
}

void uibtn_selectActive(adv::cEventArgs args)
{
	if (args.name.length() > 2) { return; }

	string id = to_string(stage.selected.x) + to_string(stage.selected.y);
	adv::cUIWindow* wnd = advUI.getWindow("wndStage1Content");
	wnd->setButtonTexture(id, advTexture.add("ui_bigbtn.png"));
	wnd->setButtonHoverTexture(id, advTexture.add("ui_bigbtn_hover.png"));
	wnd->setButtonTextColor(id, color(200, 200, 200));
	wnd->setButtonHoverTextColor(id, color(255, 255, 255));

	string sub = args.name.substr(0, 1);
	stage.selected.x = stoi(sub);
	sub = args.name.substr(1, 1);
	stage.selected.y = stoi(sub);

	id = to_string(stage.selected.x) + to_string(stage.selected.y);
	wnd->setButtonTexture(id, advTexture.add("ui_selbtn.png"));
	wnd->setButtonHoverTexture(id, advTexture.add("ui_selbtn_hover.png"));
	wnd->setButtonTextColor(id, color(100, 100, 100));
	wnd->setButtonHoverTextColor(id, color(0, 0, 0));
}
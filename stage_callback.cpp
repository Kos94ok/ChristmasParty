
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
	// Start music [Stage 2]
	else if (args.id == sf::Keyboard::Space && stage.current == 2) {
		stage.s2_toggleMusic();
	}
	// Show answer
	else if (args.id == sf::Keyboard::Return && !advInput.isEnabled()) {
		stage.s1_showAnswer(stage.selected);
	}
	// Accept new player
	else if (args.id == sf::Keyboard::Return && advInput.isEnabled() && advInput.getId() == "newPlayer") {
		advInput.close();
		advUI.getWindow("wndScore")->showElement("caret", TYPE_IMAGE, false);
		advUI.getWindow("wndScore")->showElement("score" + to_string(stage.players - 1), TYPE_LABEL, true);
	}
	// Previous question [Stage 2]
	else if (args.id == sf::Keyboard::Left && stage.current == 2) {
		stage.s2_currentQuest -= 1;
		if (stage.s2_currentQuest < 0) { stage.s2_currentQuest = 0; }

		stage.s2_showQuestion(stage.s2_currentQuest);
	}
	// Next question [Stage 2]
	else if (args.id == sf::Keyboard::Right && stage.current == 2) {
		stage.s2_currentQuest += 1;
		if (stage.s2_currentQuest > 20) { stage.s2_currentQuest = 20; }

		stage.s2_showQuestion(stage.s2_currentQuest);
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
	if (args.name.substr(0, 4) != "name") { return; }

	int mod = 1;
	if (args.id == sf::Mouse::Right) { mod = -1; }

	int score = 100;
	if (stage.selected != vec2i(-1, -1)) { score *= (float)stage.selected.x + 1; }
	score *= mod;
	// Change the score
	int index = math.stringToInt(args.name.substr(4, 1));
	stage.score[index] += score;

	// Update the interface
	adv::cUIWindow* wnd = advUI.getWindow("wndScore");
	for (int i = 0; i < 8; i++) {
		wnd->setLabelText("score" + to_string(i), to_wstring(stage.score[i]));
	}
}

void uibtn_selectActive(adv::cEventArgs args)
{
	if (args.name.length() > 2 || stage.current != 1) { return; }

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

void uibtn_s2_answer(adv::cEventArgs args)
{
	int sel = 0;
	if (args.name == "st2_btn_a") { sel = 0; }
	else if (args.name == "st2_btn_b") { sel = 1; }
	else if (args.name == "st2_btn_c") { sel = 2; }
	else if (args.name == "st2_btn_d") { sel = 3; }
	else { return; }
	stage.s2_showAnswer(sel);
}

void uibtn_newPlayer(adv::cEventArgs args)
{
	if (args.name != "newPlayer" || advInput.isEnabled()) { return; }

	if (stage.players < 8 && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		stage.players += 1;
		stage.playerName[stage.players - 1] = L"";
		advInput.open("newPlayer", INPUT_TEXT);

		advUI.getWindow("wndScore")->setButtonTextString("name" + to_string(stage.players - 1), L"- :");
		advUI.getWindow("wndScore")->setButtonPos("newPlayer", advUI.getWindow("wndScore")->getButtonPos("newPlayer") + vec2f(0, 40));
		advUI.getWindow("wndScore")->showElement("name" + to_string(stage.players - 1), TYPE_BUTTON, true);
		advUI.getWindow("wndScore")->showElement("caret", TYPE_IMAGE, true);
		advUI.getWindow("wndScore")->setImagePos("caret", advInput.getCaretPos("font_score", 0, L"- ") + vec2f(20, 20 + 40 * stage.players - 1));
	}
	else if (stage.players > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		advUI.getWindow("wndScore")->showElement("name" + to_string(stage.players - 1), TYPE_BUTTON, false);
		advUI.getWindow("wndScore")->showElement("score" + to_string(stage.players - 1), TYPE_LABEL, false);
		advUI.getWindow("wndScore")->setButtonPos("newPlayer", advUI.getWindow("wndScore")->getButtonPos("newPlayer") - vec2f(0, 40));
		stage.players -= 1;
	}
}

void input_newPlayerName(adv::cEventArgs args)
{
	if (args.name != "newPlayer") { return; }

	advUI.getWindow("wndScore")->setImagePos("caret", advInput.getCaretPos("font_score", 0, L"- ") + vec2f(20, 20 + 40 * stage.players));
	advUI.getWindow("wndScore")->setButtonTextString("name" + to_string(stage.players - 1), L"- " + advInput.getString() + L":");
}
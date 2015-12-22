
#include "stdafx.h"
#include "stage.h"

cStageMain stage;

void cStageMain::set(int number)
{
	current = number;
	advUI.getWindow("wndIntro")->show(false);
	advUI.getWindow("wndStage1")->show(false);
	advUI.getWindow("wndStage2")->show(false);
	advUI.getWindow("wndScore")->show(false);
	if (current == 0) { advUI.getWindow("wndIntro")->show(true); advUI.getWindow("wndScore")->show(true); }
	if (current == 1) { advUI.getWindow("wndStage1")->show(true); advUI.getWindow("wndScore")->show(true); }
	if (current == 2) { advUI.getWindow("wndStage2")->show(true); advUI.getWindow("wndScore")->show(true); }
}

void cStageMain::init()
{
	// Stage main
	advEvent.listen(EVENT_UIBTN_RELEASE, uibtn_addScore);
	advEvent.listen(EVENT_NOBTN_PRESS, mouse_resetActive);
	advEvent.listen(EVENT_KEY_PRESS, key_hotkeys);
	advEvent.listen(EVENT_UIBTN_PRESS, uibtn_offsetTo);
	advEvent.listen(EVENT_UIBTN_RELEASE, uibtn_offsetFrom);
	advEvent.listen(EVENT_UIBTN_PRESS, uibtn_selectActive);
	advEvent.listen(EVENT_UIBTN_RELEASE, uibtn_s2_answer);
	advEvent.listen(EVENT_UIBTN_RELEASE, uibtn_newPlayer);
	advEvent.listen(EVENT_INPUT_UPDATE, input_newPlayerName);

	// Stage 1 events

	// Preload some textures to prevent lags on runtime
	advTexture.add("ui_selbtn.png");
	advTexture.add("ui_selbtn_hover.png");

	// Create stage UI
	advUI.addFont("font_main", "calibri.ttf", 40);
	advUI.addFont("font_cat", "segoeprb.ttf", 30);
	advUI.addFont("font_score", "segoeprb.ttf", 30);
	advUI.addFont("font_scoreTitle", "segoeprb.ttf", 36);
	advUI.addFont("font_console", "consola.ttf", 16);
	advUI.addFont("font_answer", "calibri.ttf", 50);
	adv::cUIWindow* wnd;

	// Intro window
	wnd = advUI.addWindow("wndIntro", vec2f(0, 0), advUI.desktopSize);

	init_stage1();
	init_stage2();

	// Score window
	stage.players = 4;
	stage.playerName[0] = L"Моника";
	stage.playerName[1] = L"Саша";
	stage.playerName[2] = L"Сергей";
	stage.playerName[3] = L"Стелла";

	wnd = advUI.addWindow("wndScore", vec2f(advUI.desktopSize.x - 300, 0));
	wnd->addLabelOutline("scoreTitle*", vec2f(0, 0), L"Очки:", "font_scoreTitle", color(0, 0, 255));
	wnd->addLabel("scoreTitle", vec2f(0, 0), L"Очки:", "font_scoreTitle", color(255, 255, 255));

	for (int i = 0; i < 8; i++) {
		wnd->addButton("name" + to_string(i), vec2f(20, 60 + i * 40), vec2f(200, 30), "name" + to_string(i));
		wnd->addButtonText("name" + to_string(i), L"- :", "font_score", color(255, 255, 255), ALIGN_MID);
		wnd->addButtonHover("name" + to_string(i), -1, 0.20f, color(255, 150, 0));
		wnd->showElement("name" + to_string(i), TYPE_BUTTON, false);

		wnd->addLabel("score" + to_string(i), vec2f(200, 50 + i * 40), L"0", "font_score", color(255, 255, 255));
		wnd->showElement("score" + to_string(i), TYPE_LABEL, false);
	}

	for (int i = 0; i < stage.players; i++) {
		wnd->setButtonTextString("name" + to_string(i), L"- " + stage.playerName[i] + L":");
		wnd->showElement("name" + to_string(i), TYPE_BUTTON, true);
		wnd->showElement("score" + to_string(i), TYPE_LABEL, true);
	}

	wnd->addButton("newPlayer", vec2f(20, 220), vec2f(200, 10), "newPlayer");
	wnd->addButtonHover("newPlayer", advTexture.add("white.png"), 0.50f);

	wnd->addImage("caret", vec2f(0, 0), vec2f(2, 20), advTexture.add("ui_border_right.png"));
	wnd->showElement("caret", TYPE_IMAGE, false);
	wnd->show(false);

	// Answer window
	wnd = advUI.addWindow("wndAnswer", advUI.desktopSize / 2.f, vec2f(1400, 200), ALIGN_CENTER | ALIGN_MID);
	wnd->addImage("answerBG", vec2f(0, 0), wnd->size, advTexture.add("black.png"));
	wnd->addBorder("answerBorder_*", vec2f(0, 0), wnd->size, "ui_border_*.png");
	wnd->addLabel("answerL0", wnd->size / 2.f - vec2f(0, 20), L"", "font_answer", color(255, 255, 255), ALIGN_CENTER | ALIGN_MID);
	wnd->show(false);
}
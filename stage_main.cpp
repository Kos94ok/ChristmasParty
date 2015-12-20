
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
	if (current == 0) { advUI.getWindow("wndIntro")->show(true); }
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
	wnd = advUI.addWindow("wndScore", vec2f(advUI.desktopSize.x - 300, 0));
	wnd->addLabelOutline("scoreTitle*", vec2f(0, 0), L"Очки:", "font_scoreTitle", color(0, 0, 255));
	wnd->addLabel("scoreTitle", vec2f(0, 0), L"Очки:", "font_scoreTitle", color(255, 255, 255));

	wnd->addButton("nameA", vec2f(20, 60), vec2f(200, 30), "nameA");
	wnd->addButtonText("nameA", L"- Моника:", "font_score", color(255, 255, 255), ALIGN_MID);
	wnd->addButtonHover("nameA", -1, 0.20f, color(255, 150, 0));

	wnd->addButton("nameB", vec2f(20, 100), vec2f(200, 30), "nameB");
	wnd->addButtonText("nameB", L"- Саша:", "font_score", color(255, 255, 255), ALIGN_MID);
	wnd->addButtonHover("nameB", -1, 0.20f, color(255, 150, 0));

	wnd->addButton("nameC", vec2f(20, 140), vec2f(200, 30), "nameC");
	wnd->addButtonText("nameC", L"- Сергей:", "font_score", color(255, 255, 255), ALIGN_MID);
	wnd->addButtonHover("nameC", -1, 0.20f, color(255, 150, 0));

	wnd->addButton("nameD", vec2f(20, 180), vec2f(200, 30), "nameD");
	wnd->addButtonText("nameD", L"- Стелла:", "font_score", color(255, 255, 255), ALIGN_MID);
	wnd->addButtonHover("nameD", -1, 0.20f, color(255, 150, 0));

	wnd->addLabel("scoreA", vec2f(200, 50), L"0", "font_score", color(255, 255, 255));
	wnd->addLabel("scoreB", vec2f(200, 90), L"0", "font_score", color(255, 255, 255));
	wnd->addLabel("scoreC", vec2f(200, 130), L"0", "font_score", color(255, 255, 255));
	wnd->addLabel("scoreD", vec2f(200, 170), L"0", "font_score", color(255, 255, 255));
	wnd->show(false);

	// Answer window
	wnd = advUI.addWindow("wndAnswer", advUI.desktopSize / 2.f, vec2f(1400, 200), ALIGN_CENTER | ALIGN_MID);
	wnd->addImage("answerBG", vec2f(0, 0), wnd->size, advTexture.add("black.png"));
	wnd->addBorder("answerBorder_*", vec2f(0, 0), wnd->size, "ui_border_*.png");
	wnd->addLabel("answerL0", wnd->size / 2.f - vec2f(0, 20), L"", "font_answer", color(255, 255, 255), ALIGN_CENTER | ALIGN_MID);
	wnd->show(false);
}
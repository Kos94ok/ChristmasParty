
#include "stdafx.h"
#include "stage.h"

void cStageMain::init_stage2()
{
	adv::cUIWindow* wnd = advUI.addWindow("wndStage2", vec2f(0, 0), advUI.desktopSize);
	
	wnd->addImage("st2_bg", vec2f(0, 0), wnd->size, advTexture.add("background.png"));

	wnd->show(false);
	
	wnd = wnd->addWindow("wndStage2Content", vec2f(0, 600), vec2f(wnd->size.x, wnd->size.y - 600));
	wnd->addImage("st2_question_bg", vec2f(0, 0), vec2f(wnd->size.x, wnd->size.x / 12.55f), advTexture.add("ui_st2_question.png"));

	wnd = wnd->addWindow("wndStage2Answers", vec2f(0, wnd->size.x / 12.55f + 50.f), wnd->size);
	float imageSize = wnd->size.x * 0.27f / 2.f;
	float buttonDifY = 110.f;
	float buttonY = 86.f;
	wnd->addImage("st2_btn_lt", vec2f(0, buttonY / 2), vec2f(imageSize, 7), advTexture.add("ui_st2_btn_left.png"), ALIGN_MID);
	wnd->addButton("st2_btn_a", vec2f(imageSize, 0), vec2f(wnd->size.x / 2.f - imageSize, buttonY), "st2_btn_a", advTexture.add("ui_st2_btn_a.png"));
	wnd->addImage("st2_btn_rt", vec2f(wnd->size.x, buttonY / 2), vec2f(imageSize, 5), advTexture.add("ui_st2_btn_right.png"), ALIGN_RIGHT | ALIGN_MID);
	wnd->addButton("st2_btn_b", vec2f(wnd->size.x / 2.f, 0), vec2f(wnd->size.x / 2.f - imageSize + 5, buttonY), "st2_btn_b", advTexture.add("ui_st2_btn_b.png"));

	wnd->addImage("st2_btn_lb", vec2f(0, buttonY / 2 + buttonDifY), vec2f(imageSize, 7), advTexture.add("ui_st2_btn_left.png"), ALIGN_MID);
	wnd->addButton("st2_btn_c", vec2f(imageSize, buttonDifY), vec2f(wnd->size.x / 2.f - imageSize, buttonY), "st2_btn_c", advTexture.add("ui_st2_btn_c.png"));
	wnd->addImage("st2_btn_rb", vec2f(wnd->size.x, buttonY / 2 + buttonDifY), vec2f(imageSize, 5), advTexture.add("ui_st2_btn_right.png"), ALIGN_RIGHT | ALIGN_MID);
	wnd->addButton("st2_btn_d", vec2f(wnd->size.x / 2.f, buttonDifY), vec2f(wnd->size.x / 2.f - imageSize + 5, buttonY), "st2_btn_d", advTexture.add("ui_st2_btn_d.png"));
}
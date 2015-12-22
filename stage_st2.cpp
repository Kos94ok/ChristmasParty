
#include "stdafx.h"
#include "stage.h"

void cStageMain::init_stage2()
{
	// Stage 2 window
	adv::cUIWindow* wnd = advUI.addWindow("wndStage2", vec2f(0, 0), advUI.desktopSize);
	
	wnd->addImage("st2_bg", vec2f(0, 0), wnd->size, advTexture.add("background.png"));

	wnd->show(false);
	
	wnd = wnd->addWindow("wndStage2Content", vec2f(0, 600), vec2f(wnd->size.x, wnd->size.y - 600));
	wnd->addImage("st2_question_bg", vec2f(0, 0), vec2f(wnd->size.x, wnd->size.x / 12.55f), advTexture.add("ui_st2_question.png"));
	wnd->addLabel("st2_question", vec2f(wnd->size.x / 2.f, wnd->size.x / 12.55f / 2.f), L"", "font_cat", color(255, 255, 255), ALIGN_CENTER | ALIGN_MID);
	wnd->addLabel("st2_questionL0", vec2f(wnd->size.x / 2.f, wnd->size.x / 12.55f / 2.f - 20), L"", "font_cat", color(255, 255, 255), ALIGN_CENTER | ALIGN_MID);
	wnd->addLabel("st2_questionL1", vec2f(wnd->size.x / 2.f, wnd->size.x / 12.55f / 2.f + 20), L"", "font_cat", color(255, 255, 255), ALIGN_CENTER | ALIGN_MID);

	wnd = wnd->addWindow("wndStage2Answers", vec2f(0, wnd->size.x / 12.55f + 50.f), wnd->size);
	float imageSize = wnd->size.x * 0.27f / 2.f;
	float buttonDifY = 110.f;
	float buttonY = 86.f;

	color clrNormal = color(200, 200, 200);
	color clrHover = color(255, 255, 255);
	wnd->addImage("st2_btn_lt", vec2f(0, buttonY / 2), vec2f(imageSize, 7), advTexture.add("ui_st2_btn_left.png"), ALIGN_MID);
	wnd->addButton("st2_btn_a", vec2f(imageSize, 0), vec2f(wnd->size.x / 2.f - imageSize, buttonY), "st2_btn_a", advTexture.add("ui_st2_btn_a.png"));
	wnd->addButtonText("st2_btn_a", L"", "font_score", clrNormal, ALIGN_MID, vec2f(90, 5));
	wnd->addButtonHover("st2_btn_a", -1, 0.20f, clrHover);
	wnd->addImage("st2_btn_rt", vec2f(wnd->size.x, buttonY / 2), vec2f(imageSize, 5), advTexture.add("ui_st2_btn_right.png"), ALIGN_RIGHT | ALIGN_MID);
	wnd->addButton("st2_btn_b", vec2f(wnd->size.x / 2.f, 0), vec2f(wnd->size.x / 2.f - imageSize + 5, buttonY), "st2_btn_b", advTexture.add("ui_st2_btn_b.png"));
	wnd->addButtonText("st2_btn_b", L"", "font_score", clrNormal, ALIGN_MID, vec2f(100, 5));
	wnd->addButtonHover("st2_btn_b", -1, 0.20f, clrHover);

	wnd->addImage("st2_btn_lb", vec2f(0, buttonY / 2 + buttonDifY), vec2f(imageSize, 7), advTexture.add("ui_st2_btn_left.png"), ALIGN_MID);
	wnd->addButton("st2_btn_c", vec2f(imageSize, buttonDifY), vec2f(wnd->size.x / 2.f - imageSize, buttonY), "st2_btn_c", advTexture.add("ui_st2_btn_c.png"));
	wnd->addButtonText("st2_btn_c", L"", "font_score", clrNormal, ALIGN_MID, vec2f(90, 5));
	wnd->addButtonHover("st2_btn_c", -1, 0.20f, clrHover);
	wnd->addImage("st2_btn_rb", vec2f(wnd->size.x, buttonY / 2 + buttonDifY), vec2f(imageSize, 5), advTexture.add("ui_st2_btn_right.png"), ALIGN_RIGHT | ALIGN_MID);
	wnd->addButton("st2_btn_d", vec2f(wnd->size.x / 2.f, buttonDifY), vec2f(wnd->size.x / 2.f - imageSize + 5, buttonY), "st2_btn_d", advTexture.add("ui_st2_btn_d.png"));
	wnd->addButtonText("st2_btn_d", L"", "font_score", clrNormal, ALIGN_MID, vec2f(100, 5));
	wnd->addButtonHover("st2_btn_d", -1, 0.20f, clrHover);

	// Stage 2 questions
	int a = 0;
	stage.s2_addQuestion(a++, L"Вы готовы ко второму туру?", L"", L"Да", L"Нет", L"Наверное", L"Не знаю", 0);

	stage.s2_addQuestion(a++, L"Какая лягушка съела известного кузнечика?", L"",
		L"Немаленькая тушка", L"Прожорливое брюшко", L"Проколотое ушко", L"Поджаренная сушка", 1);

	stage.s2_addQuestion(a++, L"Что пел Винни Пух, поднимаясь на шарике", L"вверх за медом?",
		L"\"Кажется, дождик собирается\"", L"\"Я тучка, я вовсе не медведь\"", L"\"У природы нет плохой погоды\"", L"\"Ёжик в тумане\"", 1);

	stage.s2_addQuestion(a++, L"Кто из этих композиторов не мог услышать", L"собственных музыкальных произведений?",
		L"Людвиг ван Бетховен", L"Вольганг Амадей Моцарт", L"Пётр Ильич Чайковский", L"Антонио Вивальди", 0);

	stage.s2_addQuestion(a++, L"Сколько различных музыкальных фрагментов", L"прозвучало в первом туре?",
		L"30", L"24", L"32", L"28", 3);

	stage.s2_addQuestion(a++, L"В каком году впервые был проведен музыкальный", L"фестиваль \"Дискотека 80-х\"?",
		L"1998", L"2007", L"2002", L"1990", 2);

	stage.s2_addQuestion(a++, L"Под каким псевдонимом также известен Майкл Джексон?", L"",
		L"Принц поп-музыки", L"Лорд поп-музыки", L"Король поп-музыки", L"Властелин поп-музыки", 2);

	stage.s2_addQuestion(a++, L"♫ Кто исполняет данный музыкальный фрагмент? ♫", L"",
		L"Японская поп-звезда", L"Персонаж японской мультипликации", L"Известная киноактриса", L"Синтезированный голос", 3);
	stage.s2_addQuestionSong(a - 1, "miku.ogg");

	stage.s2_addQuestion(a++, L"♫ Назовите жанр данной композиции. ♫", L"",
		L"House", L"Trap", L"Electro", L"Dubstep", 2);
	stage.s2_addQuestionSong(a - 1, "thefatrat.ogg");

	stage.s2_showQuestion(0);
	stage.s2_currentQuest = 0;
}

void cStageMain::s2_addQuestion(int index, wstring questL0, wstring questL1, wstring A, wstring B, wstring C, wstring D, int correct)
{
	if (questL1 == L"") {
		stage.s2_questDB[index].quest = questL0;
	}
	else {
		stage.s2_questDB[index].questL0 = questL0;
		stage.s2_questDB[index].questL1 = questL1;
	}
	stage.s2_questDB[index].A = A;
	stage.s2_questDB[index].B = B;
	stage.s2_questDB[index].C = C;
	stage.s2_questDB[index].D = D;
	stage.s2_questDB[index].correct = correct;
}

void cStageMain::s2_addQuestionSong(int index, string file)
{
	stage.s2_questDB[index].songFile = file;
}

void cStageMain::s2_showQuestion(int index)
{
	adv::cUIWindow* wnd;
	if (index >= 0 && index <= 20) {
		wnd = advUI.getWindow("wndStage2Content");
		wnd->setLabelText("st2_question", stage.s2_questDB[index].quest);
		wnd->setLabelText("st2_questionL0", stage.s2_questDB[index].questL0);
		wnd->setLabelText("st2_questionL1", stage.s2_questDB[index].questL1);

		wnd = advUI.getWindow("wndStage2Answers");
		wnd->setButtonTextString("st2_btn_a", stage.s2_questDB[index].A);
		wnd->setButtonTextString("st2_btn_b", stage.s2_questDB[index].B);
		wnd->setButtonTextString("st2_btn_c", stage.s2_questDB[index].C);
		wnd->setButtonTextString("st2_btn_d", stage.s2_questDB[index].D);

		wnd->setButtonTexture("st2_btn_a", advTexture.add("ui_st2_btn_a.png"));
		wnd->setButtonTexture("st2_btn_b", advTexture.add("ui_st2_btn_b.png"));
		wnd->setButtonTexture("st2_btn_c", advTexture.add("ui_st2_btn_c.png"));
		wnd->setButtonTexture("st2_btn_d", advTexture.add("ui_st2_btn_d.png"));
	}
	else {
		wnd = advUI.getWindow("wndStage2Content");
		wnd->setLabelText("st2_question", L"");
		wnd->setLabelText("st2_questionL0", L"");
		wnd->setLabelText("st2_questionL1", L"");

		wnd = advUI.getWindow("wndStage2Answers");
		wnd->setButtonTextString("st2_btn_a", L"");
		wnd->setButtonTextString("st2_btn_b", L"");
		wnd->setButtonTextString("st2_btn_c", L"");
		wnd->setButtonTextString("st2_btn_d", L"");
	}
}

void cStageMain::s2_showAnswer(int selected)
{
	if (stage.s2_currentQuest == -1) { return; }

	cout << "!!!" << endl;
	string id = "";
	adv::cUIWindow* wnd = advUI.getWindow("wndStage2Answers");
	// Correct
	if (selected == stage.s2_questDB[stage.s2_currentQuest].correct) {
		if (selected == 0) {
			wnd->setButtonTexture("st2_btn_a", advTexture.add("ui_st2_btn_a_green.png"));
		}
		else if (selected == 1) {
			wnd->setButtonTexture("st2_btn_b", advTexture.add("ui_st2_btn_b_green.png"));
		}
		else if (selected == 2) {
			wnd->setButtonTexture("st2_btn_c", advTexture.add("ui_st2_btn_c_green.png"));
		}
		else if (selected == 3) {
			wnd->setButtonTexture("st2_btn_d", advTexture.add("ui_st2_btn_d_green.png"));
		}
	}
	// Wrong
	else {
		if (selected == 0) {
			wnd->setButtonTexture("st2_btn_a", advTexture.add("ui_st2_btn_a_red.png"));
		}
		else if (selected == 1) {
			wnd->setButtonTexture("st2_btn_b", advTexture.add("ui_st2_btn_b_red.png"));
		}
		else if (selected == 2) {
			wnd->setButtonTexture("st2_btn_c", advTexture.add("ui_st2_btn_c_red.png"));
		}
		else if (selected == 3) {
			wnd->setButtonTexture("st2_btn_d", advTexture.add("ui_st2_btn_d_red.png"));
		}
	}
}

void cStageMain::s2_toggleMusic()
{
	if (stage.s1_music.getStatus() == sf::Music::Playing) {
		stage.s1_music.stop();
	}
	else if (stage.s2_questDB[stage.s2_currentQuest].songFile.length() > 0) {
		stage.s1_music.openFromFile("Data//Music//" + stage.s2_questDB[stage.s2_currentQuest].songFile);
		stage.s1_music.play();
	}
}

#include "stdafx.h"
#include "stage.h"

void cStageMain::init_stage1()
{
	// Stage 1 window
	color mainColor = color(255, 255, 255);
	color outlineColor = color(0, 0, 255);
	adv::cUIWindow* wnd = advUI.addWindow("wndStage1", vec2f(0, 0), advUI.desktopSize);
	wnd->addImage("st1_bg", vec2f(0, 0), advUI.desktopSize, advTexture.add("background_full.png"));

	wnd->addLabelOutline("cat0*", vec2f(20, 150), L"Дискотека 80-х:", "font_cat", outlineColor, ALIGN_MID);
	wnd->addLabel("cat0", vec2f(20, 150), L"Дискотека 80-х:", "font_cat", mainColor, ALIGN_MID);

	wnd->addLabelOutline("cat1*", vec2f(20, 270), L"Кинематограф:", "font_cat", outlineColor, ALIGN_MID);
	wnd->addLabel("cat1", vec2f(20, 270), L"Кинематограф:", "font_cat", mainColor, ALIGN_MID);

	wnd->addLabelOutline("cat2*", vec2f(20, 390), L"Классическая классика:", "font_cat", outlineColor, ALIGN_MID);
	wnd->addLabel("cat2", vec2f(20, 390), L"Классическая классика:", "font_cat", mainColor, ALIGN_MID);

	wnd->addLabelOutline("cat3*", vec2f(20, 510), L"Ну это все знают:", "font_cat", outlineColor, ALIGN_MID);
	wnd->addLabel("cat3", vec2f(20, 510), L"Ну это все знают:", "font_cat", mainColor, ALIGN_MID);

	wnd->addLabelOutline("cat4*", vec2f(20, 630), L"Танцевальная:", "font_cat", outlineColor, ALIGN_MID);
	wnd->addLabel("cat4", vec2f(20, 630), L"Танцевальная:", "font_cat", mainColor, ALIGN_MID);

	wnd->addLabelOutline("cat5*", vec2f(20, 750), L"Дела государственные:", "font_cat", outlineColor, ALIGN_MID);
	wnd->addLabel("cat5", vec2f(20, 750), L"Дела государственные:", "font_cat", mainColor, ALIGN_MID);

	wnd->addLabelOutline("cat6*", vec2f(20, 870), L"Особое место:", "font_cat", outlineColor, ALIGN_MID);
	wnd->addLabel("cat6", vec2f(20, 870), L"Особое место:", "font_cat", mainColor, ALIGN_MID);

	wnd->addLabel("s1_status", vec2f(20, 20), L"", "font_cat", color(255, 255, 255), ALIGN_MID);
	wnd->show(false);
	// Stage 1 music subwindow
	wnd = wnd->addWindow("wndStage1Content", vec2f(420, 100));
	for (int y = 0; y < 7; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			wnd->addButton(
				to_string(x) + to_string(y),
				vec2f(300 * x, 120 * y),
				vec2f(280, 100),
				to_string(x) + to_string(y),
				advTexture.add("ui_bigbtn.png"));
			wnd->addButtonText(
				to_string(x) + to_string(y),
				to_wstring((x + 1) * 100),
				"font_main", color(220, 220, 220), ALIGN_CENTER | ALIGN_MID);
			wnd->addButtonHover(
				to_string(x) + to_string(y),
				advTexture.add("ui_bigbtn_hover.png"),
				0.20f, color(255, 255, 255));
		}
	}
	// Stage 1 music database
		// Cat 0
	s1_addMusic(vec2i(0, 0), "00_100.ogg", L"Максим Леонидов", L"Девочка-видение");
	s1_addMusic(vec2i(1, 0), "00_200.ogg", L"Boney M", L"Rasputin");
	s1_addMusic(vec2i(2, 0), "00_300.ogg", L"Веселые Ребята", L"Уходило лето");
	s1_addMusic(vec2i(3, 0), "00_400.ogg", L"Земляне", L"Трава у дома");
		// Cat 1
	s1_addMusic(vec2i(0, 1), "01_100.ogg", L"Джентельмены удачи", L"Музыка из К/Ф");
	s1_addMusic(vec2i(1, 1), "01_200.ogg", L"Служебный роман", L"У природы нет плохой погоды");
	s1_addMusic(vec2i(2, 1), "01_300.ogg", L"Кин-дза-дза", L"Музыка из К/Ф");
	s1_addMusic(vec2i(3, 1), "01_400.ogg", L"В бой идут одни старики", L"Музыка из К/Ф");
		// Cat 2
	s1_addMusic(vec2i(0, 2), "02_100.ogg", L"Р. Вагнер", L"Полет валькирий");
	s1_addMusic(vec2i(1, 2), "02_200.ogg", L"В.А. Моцарт", L"Симфония 40, часть 1");
	s1_addMusic(vec2i(2, 2), "02_300.ogg", L"Э. Григ", L"В пещере Горного Короля");
	s1_addMusic(vec2i(3, 2), "02_400.ogg", L"И.С. Бах", L"Токката и фуга ре минор");
		// Cat 3
	s1_addMusic(vec2i(0, 3), "03_100.ogg", L"PSY", L"Gangnam Style");
	s1_addMusic(vec2i(1, 3), "03_200.ogg", L"Yolanda be Cool", L"Papa Americano");
	s1_addMusic(vec2i(2, 3), "03_300.ogg", L"Michael Jackson", L"Billie Jean");
	s1_addMusic(vec2i(3, 3), "03_400.ogg", L"Пьер Нарцисс", L"Шоколадный Заяц");
		// Cat 4
	s1_addMusic(vec2i(0, 4), "04_100.ogg", L"Александр Рыбак", L"Fairytale (Remix)");
	s1_addMusic(vec2i(1, 4), "04_200.ogg", L"Дискотека Авария", L"Пей Пиво");
	s1_addMusic(vec2i(2, 4), "04_300.ogg", L"Виктор Цой", L"Звезда по имени Солнце (Remix)");
	s1_addMusic(vec2i(3, 4), "04_400.ogg", L"Crazy Frog", L"Axel F");
		// Cat 5
	s1_addMusic(vec2i(0, 5), "05_100.ogg", L"Государственный гимн", L"СССР");
	s1_addMusic(vec2i(1, 5), "05_200.ogg", L"Государственный гимн", L"США");
	s1_addMusic(vec2i(2, 5), "05_300.ogg", L"Государственный гимн", L"Эстонская ССР");
	s1_addMusic(vec2i(3, 5), "05_400.ogg", L"Государственный гимн", L"Израиль");
		// Cat 6
	s1_addMusic(vec2i(0, 6), "06_100.ogg", L"Игорь Корнелюк", L"Город, которого нет");
	s1_addMusic(vec2i(1, 6), "06_200.ogg", L"Britney Spears", L"Toxic");
	s1_addMusic(vec2i(2, 6), "06_300.ogg", L"Queen", L"We Will Rock You");
	s1_addMusic(vec2i(3, 6), "06_400.ogg", L"Joe Dassin", L"L'ete Indien");
}

void cStageMain::s1_toggleMusic(vec2i pos)
{
	if (s1_music.getStatus() == sf::Music::Playing) {
		stage.s1_stopMusic();
	}
	else {
		stage.s1_playMusic(stage.selected);
	}
	s1_updateStatusLabel();
}

void cStageMain::s1_playMusic(vec2i pos)
{
	// Pos changed
	if (s1_musicActive != pos) {
		s1_musicActive = pos;
		s1_music.stop();
		if (s1_musicDB[pos.x][pos.y].file != "") {
			s1_music.openFromFile("Data//Music//" + s1_musicDB[pos.x][pos.y].file);
			s1_music.play();
		}
		else {
			s1_musicActive = vec2i(-1, -1);
		}
	}
	// Same pos
	else {
		s1_music.play();
	}
}

void cStageMain::s1_stopMusic()
{
	s1_music.pause();
}

void cStageMain::s1_updateStatusLabel()
{
	vector<adv::cUIElement*> elem = advUI.findById("s1_status", TYPE_LABEL);
	if (stage.s1_musicActive != vec2i(-1, -1)) {
		if (stage.s1_music.getStatus() == sf::Music::Playing) {
			elem[0]->setLabelText(L"►");
		}
		else {
			elem[0]->setLabelText(L"▐▐");
		}
	}
	else {
		elem[0]->setLabelText(L"");
	}
}

void cStageMain::s1_addMusic(vec2i pos, string file, wstring nameA, wstring nameB)
{
	s1_musicDB[pos.x][pos.y].file = file;
	s1_musicDB[pos.x][pos.y].nameA = nameA;
	s1_musicDB[pos.x][pos.y].nameB = nameB;
}

void cStageMain::s1_showAnswer(vec2i pos)
{
	adv::cUIWindow* wnd = advUI.getWindow("wndAnswer");
	vector<adv::cUIElement*> elem = advUI.findById("answerL0", TYPE_LABEL);
	if (wnd->isHidden())
	{
		if (s1_musicDB[pos.x][pos.y].file != "")
		{
			wstring text = s1_musicDB[pos.x][pos.y].nameA + L" - " + s1_musicDB[pos.x][pos.y].nameB;
			elem[0]->setLabelText(text);
			wnd->show(true);
		}
	}
	else {
		wnd->show(false);
	}
}
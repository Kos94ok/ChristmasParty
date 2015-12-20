
#pragma once

#include "stdafx.h"

class cMusicDBEntry
{
public:
	string file = "";		// File name
	wstring nameA = L"";	// Group or singer
	wstring nameB = L"";	// Song name
};

class cStageMain
{
public:
	vec2i selected = vec2i(-1, -1);

	int current;
	int score[4];

	vec2i s1_musicActive = vec2i(-1, -1);
	sf::Music s1_music;
	cMusicDBEntry s1_musicDB[8][8];

	void set(int number);
	void init();
	void init_stage1();
	void init_stage2();
	void init_stage3();
	void init_stage4();

	void s1_toggleMusic(vec2i pos);
	void s1_playMusic(vec2i pos);
	void s1_stopMusic();
	void s1_updateStatusLabel();
	void s1_addMusic(vec2i pos, string file, wstring nameA, wstring nameB);
	void s1_showAnswer(vec2i pos);
};

extern cStageMain stage;

void mouse_resetActive(adv::cEventArgs args);
void key_hotkeys(adv::cEventArgs args);
void uibtn_offsetTo(adv::cEventArgs args);
void uibtn_offsetFrom(adv::cEventArgs args);
void uibtn_addScore(adv::cEventArgs args);
void uibtn_selectActive(adv::cEventArgs args);
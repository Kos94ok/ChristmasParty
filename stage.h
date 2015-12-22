
#pragma once

#include "stdafx.h"

class cMusicDBEntry
{
public:
	string file = "";		// File name
	wstring nameA = L"";	// Group or singer
	wstring nameB = L"";	// Song name
};

class cQuestDBEntry
{
public:
	// Single line question
	wstring quest = L"";
	// Double line question
	wstring questL0 = L"";
	wstring questL1 = L"";
	wstring A;
	wstring B;
	wstring C;
	wstring D;
	int correct;
	string songFile = "";
};

class cStageMain
{
public:
	vec2i selected = vec2i(-1, -1);

	int current;

	int players;
	int score[8];
	wstring playerName[8];

	void set(int number);
	void init();
	void init_stage1();
	void init_stage2();
	void init_stage3();
	void init_stage4();

	vec2i s1_musicActive = vec2i(-1, -1);
	sf::Music s1_music;
	cMusicDBEntry s1_musicDB[8][8];

	void s1_toggleMusic(vec2i pos);
	void s1_playMusic(vec2i pos);
	void s1_stopMusic();
	void s1_updateStatusLabel();
	void s1_addMusic(vec2i pos, string file, wstring nameA, wstring nameB);
	void s1_showAnswer(vec2i pos);

	int s2_currentQuest = -1;
	cQuestDBEntry s2_questDB[40];

	void s2_addQuestion(int index, wstring questL0, wstring questL1, wstring A, wstring B, wstring C, wstring D, int correct);
	void s2_addQuestionSong(int index, string file);
	void s2_showQuestion(int index);
	void s2_showAnswer(int selected);
	void s2_toggleMusic();
};

extern cStageMain stage;

void mouse_resetActive(adv::cEventArgs args);
void key_hotkeys(adv::cEventArgs args);
void uibtn_offsetTo(adv::cEventArgs args);
void uibtn_offsetFrom(adv::cEventArgs args);
void uibtn_addScore(adv::cEventArgs args);
void uibtn_selectActive(adv::cEventArgs args);
void uibtn_s2_answer(adv::cEventArgs args);
void uibtn_newPlayer(adv::cEventArgs args);
void input_newPlayerName(adv::cEventArgs args);

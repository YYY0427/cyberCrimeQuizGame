#include "EasyQuiz1CorrectAnswer.h"
#include "EasyQuiz2.h"
#include "EasyQuiz3.h"
#include "EasyQuizSceneMain.h"
#include "DxLib.h"
#include "game.h"

EasyQuiz1CorrectAnswer::EasyQuiz1CorrectAnswer() :
	m_circleHandle(-1),
	m_letterHandle(-1),
	m_waitFrame(0),
	m_bugPreven(false),
	m_randNum(0)
{
}

EasyQuiz1CorrectAnswer::~EasyQuiz1CorrectAnswer()
{
}

void EasyQuiz1CorrectAnswer::init()
{
	m_circleHandle = CreateFontToHandle(NULL, 100, 5);
	m_letterHandle = CreateFontToHandle(NULL, 20, 5);
	m_waitFrame	   = 30;
	m_bugPreven	   = false;
	m_randNum	   = GetRand(1);
}

void EasyQuiz1CorrectAnswer::end()
{

}

SceneBase* EasyQuiz1CorrectAnswer::update()
{
	//すぐにシーンが切り替わるのを防ぐ処理
	if (!m_bugPreven)
	{
		m_waitFrame--;
		if (m_waitFrame <= 0)
		{
			m_bugPreven = true;
		}
	}
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1 && m_bugPreven || CheckHitKey(KEY_INPUT_SPACE) && m_bugPreven)
	{
		return (new EasyQuiz2);
	}
	return this;
}

void EasyQuiz1CorrectAnswer::draw()
{
	//〇の表示
	DrawStringToHandle(Game::kScreenWidth / 2 - 55, Game::kScreenHeight / 2 - 100, "〇", GetColor(255, 0, 0), m_circleHandle);
	DrawStringToHandle(Game::kScreenWidth / 2 - 180, Game::kScreenHeight / 2 + 50, "Aボタン or SPACEキーを押してください", GetColor(255, 255, 255), m_letterHandle);
}
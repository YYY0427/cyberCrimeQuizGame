#include "EasyQuiz3CorrectAnswer.h"
#include "DxLib.h"
#include "game.h"
#include "EasyQuiz3.h"

EasyQuiz3CorrectAnswer::EasyQuiz3CorrectAnswer() :
	m_circleHandle(-1),
	m_letterHandle(-1),
	m_waitFrame(0),
	m_bugPreven(false)
{
}

EasyQuiz3CorrectAnswer::~EasyQuiz3CorrectAnswer()
{
}

void EasyQuiz3CorrectAnswer::init()
{
	m_circleHandle = CreateFontToHandle(NULL, 100, 5);
	m_letterHandle = CreateFontToHandle(NULL, 20, 5);
	m_waitFrame = 30;
	m_bugPreven = false;
}

void EasyQuiz3CorrectAnswer::end()
{

}

SceneBase* EasyQuiz3CorrectAnswer::update()
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
		return (new EasyQuiz3);
	}

	return this;
}

void EasyQuiz3CorrectAnswer::draw()
{
	//〇の表示
	DrawStringToHandle(Game::kScreenWidth / 2 - 55, Game::kScreenHeight / 2 - 100, "〇", GetColor(255, 0, 0), m_circleHandle);
	DrawStringToHandle(Game::kScreenWidth / 2 - 180, Game::kScreenHeight / 2 + 50, "Aボタン or SPACEキーを押してください", GetColor(255, 255, 255), m_letterHandle);
}
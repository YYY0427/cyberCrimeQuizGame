#include "EasyQuiz2IncorrectAnswer.h"
#include "DxLib.h"
#include "game.h"
#include "EasyQuiz3.h"

EasyQuiz2IncorrectAnswer::EasyQuiz2IncorrectAnswer() :
	m_crossHandle(-1),
	m_letterHandle(-1),
	m_waitFrame(0),
	m_bugPreven(false)
{
}

EasyQuiz2IncorrectAnswer::~EasyQuiz2IncorrectAnswer()
{
}

void EasyQuiz2IncorrectAnswer::init()
{
	m_crossHandle = CreateFontToHandle(NULL, 100, 5);
	m_letterHandle = CreateFontToHandle(NULL, 20, 5);
	m_waitFrame = 30;
	m_bugPreven = false;
}

void EasyQuiz2IncorrectAnswer::end()
{

}

SceneBase* EasyQuiz2IncorrectAnswer::update()
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

void EasyQuiz2IncorrectAnswer::draw()
{
	//×の表示
	DrawStringToHandle(Game::kScreenWidth / 2 - 55, Game::kScreenHeight / 2 - 100, "×", GetColor(30, 144, 255), m_crossHandle);
	DrawStringToHandle(Game::kScreenWidth / 2 - 180, Game::kScreenHeight / 2 + 50, "Aボタン or SPACEキーを押してください", GetColor(255, 255, 255), m_letterHandle);
}
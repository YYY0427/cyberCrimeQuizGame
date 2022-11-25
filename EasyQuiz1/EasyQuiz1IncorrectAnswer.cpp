#include "EasyQuiz1IncorrectAnswer.h"
#include "DxLib.h"
#include "game.h"

EasyQuiz1IncorrectAnswer::EasyQuiz1IncorrectAnswer() :
	m_crossHandle(-1)
{
}

EasyQuiz1IncorrectAnswer::~EasyQuiz1IncorrectAnswer()
{
}

void EasyQuiz1IncorrectAnswer::init()
{
	m_crossHandle = CreateFontToHandle(NULL, 100, 5);
}

void EasyQuiz1IncorrectAnswer::end()
{

}

SceneBase* EasyQuiz1IncorrectAnswer::update()
{
	return this;
}

void EasyQuiz1IncorrectAnswer::draw()
{
	//Å~ÇÃï\é¶
	DrawStringToHandle(Game::kScreenWidth / 2 - 55, Game::kScreenHeight / 2 - 100, "Å~", GetColor(30, 144, 255), m_crossHandle);
}
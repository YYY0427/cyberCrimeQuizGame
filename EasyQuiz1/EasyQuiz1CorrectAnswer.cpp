#include "EasyQuiz1CorrectAnswer.h"
#include "DxLib.h"
#include "game.h"

EasyQuiz1CorrectAnswer::EasyQuiz1CorrectAnswer() :
	m_circleHandle(-1)
{
}

EasyQuiz1CorrectAnswer::~EasyQuiz1CorrectAnswer()
{
}

void EasyQuiz1CorrectAnswer::init()
{
	m_circleHandle = CreateFontToHandle(NULL, 100, 5);
}

void EasyQuiz1CorrectAnswer::end()
{

}

SceneBase* EasyQuiz1CorrectAnswer::update()
{
	return this;
}

void EasyQuiz1CorrectAnswer::draw()
{	
	//ÅZÇÃï\é¶
	DrawStringToHandle(Game::kScreenWidth / 2 - 55, Game::kScreenHeight / 2 - 100, "ÅZ", GetColor(255, 0, 0), m_circleHandle);
}
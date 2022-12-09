#include "EasyQuizSceneMain.h"
#include "DxLib.h"
#include "EasyQuiz1.h"
#include "EasyQuiz2.h"
#include "EasyQuiz3.h"

namespace
{
	//–â‘è‚Ì”
	constexpr int problemNum = 3;
}

EasyQuizSceneMain::EasyQuizSceneMain() : 
	m_randNum(0)
{
}

EasyQuizSceneMain::~EasyQuizSceneMain()
{
}

void EasyQuizSceneMain::init()
{
	m_randNum = GetRand(problemNum - 1);
}

SceneBase* EasyQuizSceneMain::update()
{
	switch (m_randNum)
	{
	case 0:
		return (new EasyQuiz1);
		break;
	case 1:
		return (new EasyQuiz2);
		break;
	case 2:
		return (new EasyQuiz3);
		break;
	}

	return this;
}

#pragma once

#include "SceneBase.h"

class EasyQuiz1CorrectAnswer : public SceneBase
{
public:
	EasyQuiz1CorrectAnswer();
	virtual ~EasyQuiz1CorrectAnswer();

	virtual void init() override;

	virtual void end() override;

	virtual SceneBase* update() override;

	virtual void draw() override;

private:

	int		m_circleHandle;				//〇の表示用のフォント
};
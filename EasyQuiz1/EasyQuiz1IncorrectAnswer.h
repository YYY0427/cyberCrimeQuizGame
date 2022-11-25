#pragma once

#include "SceneBase.h"

class EasyQuiz1IncorrectAnswer : public SceneBase
{
public:
	EasyQuiz1IncorrectAnswer();
	virtual ~EasyQuiz1IncorrectAnswer();

	virtual void init() override;

	virtual void end() override;

	virtual SceneBase* update() override;

	virtual void draw() override;

private:

	int		m_crossHandle;				//×の表示用のフォント
};
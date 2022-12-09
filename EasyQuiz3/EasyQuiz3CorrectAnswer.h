#pragma once
#include "SceneBase.h"

class EasyQuiz3CorrectAnswer : public SceneBase
{
public:
	EasyQuiz3CorrectAnswer();
	virtual ~EasyQuiz3CorrectAnswer();

	virtual void init() override;

	virtual void end() override;

	virtual SceneBase* update() override;

	virtual void draw() override;

private:

	int		m_circleHandle;				//〇の表示用のフォント
	int		m_letterHandle;				//文字表示用のフォント
	int		m_waitFrame;				//バグ防止用
	bool	m_bugPreven;				//バグ防止用
};
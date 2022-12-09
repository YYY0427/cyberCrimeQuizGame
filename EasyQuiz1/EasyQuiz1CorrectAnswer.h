#pragma once

#include "SceneBase.h"
#include "SceneTitle.h"

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

	int		m_circleHandle;			//〇の表示用のフォント
	int		m_letterHandle;			//文字表示用のフォント
	int		m_waitFrame;			//バグ防止用
	bool	m_bugPreven;			//バグ防止用
	int		m_randNum;				//ランダムな数字	
};
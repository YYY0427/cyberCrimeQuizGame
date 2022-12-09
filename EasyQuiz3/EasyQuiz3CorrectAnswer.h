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

	int		m_circleHandle;				//�Z�̕\���p�̃t�H���g
	int		m_letterHandle;				//�����\���p�̃t�H���g
	int		m_waitFrame;				//�o�O�h�~�p
	bool	m_bugPreven;				//�o�O�h�~�p
};
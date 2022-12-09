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

	int		m_circleHandle;			//�Z�̕\���p�̃t�H���g
	int		m_letterHandle;			//�����\���p�̃t�H���g
	int		m_waitFrame;			//�o�O�h�~�p
	bool	m_bugPreven;			//�o�O�h�~�p
	int		m_randNum;				//�����_���Ȑ���	
};
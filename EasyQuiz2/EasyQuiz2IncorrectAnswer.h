#pragma once
#include "SceneBase.h"

class EasyQuiz2IncorrectAnswer : public SceneBase
{
public:
	EasyQuiz2IncorrectAnswer();
	virtual ~EasyQuiz2IncorrectAnswer();

	virtual void init() override;

	virtual void end() override;

	virtual SceneBase* update() override;

	virtual void draw() override;

private:

	int		m_crossHandle;				//�~�̕\���p�̃t�H���g
	int		m_letterHandle;				//�����\���p�̃t�H���g
	int		m_waitFrame;				//�o�O�h�~�p
	bool	m_bugPreven;				//�o�O�h�~�p
};
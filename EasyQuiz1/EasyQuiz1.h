#pragma once

#include "SceneBase.h"

class EasyQuiz1 : public SceneBase
{
public:
	EasyQuiz1();
	virtual ~EasyQuiz1();

	virtual void init() override;

	virtual void end() override;

	virtual SceneBase* update() override;

	virtual void draw() override;

private:
	int		m_choiceHandle;				//�I�����\���p�̃t�H���g

	int		m_problemNumHandle;			//�扽�₩�̕\���p�̃t�H���g

	int		m_problemStatemenHandle;	//��蕶�\���p�̃t�H���g

	int		m_nowSelect;				//�ǂ̍��ڂ�I�����Ă��邩

	int		m_selectInterval;			//�R���g���[���[�̑���̃C���^�[�o��

	int		m_selectPosY;				//���̕\���ʒuX

	int		m_selectPosX;				//���̕\���ʒuY

	int		m_timeBoxPosX;				//���̍���X���W

	float	m_timeBoxPosX2;				//���̉E��X���W

	bool	m_bugPreven;				//�o�O�h�~�p

	int		m_waitFrame;				//�o�O�h�~�p

	int		m_startTime;				//�X�^�[�g���Ԃ̎擾

	int		m_nowTime;					//���݂̎��Ԃ̎擾
};


#pragma once

#include "SceneBase.h"

class SceneSelect : public SceneBase
{
public:
	SceneSelect();
	virtual ~SceneSelect();

	virtual void init() override;

	virtual void end() override {}

	virtual SceneBase* update() override;

	virtual void draw() override;
private:

	int		m_nowSelect;		//�ǂ̍��ڂ�I�����Ă��邩

	int		m_selectInterval;	//�R���g���[���[�̑���̃C���^�[�o��

	int		m_selectPosY;		//���̕\���ʒu

	bool	m_bugPreven;		//�o�O�h�~�p

	int		m_waitFrame;		//�o�O�h�~�p
};
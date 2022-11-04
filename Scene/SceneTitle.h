#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle();
	
	virtual void init() override;

	virtual void end() override {}

	virtual SceneBase* update() override;

	virtual void draw() override;

private:

	int		m_nowSelect;		//�ǂ̍��ڂ�I�����Ă��邩

	int		m_selectInterval;	//�R���g���[���[�̑���̃C���^�[�o��

	int		m_selectPosY;		//���̕\���ʒu
};
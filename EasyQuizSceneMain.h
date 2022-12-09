#pragma once
#include "SceneBase.h"

class EasyQuizSceneMain : public SceneBase
{
public:
	EasyQuizSceneMain();
	virtual ~EasyQuizSceneMain();

	virtual void init();

	virtual void end() override {}

	virtual SceneBase* update() override;
private:
	int		m_randNum;			//ƒ‰ƒ“ƒ_ƒ€‚È”š
};
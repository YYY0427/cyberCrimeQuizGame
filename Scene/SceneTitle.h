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

	int		m_nowSelect;		//どの項目を選択しているか

	int		m_selectInterval;	//コントローラーの操作のインターバル

	int		m_selectPosY;		//■の表示位置
};
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
	int		m_choiceHandle;				//選択肢表示用のフォント

	int		m_problemNumHandle;			//第何問かの表示用のフォント

	int		m_problemStatemenHandle;	//問題文表示用のフォント

	int		m_nowSelect;				//どの項目を選択しているか

	int		m_selectInterval;			//コントローラーの操作のインターバル

	int		m_selectPosY;				//■の表示位置X

	int		m_selectPosX;				//■の表示位置Y

	int		m_timeBoxPosX;				//箱の左上X座標

	float	m_timeBoxPosX2;				//箱の右下X座標

	bool	m_bugPreven;				//バグ防止用

	int		m_waitFrame;				//バグ防止用

	int		m_startTime;				//スタート時間の取得

	int		m_nowTime;					//現在の時間の取得
};


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

	int		m_circleHandle;				//〇の表示用のフォント

	int		m_crossHandle;				//×の表示用のフォント

	int		m_problemNumHandle;			//第何問かの表示用のフォント

	int		m_problemStatemenHandle;	//問題文表示用のフォント

	int		m_nowSelect;				//どの項目を選択しているか

	int		m_selectInterval;			//コントローラーの操作のインターバル

	int		m_selectPosY;				//■の表示位置

	bool	m_bugPreven;				//バグ防止用

	int		m_waitFrame;				//バグ防止用

	bool	m_answerDisplay;			//〇か×かの表示の判断

	bool	m_selection;				//解答を選択したか
};


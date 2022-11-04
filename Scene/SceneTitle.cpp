#include "DxLib.h"

#include "SceneTitle.h"
#include "SceneManager.h"
#include "SceneSelect.h"
#include "game.h"

namespace
{
	//メニューの数
	constexpr int kMenuNum = 2;
	//コントローラーの操作のインターバル
	constexpr int kSelectInterval = 10;
	//STARTの表示位置
	constexpr int kLetterPosX = Game::kScreenWidth / 2 - 20;
	constexpr int kLetterPosY = Game::kScreenHeight / 2 + 50;
}

SceneTitle::SceneTitle() : 
	m_nowSelect(0),
	m_selectInterval(0),
	m_selectPosY()
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::init()
{
	m_nowSelect = 0;
	m_selectInterval = kSelectInterval;
	m_selectPosY = kLetterPosY;
}


SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	
	//ゲームスタートを選択中の場合
	if (m_nowSelect == 0)
	{
		//■の位置をゲームスタートの横に表示
		m_selectPosY = kLetterPosY;
	}
	//ゲーム終了を選択中の場合
	else
	{
		//■の位置をゲーム終了の横に表示
		m_selectPosY = kLetterPosY + 50;
	}

	//インターバル処理
	m_selectInterval--;
	if (m_selectInterval < 0) m_selectInterval = 0;

	if (m_selectInterval <= 0)
	{
		//下キーが入力された場合
		if (padState & PAD_INPUT_DOWN)
		{
			//選択状態を1つ下げる
			m_nowSelect = (m_nowSelect + 1) % kMenuNum;

			//インターバルを初期化
			m_selectInterval = kSelectInterval;
		}
		//上キーが入力された場合
		if (padState & PAD_INPUT_UP)
		{
			//選択状態を1上げる
			m_nowSelect = (m_nowSelect + (kMenuNum - 1)) % kMenuNum;

			//インターバルを初期化
			m_selectInterval = kSelectInterval;
		}
		if (padState & PAD_INPUT_1)
		{
			switch (m_nowSelect)
			{
			case 0: //ゲームスタートを選択中の場合

				//セレクト画面に移動
				return (new SceneSelect);
				break;
			case 1: //ゲーム終了を選択中の場合

				//ゲーム終了
				DxLib_End();
				break;
			}

			//インターバルを初期化
			m_selectInterval = kSelectInterval;
		}
	}
	return this;
}

void SceneTitle::draw()
{
	DrawString(kLetterPosX, kLetterPosY, "START",GetColor(255, 255, 255));
	DrawString(kLetterPosX, kLetterPosY + 50, "EXIT", GetColor(255, 255, 255));
	DrawString(kLetterPosX - 50, m_selectPosY, "■", GetColor(255, 255, 255));
}
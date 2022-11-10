#include "SceneSelect.h"
#include "DxLib.h"
#include "game.h"
#include "SceneTitle.h"
#include "EasyQuiz1.h"

namespace
{
	//メニューの数
	constexpr int kMenuNum = 4;
	//コントローラーの操作のインターバル
	constexpr int kSelectInterval = 10;
	//EASYの表示位置
	constexpr int kLetterPosX = Game::kScreenWidth / 2 - 20;
	constexpr int kLetterPosY = Game::kScreenHeight / 2 - 100;
}


SceneSelect::SceneSelect() :
	m_selectInterval(0),
	m_nowSelect(0),
	m_selectPosY(),
	m_waitFrame(0),
	m_bugPreven(false)
{
}

SceneSelect::~SceneSelect()
{
}

void SceneSelect::init()
{
	m_selectInterval = 0;
	m_nowSelect = 0;
	m_waitFrame = 30;
	m_selectPosY = kLetterPosY;
}

SceneBase* SceneSelect::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//すぐにシーンが切り替わるのを防ぐ処理
	if (!m_bugPreven)
	{
		m_waitFrame--;
		if (m_waitFrame <= 0)
		{
			m_bugPreven = true;
		}
	}

	//EASYを選択中の場合
	if (m_nowSelect == 0)
	{
		//■の位置をEASYの横に表示
		m_selectPosY = kLetterPosY;
	}
	//NORMALを選択中の場合
	else if (m_nowSelect == 1)
	{
		//■の位置をNORMALの横に表示
		m_selectPosY = kLetterPosY + 50;
	}
	//HARDを選択中の場合
	else if (m_nowSelect == 2)
	{
		//■の位置をHAEDの横に表示
		m_selectPosY = kLetterPosY + 100;
	}
	//タイトルの戻るを選択中の場合
	else
	{
		//■の位置をゲーム終了の横に表示
		m_selectPosY = kLetterPosY + 150;
	}

	//インターバル処理
	m_selectInterval--;
	if (m_selectInterval < 0) m_selectInterval = 0;

	if (m_selectInterval <= 0 && m_bugPreven)
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
			case 0: //EASYを選択中の場合

				//EASYに移動(どの問題に飛ぶかはランダム)
				return (new EasyQuiz1);
				break;
			case 1: //NORMALを選択中の場合

				//NORMALに移動
				break;
			case 2:	//HARDを選択中の場合

				//HARDに移動
				break;
			case 3: //BACKを選択中の場合

				//タイトルに戻る
				return (new SceneTitle);
				break;
			}

			//インターバルを初期化
			m_selectInterval = kSelectInterval;
		}
	}
	return this;
}

void SceneSelect::draw()
{
	DrawString(kLetterPosX, kLetterPosY, "EASY", GetColor(255, 255, 255));
	DrawString(kLetterPosX, kLetterPosY + 50, "NORMAL", GetColor(255, 255, 255));
	DrawString(kLetterPosX, kLetterPosY + 100, "HARD", GetColor(255, 255, 255));
	DrawString(kLetterPosX, kLetterPosY + 150, "BACK", GetColor(255, 255, 255));
	DrawString(kLetterPosX - 50, m_selectPosY, "■", GetColor(255, 255, 255));
}
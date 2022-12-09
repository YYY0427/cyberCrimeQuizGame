#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneManager.h"
#include "game.h"
#include "EasyQuiz1.h"
#include "EasyQuiz2.h"
#include "EasyQuiz3.h"

namespace
{
	//メニューの数
	constexpr int kMenuNum = 4;
	//コントローラーの操作のインターバル
	constexpr int kSelectInterval = 10;
	//STARTの表示位置
	constexpr int kLetterPosX = Game::kScreenWidth / 2 - 40;
	constexpr int kLetterPosY = Game::kScreenHeight / 2 + 20;
}

SceneTitle::SceneTitle() : 
	m_nowSelect(0),
	m_selectInterval(0),
	m_selectPosY(),
	m_explanLetterHandle(-1),
	m_titleLetterHandle(-1)
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
	/*m_randNum = GetRand(kMenuNum - 2);*/
	m_titleLetterHandle = CreateFontToHandle(NULL, 35, 5);
	m_explanLetterHandle = CreateFontToHandle(NULL, 20, 5);
}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	
	//かんたんを選択中の場合
	if (m_nowSelect == 0)
	{
		//■の位置をかんたんの横に表示
		m_selectPosY = kLetterPosY;
	}
	//ふつうを選択中の場合
	else if (m_nowSelect == 1)
	{
		//■の位置をふつうの横に表示
		m_selectPosY = kLetterPosY + 50;
	}
	//むずかしいを選択中の場合
	else if (m_nowSelect == 2)
	{
		//■の位置をむずかしいの横に表示
		m_selectPosY = kLetterPosY + 100;
	}
	//ゲーム終了を選択中の場合
	else
	{
		//■の位置をゲーム終了の横に表示
		m_selectPosY = kLetterPosY + 150;
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
		if (padState & PAD_INPUT_1 || CheckHitKey(KEY_INPUT_SPACE))
		{
			switch (m_nowSelect)
			{
			case 0: //かんたんを選択中の場合

				//かんたんに移動
				return (new EasyQuiz1);
				break;
			case 1: //ふつうを選択中の場合

				break;
			case 2:	//むずかしいを選択中の場合

				break;
			case 3:	//ゲーム終了を選択中の場合

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
	DrawStringToHandle(Game::kScreenWidth / 2 - 227, 70, "サイバーセキュリティクイズ", GetColor(255, 255, 255), m_titleLetterHandle);
	DrawStringToHandle(Game::kScreenWidth / 2 - 190, 170, "レベルを選んでゲームをスタートしよう！", GetColor(255, 255, 255), m_explanLetterHandle);
	DrawString(kLetterPosX, kLetterPosY, "かんたん", GetColor(255, 255, 255));
	DrawString(kLetterPosX + 5, kLetterPosY + 50, "ふつう", GetColor(255, 255, 255));
	DrawString(kLetterPosX - 10, kLetterPosY + 100, "むずかしい", GetColor(255, 255, 255));
	DrawString(kLetterPosX - 20, kLetterPosY + 150, "ゲームをやめる", GetColor(255, 255, 255));
	DrawString(kLetterPosX - 50, m_selectPosY, "■", GetColor(255, 255, 255));
}
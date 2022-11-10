#include "EasyQuiz1.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//選択肢の数
	constexpr int kMenuNum = 4;
	//コントローラーの操作のインターバル
	constexpr int kSelectInterval = 10;
	//選択肢1の表示位置
	constexpr int kLetterPosX = Game::kScreenWidth / 2 - 200;
	constexpr int kLetterPosY = Game::kScreenHeight / 2 + 50;
}

EasyQuiz1::EasyQuiz1() :
	m_problemNumHandle(-1),
	m_problemStatemenHandle(-1),
	m_selectInterval(0),
	m_nowSelect(0),
	m_selectPosY(),
	m_waitFrame(0),
	m_bugPreven(false)
{
}

EasyQuiz1::~EasyQuiz1()
{

}

void EasyQuiz1::init()
{
	m_problemNumHandle		= CreateFontToHandle(NULL, 30, 5);
	m_problemStatemenHandle = CreateFontToHandle(NULL, 20, 5);

	m_selectInterval = 0;
	m_nowSelect = 0;
	m_waitFrame = 30;
	m_selectPosY = kLetterPosY;
}

SceneBase* EasyQuiz1::update()
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

	//選択肢0を選択中の場合
	if (m_nowSelect == 0)
	{
		//■の位置を選択肢0の横に表示
		m_selectPosY = kLetterPosY;
	}
	//選択肢1を選択中の場合
	else if (m_nowSelect == 1)
	{
		//■の位置を選択肢1の横に表示
		m_selectPosY = kLetterPosY + 50;
	}
	//選択肢2を選択中の場合
	else if (m_nowSelect == 2)
	{
		//■の位置を選択肢2の横に表示
		m_selectPosY = kLetterPosY + 100;
	}
	//選択肢3を選択中の場合
	else
	{
		//■の位置を選択肢3の横に表示
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
			case 0: //選択肢0を選択した場合

				break;
			case 1: //選択肢1を選択した場合

				break;
			case 2:	//選択肢2を選択した場合

				break;
			case 3: //選択肢3を選択した場合

				break;
			}

			//インターバルを初期化
			m_selectInterval = kSelectInterval;
		}
	}

	return this;
}

void EasyQuiz1::draw()
{
	DrawStringToHandle(Game::kScreenWidth / 2 - 55, 10, "第 1 問", GetColor(255, 255, 255), m_problemNumHandle);
	DrawStringToHandle(Game::kScreenWidth / 2 - 145, 100, "次の文を完成させてください。", GetColor(255, 255, 255), m_problemStatemenHandle);
	DrawStringToHandle(Game::kScreenWidth / 2 - 185, 140, "「通常、私用のデバイスを持ち歩くと...」", GetColor(255, 255, 255), m_problemStatemenHandle);

	//選択肢の表示
	DrawString(kLetterPosX, kLetterPosY, "仕事用のデバイスを使用するよりもリスクが高くなる", GetColor(255, 255, 255));
	DrawString(kLetterPosX, kLetterPosY + 50, "仕事用のデバイスを使用するのと同じくらいリスクがある", GetColor(255, 255, 255));
	DrawString(kLetterPosX, kLetterPosY + 100, "仕事用のデバイスを使用するよりもリスクが低くなる", GetColor(255, 255, 255));
	DrawString(kLetterPosX, kLetterPosY + 150, "西村", GetColor(255, 255, 255));

	DrawString(kLetterPosX - 50, m_selectPosY, "■", GetColor(255, 255, 255));
}

void EasyQuiz1::end()
{

}
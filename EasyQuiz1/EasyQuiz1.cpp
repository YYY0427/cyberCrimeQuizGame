#include "EasyQuiz1.h"
#include "DxLib.h"
#include "game.h"
#include "EasyQuiz1CorrectAnswer.h"
#include "EasyQuiz1IncorrectAnswer.h"

namespace
{
	//選択肢の数
	constexpr int kMenuNum = 4;

	//コントローラーの操作のインターバル
	constexpr int kSelectInterval = 10;

	//制限時間
	constexpr int kTimeLimit = 10000;

	//問題文
	const char* const kProblemStatemen = "Q　次のうち、最も安全なパスワードは？";

	//選択肢
	const char* const kProblemChoice0 = "uMebosh!58";
	const char* const kProblemChoice1 = "123456";
	const char* const kProblemChoice2 = "Maho010200";
	const char* const kProblemChoice3 = "1qaz2wsx";

	//選択肢0の表示位置
	constexpr int kLetterPosX = Game::kScreenWidth / 2 - 200;
	constexpr int kLetterPosY = Game::kScreenHeight / 2;
	//選択肢1の表示位置
	constexpr int kLetterPosX1 = Game::kScreenWidth / 2 + 90;
	constexpr int kLetterPosY1 = Game::kScreenHeight / 2;
}

EasyQuiz1::EasyQuiz1() :
	m_problemNumHandle(-1),
	m_problemStatemenHandle(-1),
	m_choiceHandle(-1),
	m_selectInterval(0),
	m_nowSelect(0),
	m_selectPosY(),
	m_selectPosX(),
	m_waitFrame(0),
	m_startTime(0),
	m_nowTime(0),
	m_timeBoxPosX(0),
	m_timeBoxPosX2(0),
	m_bugPreven(false)
{
}

EasyQuiz1::~EasyQuiz1()
{
}

void EasyQuiz1::init()
{
	m_problemNumHandle		= CreateFontToHandle(NULL, 30, 5);
	m_problemStatemenHandle = CreateFontToHandle(NULL, 25, 5);
	m_choiceHandle			= CreateFontToHandle(NULL, 25, 5);

	m_timeBoxPosX		   = Game::kScreenWidth / 2 - 230;
	m_timeBoxPosX2		   = Game::kScreenWidth - 100;
	m_selectInterval	   = 0;
	m_nowSelect			   = 0;
	m_waitFrame			   = 30;
	m_selectPosY		   = kLetterPosY;
	m_selectPosX		   = kLetterPosX;
	m_bugPreven			   = false;
	m_startTime			   = GetNowCount();
	m_nowTime			   = 0;
}

void EasyQuiz1::end()
{

}

SceneBase* EasyQuiz1::update()
{
	//ゲームのスタート時間を取得
	m_nowTime = GetNowCount();

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
		m_selectPosX = kLetterPosX;
	}
	//選択肢1を選択中の場合
	else if (m_nowSelect == 1)
	{
		//■の位置を選択肢1の横に表示
		m_selectPosY = kLetterPosY1;
		m_selectPosX = kLetterPosX1;
	}
	//選択肢2を選択中の場合
	else if (m_nowSelect == 2)
	{
		//■の位置を選択肢2の横に表示
		m_selectPosY = kLetterPosY + 100;
		m_selectPosX = kLetterPosX;
	}
	//選択肢3を選択中の場合
	else 
	{
		//■の位置を選択肢3の横に表示
		m_selectPosY = kLetterPosY1 + 100;
		m_selectPosX = kLetterPosX1;
	}

	//インターバル処理
	m_selectInterval--;
	if (m_selectInterval < 0) m_selectInterval = 0;

	if (m_selectInterval <= 0 && m_bugPreven)
	{
		//下キーか上キーが入力された場合
		if (padState & PAD_INPUT_DOWN)
		{
			if (m_nowSelect == 0)
			{
				m_nowSelect = 2;
			}
			else if(m_nowSelect == 1)
			{
				m_nowSelect = 3;
			}
			else if (m_nowSelect == 2)
			{
				m_nowSelect = 0;
			}
			else
			{
				m_nowSelect = 1;
			}

			//インターバルを初期化
			m_selectInterval = kSelectInterval;
		}
		//上キーが入力された場合
		if (padState & PAD_INPUT_UP)
		{
			if (m_nowSelect == 0)
			{
				m_nowSelect = 2;
			}
			else if (m_nowSelect == 1)
			{
				m_nowSelect = 3;
			}
			else if (m_nowSelect == 2)
			{
				m_nowSelect = 0;
			}
			else
			{
				m_nowSelect = 1;
			}

			//インターバルを初期化
			m_selectInterval = kSelectInterval;
		}
		//左キーが入力された場合
		if (padState & PAD_INPUT_LEFT)
		{
			if (m_nowSelect == 0)
			{
				m_nowSelect = 1;
			}
			else if (m_nowSelect == 1)
			{
				m_nowSelect = 0;
			}
			else if (m_nowSelect == 2)
			{
				m_nowSelect = 3;
			}
			else
			{
				m_nowSelect = 2;
			}

			//インターバルを初期化
			m_selectInterval = kSelectInterval;
		}
		//右キーが入力された場合
		if (padState & PAD_INPUT_RIGHT)
		{
			if (m_nowSelect == 0)
			{
				m_nowSelect = 1;
			}
			else if (m_nowSelect == 1)
			{
				m_nowSelect = 0;
			}
			else if (m_nowSelect == 2)
			{
				m_nowSelect = 3;
			}
			else
			{
				m_nowSelect = 2;
			}

			//インターバルを初期化
			m_selectInterval = kSelectInterval;
		}
		if (padState & PAD_INPUT_1)
		{
			switch (m_nowSelect)
			{
			case 0: //選択肢0を選択した場合(正解)

				//〇を表示
				return (new EasyQuiz1CorrectAnswer);
				break;
			case 1: //選択肢1を選択した場合(不正解)

				//×を表示
				return (new EasyQuiz1IncorrectAnswer);
				break;
			case 2:	//選択肢2を選択した場合(不正解)

				//×を表示
				return (new EasyQuiz1IncorrectAnswer);
				break;
			case 3:	//選択肢3を選択した場合(不正解)

				//×を表示
				return (new EasyQuiz1IncorrectAnswer);
				break;
			}

			//インターバルを初期化
			m_selectInterval = kSelectInterval;
		}

		//指定した時間以上経った場合
		if ((m_nowTime - m_startTime) > kTimeLimit)
		{
			return (new EasyQuiz1IncorrectAnswer);
		}
	}

	//箱の右頂点が左頂点より大きい場合
	if (m_timeBoxPosX < m_timeBoxPosX2)
	{
		//時間制限を表す箱の表示の減少
		m_timeBoxPosX2 -= 0.75;
	}
	
	return this;
}

void EasyQuiz1::draw()
{
	//制限時間の表示
//	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d秒", (kTimeLimit - (m_nowTime - m_startTime)) / 1000);
	DrawBox(m_timeBoxPosX, Game::kScreenHeight / 2 - 70, m_timeBoxPosX2, Game::kScreenHeight / 2 - 60,
		GetColor(255, 255, 255), true);

	//第何問目かの表示
	DrawStringToHandle(Game::kScreenWidth / 2 - 75, 20, "第　1　問", GetColor(255, 255, 255), m_problemNumHandle);

	//問題文の表示
	DrawStringToHandle(Game::kScreenWidth / 2 - 237, Game::kScreenHeight / 2 - 130, kProblemStatemen, GetColor(255, 255, 255), m_problemStatemenHandle);

	//選択肢0の表示
	DrawStringToHandle(kLetterPosX, kLetterPosY, kProblemChoice0, GetColor(255, 255, 255), m_choiceHandle);
	//選択肢1の表示
	DrawStringToHandle(kLetterPosX1, kLetterPosY1, kProblemChoice1, GetColor(255, 255, 255), m_choiceHandle);
	//選択肢2の表示
	DrawStringToHandle(kLetterPosX, kLetterPosY + 100, kProblemChoice2, GetColor(255, 255, 255), m_choiceHandle);
	//選択肢3の表示
	DrawStringToHandle(kLetterPosX1, kLetterPosY1 + 100, kProblemChoice3, GetColor(255, 255, 255), m_choiceHandle);

	DrawString(m_selectPosX - 30, m_selectPosY, "■", GetColor(255, 255, 255));
}
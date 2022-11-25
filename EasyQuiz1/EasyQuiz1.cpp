#include "EasyQuiz1.h"
#include "DxLib.h"
#include "game.h"
#include "EasyQuiz1CorrectAnswer.h"
#include "EasyQuiz1IncorrectAnswer.h"

namespace
{
	//�I�����̐�
	constexpr int kMenuNum = 4;

	//�R���g���[���[�̑���̃C���^�[�o��
	constexpr int kSelectInterval = 10;

	//��������
	constexpr int kTimeLimit = 10000;

	//��蕶
	const char* const kProblemStatemen = "Q�@���̂����A�ł����S�ȃp�X���[�h�́H";

	//�I����
	const char* const kProblemChoice0 = "uMebosh!58";
	const char* const kProblemChoice1 = "123456";
	const char* const kProblemChoice2 = "Maho010200";
	const char* const kProblemChoice3 = "1qaz2wsx";

	//�I����0�̕\���ʒu
	constexpr int kLetterPosX = Game::kScreenWidth / 2 - 200;
	constexpr int kLetterPosY = Game::kScreenHeight / 2;
	//�I����1�̕\���ʒu
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
	//�Q�[���̃X�^�[�g���Ԃ��擾
	m_nowTime = GetNowCount();

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//�����ɃV�[�����؂�ւ��̂�h������
	if (!m_bugPreven)
	{
		m_waitFrame--;
		if (m_waitFrame <= 0)
		{
			m_bugPreven = true;
		}
	}

	//�I����0��I�𒆂̏ꍇ
	if (m_nowSelect == 0)
	{
		//���̈ʒu��I����0�̉��ɕ\��
		m_selectPosY = kLetterPosY;
		m_selectPosX = kLetterPosX;
	}
	//�I����1��I�𒆂̏ꍇ
	else if (m_nowSelect == 1)
	{
		//���̈ʒu��I����1�̉��ɕ\��
		m_selectPosY = kLetterPosY1;
		m_selectPosX = kLetterPosX1;
	}
	//�I����2��I�𒆂̏ꍇ
	else if (m_nowSelect == 2)
	{
		//���̈ʒu��I����2�̉��ɕ\��
		m_selectPosY = kLetterPosY + 100;
		m_selectPosX = kLetterPosX;
	}
	//�I����3��I�𒆂̏ꍇ
	else 
	{
		//���̈ʒu��I����3�̉��ɕ\��
		m_selectPosY = kLetterPosY1 + 100;
		m_selectPosX = kLetterPosX1;
	}

	//�C���^�[�o������
	m_selectInterval--;
	if (m_selectInterval < 0) m_selectInterval = 0;

	if (m_selectInterval <= 0 && m_bugPreven)
	{
		//���L�[����L�[�����͂��ꂽ�ꍇ
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

			//�C���^�[�o����������
			m_selectInterval = kSelectInterval;
		}
		//��L�[�����͂��ꂽ�ꍇ
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

			//�C���^�[�o����������
			m_selectInterval = kSelectInterval;
		}
		//���L�[�����͂��ꂽ�ꍇ
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

			//�C���^�[�o����������
			m_selectInterval = kSelectInterval;
		}
		//�E�L�[�����͂��ꂽ�ꍇ
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

			//�C���^�[�o����������
			m_selectInterval = kSelectInterval;
		}
		if (padState & PAD_INPUT_1)
		{
			switch (m_nowSelect)
			{
			case 0: //�I����0��I�������ꍇ(����)

				//�Z��\��
				return (new EasyQuiz1CorrectAnswer);
				break;
			case 1: //�I����1��I�������ꍇ(�s����)

				//�~��\��
				return (new EasyQuiz1IncorrectAnswer);
				break;
			case 2:	//�I����2��I�������ꍇ(�s����)

				//�~��\��
				return (new EasyQuiz1IncorrectAnswer);
				break;
			case 3:	//�I����3��I�������ꍇ(�s����)

				//�~��\��
				return (new EasyQuiz1IncorrectAnswer);
				break;
			}

			//�C���^�[�o����������
			m_selectInterval = kSelectInterval;
		}

		//�w�肵�����Ԉȏ�o�����ꍇ
		if ((m_nowTime - m_startTime) > kTimeLimit)
		{
			return (new EasyQuiz1IncorrectAnswer);
		}
	}

	//���̉E���_�������_���傫���ꍇ
	if (m_timeBoxPosX < m_timeBoxPosX2)
	{
		//���Ԑ�����\�����̕\���̌���
		m_timeBoxPosX2 -= 0.75;
	}
	
	return this;
}

void EasyQuiz1::draw()
{
	//�������Ԃ̕\��
//	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d�b", (kTimeLimit - (m_nowTime - m_startTime)) / 1000);
	DrawBox(m_timeBoxPosX, Game::kScreenHeight / 2 - 70, m_timeBoxPosX2, Game::kScreenHeight / 2 - 60,
		GetColor(255, 255, 255), true);

	//�扽��ڂ��̕\��
	DrawStringToHandle(Game::kScreenWidth / 2 - 75, 20, "��@1�@��", GetColor(255, 255, 255), m_problemNumHandle);

	//��蕶�̕\��
	DrawStringToHandle(Game::kScreenWidth / 2 - 237, Game::kScreenHeight / 2 - 130, kProblemStatemen, GetColor(255, 255, 255), m_problemStatemenHandle);

	//�I����0�̕\��
	DrawStringToHandle(kLetterPosX, kLetterPosY, kProblemChoice0, GetColor(255, 255, 255), m_choiceHandle);
	//�I����1�̕\��
	DrawStringToHandle(kLetterPosX1, kLetterPosY1, kProblemChoice1, GetColor(255, 255, 255), m_choiceHandle);
	//�I����2�̕\��
	DrawStringToHandle(kLetterPosX, kLetterPosY + 100, kProblemChoice2, GetColor(255, 255, 255), m_choiceHandle);
	//�I����3�̕\��
	DrawStringToHandle(kLetterPosX1, kLetterPosY1 + 100, kProblemChoice3, GetColor(255, 255, 255), m_choiceHandle);

	DrawString(m_selectPosX - 30, m_selectPosY, "��", GetColor(255, 255, 255));
}
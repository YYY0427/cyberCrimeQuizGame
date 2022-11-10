#include "EasyQuiz1.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	//�I�����̐�
	constexpr int kMenuNum = 4;
	//�R���g���[���[�̑���̃C���^�[�o��
	constexpr int kSelectInterval = 10;
	//�I����1�̕\���ʒu
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
	}
	//�I����1��I�𒆂̏ꍇ
	else if (m_nowSelect == 1)
	{
		//���̈ʒu��I����1�̉��ɕ\��
		m_selectPosY = kLetterPosY + 50;
	}
	//�I����2��I�𒆂̏ꍇ
	else if (m_nowSelect == 2)
	{
		//���̈ʒu��I����2�̉��ɕ\��
		m_selectPosY = kLetterPosY + 100;
	}
	//�I����3��I�𒆂̏ꍇ
	else
	{
		//���̈ʒu��I����3�̉��ɕ\��
		m_selectPosY = kLetterPosY + 150;
	}

	//�C���^�[�o������
	m_selectInterval--;
	if (m_selectInterval < 0) m_selectInterval = 0;

	if (m_selectInterval <= 0 && m_bugPreven)
	{
		//���L�[�����͂��ꂽ�ꍇ
		if (padState & PAD_INPUT_DOWN)
		{
			//�I����Ԃ�1������
			m_nowSelect = (m_nowSelect + 1) % kMenuNum;

			//�C���^�[�o����������
			m_selectInterval = kSelectInterval;
		}
		//��L�[�����͂��ꂽ�ꍇ
		if (padState & PAD_INPUT_UP)
		{
			//�I����Ԃ�1�グ��
			m_nowSelect = (m_nowSelect + (kMenuNum - 1)) % kMenuNum;

			//�C���^�[�o����������
			m_selectInterval = kSelectInterval;
		}
		if (padState & PAD_INPUT_1)
		{
			switch (m_nowSelect)
			{
			case 0: //�I����0��I�������ꍇ

				break;
			case 1: //�I����1��I�������ꍇ

				break;
			case 2:	//�I����2��I�������ꍇ

				break;
			case 3: //�I����3��I�������ꍇ

				break;
			}

			//�C���^�[�o����������
			m_selectInterval = kSelectInterval;
		}
	}

	return this;
}

void EasyQuiz1::draw()
{
	DrawStringToHandle(Game::kScreenWidth / 2 - 55, 10, "�� 1 ��", GetColor(255, 255, 255), m_problemNumHandle);
	DrawStringToHandle(Game::kScreenWidth / 2 - 145, 100, "���̕������������Ă��������B", GetColor(255, 255, 255), m_problemStatemenHandle);
	DrawStringToHandle(Game::kScreenWidth / 2 - 185, 140, "�u�ʏ�A���p�̃f�o�C�X������������...�v", GetColor(255, 255, 255), m_problemStatemenHandle);

	//�I�����̕\��
	DrawString(kLetterPosX, kLetterPosY, "�d���p�̃f�o�C�X���g�p����������X�N�������Ȃ�", GetColor(255, 255, 255));
	DrawString(kLetterPosX, kLetterPosY + 50, "�d���p�̃f�o�C�X���g�p����̂Ɠ������炢���X�N������", GetColor(255, 255, 255));
	DrawString(kLetterPosX, kLetterPosY + 100, "�d���p�̃f�o�C�X���g�p����������X�N���Ⴍ�Ȃ�", GetColor(255, 255, 255));
	DrawString(kLetterPosX, kLetterPosY + 150, "����", GetColor(255, 255, 255));

	DrawString(kLetterPosX - 50, m_selectPosY, "��", GetColor(255, 255, 255));
}

void EasyQuiz1::end()
{

}
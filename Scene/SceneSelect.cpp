#include "SceneSelect.h"
#include "DxLib.h"
#include "game.h"
#include "SceneTitle.h"
#include "EasyQuiz1.h"

namespace
{
	//���j���[�̐�
	constexpr int kMenuNum = 4;
	//�R���g���[���[�̑���̃C���^�[�o��
	constexpr int kSelectInterval = 10;
	//EASY�̕\���ʒu
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

	//�����ɃV�[�����؂�ւ��̂�h������
	if (!m_bugPreven)
	{
		m_waitFrame--;
		if (m_waitFrame <= 0)
		{
			m_bugPreven = true;
		}
	}

	//EASY��I�𒆂̏ꍇ
	if (m_nowSelect == 0)
	{
		//���̈ʒu��EASY�̉��ɕ\��
		m_selectPosY = kLetterPosY;
	}
	//NORMAL��I�𒆂̏ꍇ
	else if (m_nowSelect == 1)
	{
		//���̈ʒu��NORMAL�̉��ɕ\��
		m_selectPosY = kLetterPosY + 50;
	}
	//HARD��I�𒆂̏ꍇ
	else if (m_nowSelect == 2)
	{
		//���̈ʒu��HAED�̉��ɕ\��
		m_selectPosY = kLetterPosY + 100;
	}
	//�^�C�g���̖߂��I�𒆂̏ꍇ
	else
	{
		//���̈ʒu���Q�[���I���̉��ɕ\��
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
			case 0: //EASY��I�𒆂̏ꍇ

				//EASY�Ɉړ�(�ǂ̖��ɔ�Ԃ��̓����_��)
				return (new EasyQuiz1);
				break;
			case 1: //NORMAL��I�𒆂̏ꍇ

				//NORMAL�Ɉړ�
				break;
			case 2:	//HARD��I�𒆂̏ꍇ

				//HARD�Ɉړ�
				break;
			case 3: //BACK��I�𒆂̏ꍇ

				//�^�C�g���ɖ߂�
				return (new SceneTitle);
				break;
			}

			//�C���^�[�o����������
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
	DrawString(kLetterPosX - 50, m_selectPosY, "��", GetColor(255, 255, 255));
}
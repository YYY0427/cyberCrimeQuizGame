#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneManager.h"
#include "game.h"
#include "EasyQuiz1.h"
#include "EasyQuiz2.h"
#include "EasyQuiz3.h"

namespace
{
	//���j���[�̐�
	constexpr int kMenuNum = 4;
	//�R���g���[���[�̑���̃C���^�[�o��
	constexpr int kSelectInterval = 10;
	//START�̕\���ʒu
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
	
	//���񂽂��I�𒆂̏ꍇ
	if (m_nowSelect == 0)
	{
		//���̈ʒu�����񂽂�̉��ɕ\��
		m_selectPosY = kLetterPosY;
	}
	//�ӂ���I�𒆂̏ꍇ
	else if (m_nowSelect == 1)
	{
		//���̈ʒu���ӂ��̉��ɕ\��
		m_selectPosY = kLetterPosY + 50;
	}
	//�ނ���������I�𒆂̏ꍇ
	else if (m_nowSelect == 2)
	{
		//���̈ʒu���ނ��������̉��ɕ\��
		m_selectPosY = kLetterPosY + 100;
	}
	//�Q�[���I����I�𒆂̏ꍇ
	else
	{
		//���̈ʒu���Q�[���I���̉��ɕ\��
		m_selectPosY = kLetterPosY + 150;
	}

	//�C���^�[�o������
	m_selectInterval--;
	if (m_selectInterval < 0) m_selectInterval = 0;

	if (m_selectInterval <= 0)
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
		if (padState & PAD_INPUT_1 || CheckHitKey(KEY_INPUT_SPACE))
		{
			switch (m_nowSelect)
			{
			case 0: //���񂽂��I�𒆂̏ꍇ

				//���񂽂�Ɉړ�
				return (new EasyQuiz1);
				break;
			case 1: //�ӂ���I�𒆂̏ꍇ

				break;
			case 2:	//�ނ���������I�𒆂̏ꍇ

				break;
			case 3:	//�Q�[���I����I�𒆂̏ꍇ

				//�Q�[���I��
				DxLib_End();
				break;
			}

			//�C���^�[�o����������
			m_selectInterval = kSelectInterval;
		}
	}
	return this;
}

void SceneTitle::draw()
{
	DrawStringToHandle(Game::kScreenWidth / 2 - 227, 70, "�T�C�o�[�Z�L�����e�B�N�C�Y", GetColor(255, 255, 255), m_titleLetterHandle);
	DrawStringToHandle(Game::kScreenWidth / 2 - 190, 170, "���x����I��ŃQ�[�����X�^�[�g���悤�I", GetColor(255, 255, 255), m_explanLetterHandle);
	DrawString(kLetterPosX, kLetterPosY, "���񂽂�", GetColor(255, 255, 255));
	DrawString(kLetterPosX + 5, kLetterPosY + 50, "�ӂ�", GetColor(255, 255, 255));
	DrawString(kLetterPosX - 10, kLetterPosY + 100, "�ނ�������", GetColor(255, 255, 255));
	DrawString(kLetterPosX - 20, kLetterPosY + 150, "�Q�[������߂�", GetColor(255, 255, 255));
	DrawString(kLetterPosX - 50, m_selectPosY, "��", GetColor(255, 255, 255));
}
#include "DxLib.h"

#include "SceneTitle.h"
#include "SceneManager.h"
#include "SceneSelect.h"
#include "game.h"

namespace
{
	//���j���[�̐�
	constexpr int kMenuNum = 2;
	//�R���g���[���[�̑���̃C���^�[�o��
	constexpr int kSelectInterval = 10;
	//START�̕\���ʒu
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
	
	//�Q�[���X�^�[�g��I�𒆂̏ꍇ
	if (m_nowSelect == 0)
	{
		//���̈ʒu���Q�[���X�^�[�g�̉��ɕ\��
		m_selectPosY = kLetterPosY;
	}
	//�Q�[���I����I�𒆂̏ꍇ
	else
	{
		//���̈ʒu���Q�[���I���̉��ɕ\��
		m_selectPosY = kLetterPosY + 50;
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
		if (padState & PAD_INPUT_1)
		{
			switch (m_nowSelect)
			{
			case 0: //�Q�[���X�^�[�g��I�𒆂̏ꍇ

				//�Z���N�g��ʂɈړ�
				return (new SceneSelect);
				break;
			case 1: //�Q�[���I����I�𒆂̏ꍇ

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
	DrawString(kLetterPosX, kLetterPosY, "START",GetColor(255, 255, 255));
	DrawString(kLetterPosX, kLetterPosY + 50, "EXIT", GetColor(255, 255, 255));
	DrawString(kLetterPosX - 50, m_selectPosY, "��", GetColor(255, 255, 255));
}
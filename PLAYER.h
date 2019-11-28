#pragma once

#include "DxLib.h"
#include "Keyboard_Get.h"
#include "ENEMY.h"
#include "window_size.h"

#define GAME_PLAYER "�N���X�}�X�L�����`�b�v\\�e�X�g.jpg"
#define PLAYER_BUNKATU	12			//�v���C���[�摜�̑�������
#define PLAYER_BUNKATU_X 4//3		//�v���C���[�摜�̉�������
#define PLAYER_BUNKATU_Y 3//4		//�v���C���[�摜�̏c������
#define PLAYER_MIN_SOEJI 1			//�v���C���[�̍ŏ��̉摜
#define PLAYER_MAX_SOEJI 12			//�v���C���[�̍Ō�̉摜

int PLAYER_Size;					//�v���C���[�̉摜�T�C�Y��LoadDivGrahp�Ŏ擾���邽��
int PLAYER_Size_W, PLAYER_Size_H;	//�v���C���[�摜�̉��T�C�Y�A�c�T�C�Y���擾

class PLAYER{
private:
	
	
	int PLAYER_HP = 3;						//�v���C���[�̗̑�
	int PLAYER_Speed;					//�v���C���[�̃X�s�[�h

public:
	int PLAYER_X = 0;		//�v���C���[�̏���X�ʒu
	int PLAYER_Y = 0;		//�v���C���[�̏���Y�ʒu
	int PLAYER_soeji = 1;				//�v���C���[�̓Y�����Ɏg��
	int PLAYER_Handle[PLAYER_MAX_SOEJI];//�v���C���[�̃n���h��
	int Get_PLAYER_Speed();				//�v���C���[�̃X�s�[�h���֐��Ŏ擾
	int Get_PLAYER_X();					//�v���C���[��X�ʒu���֐��Ŏ擾
	int Get_PLAYER_Y();					//�v���C���[��Y�ʒu���֐��Ŏ擾
	void PLAYER_DRAW();					//�v���C���[��`�悷��֐�
	void PLAYER_RESET();
	int cnt = 0;
	void PLAYER_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y);		//�v���C���[�ƃG�l�~�[�̏Փ˔���

};

//�v���C���[�̃X�s�[�h���擾����֐�
int PLAYER::Get_PLAYER_Speed()
{
	//�v���C���[�̃X�s�[�h�ݒ�
	PLAYER_Speed = 10;
	return PLAYER_Speed;
}

//�v���C���[��X�ʒu���擾����֐�
int PLAYER::Get_PLAYER_X()
{
	//�v���C���[�𑀍삷��@���@���L�[���������ꍇ
	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1)
	{
		//window�̍��[�܂ňړ�����
		if (PLAYER_X >= GAME_MIN_WIDTH)
		{
			PLAYER_X -= Get_PLAYER_Speed();
		}
		/*if (fps->Wait)
		{
			PLAYER_soeji = fps->Wait % 2;
		}*/
	}
	//�v���C���[�𑀍삷��@�E�@���L�[���������ꍇ
	if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1)
	{
		//window�̉E�[�܂ňړ�����(�v���C���[�̉摜���T�C�Y���A�l�����炷)�@
		if (PLAYER_X <= GAME_WIDTH - PLAYER_Size_W / PLAYER_BUNKATU_X)
		{
			PLAYER_X += Get_PLAYER_Speed();
		}
	}
	return PLAYER_X;
}

//�v���C���[��Y�ʒu���擾����֐�
int PLAYER::Get_PLAYER_Y()
{
	//�v���C���[�𑀍삷��@��@���L�[���������ꍇ
	if (Keyboard_Get(KEY_INPUT_UP) >= 1)
	{
		//window�̏�[�܂ňړ�����
		if (PLAYER_Y >= GAME_MIN_HEIGHT)
		{
			PLAYER_Y -= Get_PLAYER_Speed();
		}
	}
	//�v���C���[�𑀍삷��@���@���L�[���������ꍇ
	if (Keyboard_Get(KEY_INPUT_DOWN) >= 1)
	{
		//window�̉��[�܂ňړ�����(�v���C���[�̉摜�c�T�C�Y���A�l�����炷)
		if (PLAYER_Y <= GAME_HEIGHT - PLAYER_Size_H / PLAYER_BUNKATU_Y)
		{
			PLAYER_Y += Get_PLAYER_Speed();
		}
	}
	return PLAYER_Y;
}

//�v���C���[��`�悷��֐�
void PLAYER::PLAYER_DRAW()
{
	DrawGraph(Get_PLAYER_X(), Get_PLAYER_Y(), PLAYER_Handle[PLAYER_soeji], TRUE);
}


void PLAYER::PLAYER_RESET()
{
	PLAYER_X = GAME_WIDTH / 2;
	PLAYER_Y = GAME_HEIGHT / 2;
	PLAYER_HP = 3;
}


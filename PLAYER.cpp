#include "DxLib.h"
#include "PLAYER.h"
#include "Keyboard_Get.h"
#include "WINDOW_SIZE.h"

int PLAYER_Size;					//�v���C���[�̉摜�T�C�Y��LoadDivGrahp�Ŏ擾���邽��
int PLAYER_Size_W, PLAYER_Size_H;	//�v���C���[�摜�̉��T�C�Y�A�c�T�C�Y���擾

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

//�v���C���[�������ʒu�ֈړ�
void PLAYER::PLAYER_RESET()
{
	PLAYER_X = GAME_WIDTH / PLAYER_X_HALF;
	PLAYER_Y = GAME_HEIGHT / PLAYER_Y_HALF;
}

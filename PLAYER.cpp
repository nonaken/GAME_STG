#include "DxLib.h"
#include "PLAYER.h"
#include "Keyboard_Get.h"
#include "WINDOW_SIZE.h"



#define PLAYER_DOWN_SOEJI 0			//�������̉摜
#define PLAYER_UP_SOEJI 9			//������̉摜
#define PLAYER_LEFT_SOEJI 3			//�������̉摜
#define PLAYER_RIGHT_SOEJI 6		//�E�����̉摜

#define PLAYER_ANIMATION_FRAME 5			//�A�j���[�V�����̕`���؂�ւ���t���[����
#define PLAYER_ANIMETION_PATTERN 3			//�A�j���[�V�����̎��

int PLAYER_Size;					//�v���C���[�̉摜�T�C�Y��LoadDivGrahp�Ŏ擾���邽��
int PLAYER_Size_W, PLAYER_Size_H;	//�v���C���[�摜�̉��T�C�Y�A�c�T�C�Y���擾

//�v���C���[�̃X�s�[�h���擾����֐�
int PLAYER::Get_PLAYER_Speed()
{
	//�v���C���[�̃X�s�[�h�ݒ�
	PLAYER_Speed = 5;
	return PLAYER_Speed;
}

//�v���C���[��X�ʒu���擾����֐�
int PLAYER::Get_PLAYER_X()
{

	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1 && Keyboard_Get(KEY_INPUT_UP) >= 1 ||
		Keyboard_Get(KEY_INPUT_LEFT) >= 1 && Keyboard_Get(KEY_INPUT_DOWN) >= 1 ||
		Keyboard_Get(KEY_INPUT_RIGHT) >= 1 && Keyboard_Get(KEY_INPUT_UP) >= 1 ||
		Keyboard_Get(KEY_INPUT_RIGHT) >= 1 && Keyboard_Get(KEY_INPUT_DOWN) >= 1 ||
		Keyboard_Get(KEY_INPUT_LEFT) >= 1 && Keyboard_Get(KEY_INPUT_RIGHT) >= 1 ||
		Keyboard_Get(KEY_INPUT_LEFT) == 0 && Keyboard_Get(KEY_INPUT_RIGHT) == 0
		&& Keyboard_Get(KEY_INPUT_UP) == 0 && Keyboard_Get(KEY_INPUT_DOWN) == 0)
	{
		PLAYER_MOVE_flag = false;
		PLAYER_soeji = PLAYER_UP_SOEJI;
	}


	//�v���C���[�𑀍삷��@���@���L�[���������ꍇ
	else if (Keyboard_Get(KEY_INPUT_LEFT) >= 1)
	{
		PLAYER_MOVE_flag = true;
		//window�̍��[�܂ňړ�����
		if (PLAYER_X >= GAME_MIN_WIDTH)
		{
			if (PLAYER_MOVE_flag == true)
			{
				PLAYER_X -= Get_PLAYER_Speed();

				//�A�j���[�V�����p�J�E���g
				PLAYER_COUNT++;

				//���Ɉړ�����A�j���[�V����
				PLAYER_soeji = PLAYER_LEFT_SOEJI + (PLAYER_COUNT / PLAYER_ANIMATION_FRAME) % PLAYER_ANIMETION_PATTERN;
			}
		}
		/*if (fps->Wait)
		{
			PLAYER_soeji = fps->Wait % 2;
		}*/
	}
	//�v���C���[�𑀍삷��@�E�@���L�[���������ꍇ
	else if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1)
	{
		PLAYER_MOVE_flag = true;
		//window�̉E�[�܂ňړ�����(�v���C���[�̉摜���T�C�Y���A�l�����炷)�@
		if (PLAYER_X <= GAME_WIDTH - PLAYER_Size_W / PLAYER_BUNKATU_X)
		{
			if (PLAYER_MOVE_flag == true)
			{
				PLAYER_X += Get_PLAYER_Speed();

				//�A�j���[�V�����p�J�E���g
				PLAYER_COUNT++;

				//�E�Ɉړ�����A�j���[�V����
				PLAYER_soeji = PLAYER_RIGHT_SOEJI + (PLAYER_COUNT / PLAYER_ANIMATION_FRAME) % PLAYER_ANIMETION_PATTERN;
			}
		}
	}

	//�v���C���[�𑀍삷��@�E�@���L�[���������ꍇ
	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1 && Keyboard_Get(KEY_INPUT_RIGHT) >= 1)
	{
		PLAYER_soeji = PLAYER_UP_SOEJI;
	}

	return PLAYER_X;
}

//�v���C���[��Y�ʒu���擾����֐�
int PLAYER::Get_PLAYER_Y()
{

	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1 && Keyboard_Get(KEY_INPUT_UP) >= 1 ||
		Keyboard_Get(KEY_INPUT_LEFT) >= 1 && Keyboard_Get(KEY_INPUT_DOWN) >= 1 ||
		Keyboard_Get(KEY_INPUT_RIGHT) >= 1 && Keyboard_Get(KEY_INPUT_UP) >= 1 ||
		Keyboard_Get(KEY_INPUT_RIGHT) >= 1 && Keyboard_Get(KEY_INPUT_DOWN) >= 1 ||
		Keyboard_Get(KEY_INPUT_UP) >= 1 && Keyboard_Get(KEY_INPUT_DOWN) >= 1)
	{
		PLAYER_MOVE_flag = false;
	}
	//�v���C���[�𑀍삷��@��@���L�[���������ꍇ
	else if (Keyboard_Get(KEY_INPUT_UP) >= 1)
	{
		PLAYER_MOVE_flag = true;
		//window�̏�[�܂ňړ�����
		if (PLAYER_Y >= GAME_MIN_HEIGHT)
		{
			if (PLAYER_MOVE_flag == true)
			{
				PLAYER_Y -= Get_PLAYER_Speed();

				//�A�j���[�V�����p�J�E���g
				PLAYER_COUNT++;

				//��Ɉړ�����A�j���[�V����
				PLAYER_soeji = PLAYER_UP_SOEJI + (PLAYER_COUNT / PLAYER_ANIMATION_FRAME) % PLAYER_ANIMETION_PATTERN;
			}
		}
	}
	//�v���C���[�𑀍삷��@���@���L�[���������ꍇ
	else if (Keyboard_Get(KEY_INPUT_DOWN) >= 1)
	{
		PLAYER_MOVE_flag = true;
		//window�̉��[�܂ňړ�����(�v���C���[�̉摜�c�T�C�Y���A�l�����炷)
		if (PLAYER_Y <= GAME_HEIGHT - PLAYER_Size_H / PLAYER_BUNKATU_Y)
		{
			if (PLAYER_MOVE_flag == true)
			{
				PLAYER_Y += Get_PLAYER_Speed();

				//�A�j���[�V�����p�J�E���g
				PLAYER_COUNT++;

				//���Ɉړ�����A�j���[�V����
				PLAYER_soeji = PLAYER_DOWN_SOEJI + (PLAYER_COUNT / PLAYER_ANIMATION_FRAME) % PLAYER_ANIMETION_PATTERN;
			}
		}
	}
	return PLAYER_Y;
}

//�v���C���[��HP��`�悷��֐�
void PLAYER::PLAYER_HP_DRAW()
{
	DrawFormatStringToHandle(0, 0, GetColor(255, 0, 0), FontHandle_PLAYER_HP,"PLAYER�F%d", PLAYER_HP);	//�v���C���[�̗̑͂�`�悷��
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

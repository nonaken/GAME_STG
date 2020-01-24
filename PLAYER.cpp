#include "DxLib.h"
#include "PLAYER.h"
#include "Keyboard_Get.h"
#include "WINDOW_SIZE.h"

int PLAYER_Size;					//�v���C���[�̉摜�T�C�Y��LoadDivGrahp�Ŏ擾���邽��
int PLAYER_Size_W, PLAYER_Size_H;	//�v���C���[�摜�̉��T�C�Y�A�c�T�C�Y���擾

#define PLAYER_DOWN_SOEJI 0			//�������̉摜
#define PLAYER_UP_SOEJI 9			//������̉摜
#define PLAYER_LEFT_SOEJI 3			//�������̉摜
#define PLAYER_RIGHT_SOEJI 6		//�E�����̉摜

#define ANIMATION_FRAME 5			//�A�j���[�V�����̕`���؂�ւ���t���[����
#define ANIMETION_PATTERN 3			//�A�j���[�V�����̎��

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
	//�v���C���[�𑀍삷��@���@���L�[���������ꍇ
	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1)
	{
		//window�̍��[�܂ňړ�����
		if (PLAYER_X >= GAME_MIN_WIDTH)
		{
			PLAYER_X -= Get_PLAYER_Speed();

			//�A�j���[�V�����p�J�E���g
			PLAYER_COUNT++;
			
			//���Ɉړ�����A�j���[�V����
			PLAYER_soeji = PLAYER_LEFT_SOEJI + (PLAYER_COUNT / ANIMATION_FRAME) % ANIMETION_PATTERN;
			
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
			
			//�A�j���[�V�����p�J�E���g
			PLAYER_COUNT++;
			
			//�E�Ɉړ�����A�j���[�V����
			PLAYER_soeji = PLAYER_RIGHT_SOEJI + (PLAYER_COUNT / ANIMATION_FRAME) % ANIMETION_PATTERN;
			
			
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

			//�A�j���[�V�����p�J�E���g
			PLAYER_COUNT++;
			
			//��Ɉړ�����A�j���[�V����
			PLAYER_soeji = PLAYER_UP_SOEJI + (PLAYER_COUNT / ANIMATION_FRAME) % ANIMETION_PATTERN;
			
		}
	}
	//�v���C���[�𑀍삷��@���@���L�[���������ꍇ
	if (Keyboard_Get(KEY_INPUT_DOWN) >= 1)
	{
		//window�̉��[�܂ňړ�����(�v���C���[�̉摜�c�T�C�Y���A�l�����炷)
		if (PLAYER_Y <= GAME_HEIGHT - PLAYER_Size_H / PLAYER_BUNKATU_Y)
		{
			PLAYER_Y += Get_PLAYER_Speed();

			//�A�j���[�V�����p�J�E���g
			PLAYER_COUNT++;
			
			//���Ɉړ�����A�j���[�V����
			PLAYER_soeji = PLAYER_DOWN_SOEJI + (PLAYER_COUNT / ANIMATION_FRAME) % ANIMETION_PATTERN;
			
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

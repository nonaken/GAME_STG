#include "DxLib.h"
#include "WINDOW_SIZE.h"
#include <random>
#include "ENEMY.h"

int ENEMY_Size;						//�v���C���[�̉摜�T�C�Y��LoadDivGrahp�Ŏ擾���邽��
int ENEMY_Size_W, ENEMY_Size_H;		//�v���C���[�摜�̉��T�C�Y�A�c�T�C�Y���擾

//�G�l�~�[X���W�𗐐��Ő�������֐�(�����̓����Z���k�E�c�C�X�^���g�p)
int ENEMY::RANDOM()
{
	std::random_device rd;

	std::mt19937 mt(rd());

	//ENEMY_RANDOM_X_DROW = true;
	//�G�l�~�[�摜�̓Y�����̍ŏ��l����ő�l�܂ł𗐐��Ō��߂�
	std::uniform_int_distribution<int> RANDOM(ENEMY_MIN_SOEJI - 1, ENEMY_MAX_SOEJI - 1);	//�Y�����͍ŏ��P���琔���邽��

	return RANDOM(mt);
}

//�G�l�~�[��X�ʒu�𗐐��Ő�������֐�(�����̓����Z���k�E�c�C�X�^���g�p)
int ENEMY::WINDOW_WIDTH_RANDOM_ENEMY_X()
{
	std::random_device rd;

	std::mt19937 mt(rd());

	//1�`��ʃT�C�Y�̉����܂ł𗐐��Ō��߂�
	std::uniform_int_distribution<int> WINDOW_WIDTH_RANDOM_ENEMY_X(0, GAME_WIDTH - ENEMY_Size_H / ENEMY_BUNKATU_X);

	return WINDOW_WIDTH_RANDOM_ENEMY_X(mt);
}

//�G�l�~�[�𗐐����w�肵���̐��l�ɂȂ����琶������
int ENEMY::ENEMY_SPAWN_RANDOM()
{
	std::random_device rd;

	std::mt19937 mt(rd());

	//ENEMY_RANDOM_X_DROW = true;
	//�G�l�~�[�摜�̓Y�����̍ŏ��l����ő�l�܂ł𗐐��Ō��߂�
	std::uniform_int_distribution<int> ENEMY_SPAWN_RANDOM(ENEMY_MIN_SOEJI - 1, 50);	//�Y�����͍ŏ��P���琔���邽��

	return ENEMY_SPAWN_RANDOM(mt);
}

//�G�l�~�[�̃X�s�[�h���擾����֐�
int ENEMY::Get_ENEMY_Speed()
{
	ENEMY_Speed = 5;
	return ENEMY_Speed;
}

//�G�l�~�[��X�ʒu���擾����֐�
int ENEMY::Get_ENEMY_X()
{
	return ENEMY_X;
}



//�G�l�~�[�̕`�揈��������֐�
void ENEMY::ENEMY_DRAW()
{
	DrawGraph(Get_ENEMY_X(), Get_ENEMY_Y(), ENEMY_Handle[RANDOM_soeji], TRUE);
}

//�G�l�~�[�̏�����������֐�
void ENEMY::ENEMY_RESET()
{
		ENEMY_Y = GAME_MIN_HEIGHT - ENEMY_Size_H / ENEMY_BUNKATU_Y;
		ENEMY_X = WINDOW_WIDTH_RANDOM_ENEMY_X();
		RANDOM_soeji = RANDOM();
}




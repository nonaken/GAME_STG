#include "DxLib.h"
#include "WINDOW_SIZE.h"
#include <random>
#include "ENEMY.h"

int ENEMY_Size;						//�G�l�~�[�̉摜�T�C�Y��LoadDivGrahp�Ŏ擾���邽��
int ENEMY_Size_W, ENEMY_Size_H;		//�G�l�~�[�̉摜�̉��T�C�Y�A�c�T�C�Y���擾

int ENEMY_ANIMATION_Size;						//�G�l�~�[�摜�̃T�C�Y��LoadDivGrahp�Ŏ擾���邽��	(ENEMY.cpp�ł������ϐ��𗘗p���邽�߁Aextern���g�p���Ă���)
int ENEMY_ANIMATION_Size_W, ENEMY_ANIMATION_Size_H;		//�G�l�~�[�摜�̉��T�C�Y�A�c�T�C�Y���擾	(ENEMY.cpp�ł������ϐ��𗘗p���邽�߁Aextern���g�p���Ă���)



//�G�l�~�[�̓Y�����𗐐��Ő�������֐�(�����̓����Z���k�E�c�C�X�^���g�p)
int ENEMY::RANDOM()
{
	std::random_device rd;

	std::mt19937 mt(rd());

	//ENEMY_RANDOM_X_DROW = true;
	//�G�l�~�[�摜�̓Y�����̍ŏ��l����ő�l�܂ł𗐐��Ō��߂�
	//std::uniform_int_distribution<int> RANDOM(ENEMY_MIN_SOEJI - 1, ENEMY_MAX_SOEJI - 1);	//�Y�����͍ŏ��P���琔���邽��
	std::uniform_int_distribution<int> RANDOM(ENEMY_MIN_SOEJI - 1, ENEMY_RANDOM_soeji_MAX);	//�Y�����͍ŏ��P���琔���邽��
	
	//if (RANDOM(mt) != 0 || RANDOM(mt) % 3 != 0)
	//{
	//	std::uniform_int_distribution<int> RANDOM(ENEMY_MIN_SOEJI - 1, ENEMY_RANDOM_soeji_MAX);	//�Y�����͍ŏ��P���琔���邽��
	//}

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

/*
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
*/

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

//�G�l�~�[�̔����A�j���[�V������`�悷��֐�
void ENEMY::ENEMY_ANIMATION_DRAW(int x,int y)
{
	//DrawGraph(Get_ENEMY_X() - ENEMY_ANIMATION_Size_W / ENEMY_ANIMATION_BUNKATU_X / 2, Get_ENEMY_Y() - ENEMY_ANIMATION_Size_H / ENEMY_ANIMATION_BUNKATU_Y / 2, ENEMY_ANIMATION_Handle[ENEMY_ANIMATION_soeji], TRUE);

	DrawGraph(Get_ENEMY_X() - x, Get_ENEMY_Y() - y,ENEMY_ANIMATION_Handle[ENEMY_ANIMATION_soeji], TRUE);

}


//�G�l�~�[�̏�����������֐�
void ENEMY::ENEMY_RESET()
{
		ENEMY_Y = GAME_MIN_HEIGHT - ENEMY_Size_H / ENEMY_BUNKATU_Y;
		ENEMY_X = WINDOW_WIDTH_RANDOM_ENEMY_X();
		RANDOM_soeji = RANDOM();
		if (RANDOM_soeji != 0 && RANDOM_soeji % ENEMY_ANIMATION_PATTERN != 0)
		{
			RANDOM_soeji = RANDOM();
		}
		else
		{
			ENEMY_RANDOM_soeji_Evacuation = RANDOM_soeji;
		}
}




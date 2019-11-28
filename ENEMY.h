#pragma once
#include "window_size.h"
#include <random>

#define GAME_ENEMY		"�N���X�}�X�L�����`�b�v\\�e�X�g.jpg"			//�L�����N�^�[�摜
#define ENEMY_BUNKATU	12		//�v���C���[�摜�̑�������
#define ENEMY_BUNKATU_X 4//3	//�v���C���[�摜�̉�������
#define ENEMY_BUNKATU_Y 3//4	//�v���C���[�摜�̏c������

#define ENEMY_MIN_SOEJI 1		//�G�l�~�[�̍ŏ��̉摜
#define ENEMY_MAX_SOEJI 12		//�G�l�~�[�̍Ō�̉摜

#define ENEMY_NUM 3 //��ʂɓo�ꂷ��G�l�~�[�̐�

int ENEMY_Size;	//�摜�̉��Əc�̃T�C�Y�𒲂ׂ邽�߂̕ϐ�
int ENEMY_Size_W, ENEMY_Size_H;

class ENEMY
{
private:

	int ENEMY_HP;
	int ENEMY_Speed;
	
public:
	
	int ENEMY_X = WINDOW_WIDTH_RANDOM_ENEMY_X();
	int ENEMY_Y;
	int WINDOW_WIDTH_RANDOM_ENEMY_X();
	int RANDOM();
	int ENEMY_Handle[ENEMY_MAX_SOEJI];
	
	int Get_ENEMY_Speed();
	int Get_ENEMY_Y();
	int Get_ENEMY_X();
	void ENEMY_DRAW();
	void ENEMY_RESET();
	int RANDOM_soeji = RANDOM();

	//ENEMY();
	//~ENEMY();


};

//ENEMY::ENEMY()
//{
//	for (int num = 0; num < ENEMY_NUM; num++)
//	{
//		e[num] = NULL;
//	}
//}
//
//ENEMY::~ENEMY()
//{
//	for (int num = 0; num < ENEMY_NUM; num++)
//	{
//		delete e[num];
//	}
//}

//�G�l�~�[X���W�𗐐��Ő�������
int ENEMY::RANDOM()
{

	std::random_device rd;

	std::mt19937 mt(rd());

	//ENEMY_RANDOM_X_DROW = true;
	//1�`��ʃT�C�Y�̉����܂ł𗐐��Ō��߂�
	std::uniform_int_distribution<int> RANDOM(ENEMY_MIN_SOEJI - 1, ENEMY_MAX_SOEJI - 1);	//�Y�����͍ŏ��P���琔���邽��

	return RANDOM(mt);
}

//�G�l�~�[��X�ʒu�𗐐��Ő�������֐�
int ENEMY::WINDOW_WIDTH_RANDOM_ENEMY_X()
{
	std::random_device rd;

	std::mt19937 mt(rd());

	//1�`��ʃT�C�Y�̉����܂ł𗐐��Ō��߂�
	std::uniform_int_distribution<int> WINDOW_WIDTH_RANDOM_ENEMY_X(0, GAME_WIDTH - ENEMY_Size_W / ENEMY_BUNKATU_X);

	return WINDOW_WIDTH_RANDOM_ENEMY_X(mt);
}

//�G�l�~�[�̃X�s�[�h��ݒ肷��
int ENEMY::Get_ENEMY_Speed()
{
	ENEMY_Speed = 10;
	return ENEMY_Speed;
}


int ENEMY::Get_ENEMY_Y()
{
	ENEMY_Y += Get_ENEMY_Speed();
	if (ENEMY_Y > GAME_HEIGHT)
	{
		ENEMY_Y = 0;
		ENEMY_X = WINDOW_WIDTH_RANDOM_ENEMY_X();
		RANDOM_soeji = RANDOM();
	}

	return ENEMY_Y;
}

int ENEMY::Get_ENEMY_X()
{
	return ENEMY_X;
}


void ENEMY::ENEMY_DRAW()
{
	DrawGraph(Get_ENEMY_X(), Get_ENEMY_Y(), ENEMY_Handle[RANDOM_soeji], TRUE);
}

void ENEMY::ENEMY_RESET()
{
	ENEMY_Y = 0;
	ENEMY_X = WINDOW_WIDTH_RANDOM_ENEMY_X();
	RANDOM_soeji = RANDOM();
}



#pragma once

#include"WINDOW_SIZE.h"

#define GAME_PLAYER "animals\\$yaksaddle.png"//"PLAYER\\player_�k��.png"
#define PLAYER_BUNKATU	12			//�v���C���[�摜�̑�������
#define PLAYER_BUNKATU_X 3//3		//�v���C���[�摜�̉�������
#define PLAYER_BUNKATU_Y 4//4		//�v���C���[�摜�̏c������
#define PLAYER_MIN_SOEJI 1			//�v���C���[�̍ŏ��̉摜
#define PLAYER_MAX_SOEJI 12			//�v���C���[�̍Ō�̉摜

#define PLAYER_X_HALF 2
#define PLAYER_Y_HALF 2


class PLAYER{
private:
	
	int PLAYER_Speed;		//�v���C���[�̃X�s�[�h

public:
	int PLAYER_HP = 3;		//�v���C���[�̗̑�
	int PLAYER_X;		//�v���C���[�̏���X�ʒu
	int PLAYER_Y;		//�v���C���[�̏���Y�ʒu
	int PLAYER_soeji = 0;				//�v���C���[�̓Y�����Ɏg��
	int PLAYER_Handle[PLAYER_MAX_SOEJI];//�v���C���[�̃n���h��
	int Get_PLAYER_Speed();				//�v���C���[�̃X�s�[�h���֐��Ŏ擾
	int Get_PLAYER_X();					//�v���C���[��X�ʒu���֐��Ŏ擾
	int Get_PLAYER_Y();					//�v���C���[��Y�ʒu���֐��Ŏ擾
	void PLAYER_DRAW();					//�v���C���[��`�悷��֐�
	void PLAYER_RESET();
	void PLAYER_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y);		//�v���C���[�ƃG�l�~�[�̏Փ˔��������֐�
	int PLAYER_COUNT = 0;
};




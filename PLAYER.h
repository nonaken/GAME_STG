#pragma once

#include"WINDOW_SIZE.h"

#define GAME_PLAYER "animals\\�����L3�{.png"//"animals\\$yaksaddle.png"//"PLAYER\\player_�k��.png"
#define PLAYER_BUNKATU	12			//�v���C���[�摜�̑�������
#define PLAYER_BUNKATU_X 3//3		//�v���C���[�摜�̉�������
#define PLAYER_BUNKATU_Y 4//4		//�v���C���[�摜�̏c������
#define PLAYER_MIN_SOEJI 1			//�v���C���[�̍ŏ��̉摜
#define PLAYER_MAX_SOEJI 12			//�v���C���[�̍Ō�̉摜

#define PLAYER_X_HALF 2				//�v���C���[�̏���X�ʒu(��ʂ̉��� / 2)
#define PLAYER_Y_HALF 2				//�v���C���[�̏���Y�ʒu(��ʂ̏c�� / 2)

#define PLAYER_INVINCIBLE_TIME 1	//�v���C���[�̖��G����


#define PLAYER_DOWN_SOEJI 0			//�������̉摜
#define PLAYER_UP_SOEJI 9			//������̉摜
#define PLAYER_LEFT_SOEJI 3			//�������̉摜
#define PLAYER_RIGHT_SOEJI 6		//�E�����̉摜

#define PLAYER_HIT_INVINCIBLE_ANIMATION	"ANIMATION\\���G.png"	//"ANIMATION\\���G�G�t�F�N�g2.png"//�v���C���[�̖��G�A�j���[�V�����摜
#define PLAYER_HIT_INVINCIBLE_ANIMATION_BUNKATU	12				//�v���C���[�̖��G�A�j���[�V�����摜�̑�������
#define PLAYER_HIT_INVINCIBLE_ANIMATION_BUNKATU_X 12			//�v���C���[�̖��G�A�j���[�V�����摜�̉�������
#define PLAYER_HIT_INVINCIBLE_ANIMATION_BUNKATU_Y 1				//�v���C���[�̖��G�A�j���[�V�����摜�̏c������

#define PLAYER_HIT_INVINCIBLE_ANIMATION_FRAME 5//10				//�v���C���[�̖��G�A�j���[�V�����̕`���؂�ւ���t���[����
#define PLAYER_HIT_INVINCIBLE_ANIMATION_PATTERN 12//3			//�v���C���[�̖��G�A�j���[�V�����̎��


#define PLAYER_ANIMATION_FRAME 5				//�v���C���[�̖��G�A�j���[�V�����`���؂�ւ���t���[����
#define PLAYER_ANIMETION_PATTERN 3				//�v���C���[�̖��G�A�j���[�V�������

#define PLAYER_HIT_ANIMATION_MIN_SOEJI 1		//�v���C���[�̖��G�A�j���[�V�����̍ŏ��l
#define PLAYER_HIT_ANIMATION_MAX_SOEJI 12		//�v���C���[�̖��G�A�j���[�V�����̍ő�l

//�v���C���[�̃N���X
class PLAYER{
private:
	
	int PLAYER_Speed;	//�v���C���[�̃X�s�[�h

public:
	int PLAYER_HP = 3;	//�v���C���[�̗̑�
	int PLAYER_X;		//�v���C���[�̏���X�ʒu
	int PLAYER_Y;		//�v���C���[�̏���Y�ʒu
	int PLAYER_soeji = 0;				//�v���C���[�̓Y�����Ɏg��
	int PLAYER_Handle[PLAYER_MAX_SOEJI];//�v���C���[�̃n���h��
	int FontHandle_PLAYER_HP = 0;		//�v���C���[��HP��`�悷��t�H���g�n���h���p�ϐ�

	bool PLAYER_MOVE_flag = false;		//�v���C���[�����������Ǘ�����t���O(�����������ł��Ȃ�����)
	bool PLAYER_INVINCIBLE_flag = false;//�v���C���[���G�ɐG�ꂽ���莞�Ԗ��G�^�C���ɂ���(�X�R�A�͑����Ȃ�)

	int Get_PLAYER_Speed();				//�v���C���[�̃X�s�[�h���֐��Ŏ擾
	int Get_PLAYER_X();					//�v���C���[��X�ʒu���֐��Ŏ擾
	int Get_PLAYER_Y();					//�v���C���[��Y�ʒu���֐��Ŏ擾
	void PLAYER_HP_DRAW();
	void PLAYER_DRAW();					//�v���C���[��`�悷��֐�
	void PLAYER_RESET();				//�v���C���[�̏����ݒ�
	void PLAYER_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y);		//�v���C���[�ƃG�l�~�[�̏Փ˔��������֐�
	int PLAYER_COUNT = 0;				//�v���C���[�̃A�j���[�V�����p�J�E���g

	int PLAYER_HIT_ANIMATION_COUNT = 0;
	int PLAYER_HIT_ANIMATION_soeji = 0;
	int PLAYER_HIT_ANIMATION_Handle[PLAYER_HIT_ANIMATION_MAX_SOEJI];	//�v���C���[�̃A�j���[�V�����摜�̓Y����������
	void PLAYER_ANIMATION_DRAW(int x, int y);
};




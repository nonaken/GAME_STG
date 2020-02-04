#pragma once
#include"PLAYER.h"

#define GAME_WEAPON "WEAPON\\���΂�3�{.png"//"WEAPON\\���e.png"
#define WEAPON_BUNKATU	12//60			//�E�G�|���摜�̑�������
#define WEAPON_BUNKATU_X 3//6		//�E�G�|���摜�̉�������
#define WEAPON_BUNKATU_Y 4//10		//�E�G�|���摜�̏c������
#define WEAPON_MIN_SOEJI 1			//�E�G�|���̍ŏ��̉摜
#define WEAPON_MAX_SOEJI 12//60			//�E�G�|���̍Ō�̉摜

#define WEAPON_X_HALF 2	//�E�G�|����X�ʒu���v���C���[�̉摜�T�C�Y�̔����ɐݒ肷�邽�߂̃}�N����`

#define WEAPON_NUM 3				//��ʂɕ\���ł���E�G�|���̐�

#define WEAPON_ANIMATION_EXPROSION_FRAME	20	//�E�G�|���̃A�j���[�V�����`��t���[��
#define WEAPON_ANIMATION_PATTERN		3		//�E�G�|���̃A�j���[�V�����o�^�[��
#define WEAPON_NEXT_ATACKSPEED 0.3				//�E�G�|���̔��ˎ���


class WEAPON : public PLAYER
{
private:
	int WEAPON_Speed = 0;			//�E�G�|���摜�̏㏸���x
public:
	int WEAPON_Handle[WEAPON_MAX_SOEJI];	//�E�G�|���摜���i�[����z��̗v�f��
	int WEAPON_X;							//�E�G�|���摜��X�ʒu���v���C���[�̉摜�T�C�Y�̔����ɐݒ肷��
	int WEAPON_Y;							//�E�G�|���摜��Y�ʒu���v���C���[��Y�ʒu�������l�Ƃ���(�v���C���[�̏�ɂ���悤�ɂ���)
	int WEAPON_soeji = 0;					//�E�G�|���摜�̓Y����

	int Get_WEAPON_Speed(int WEAPON_Speed);			//�E�G�|���̃X�s�[�h���擾�擾����֐�
	int Get_WEAPON_Y();				//�E�G�|����X�ʒu���擾�擾����֐�
	int Get_WEAPON_X();				//�E�G�|����Y�ʒu���擾�擾����֐�
	void WEAPON_DRAW(int, int);				//�E�G�|����`�悷��֐�
	void WEAPON_RESET();			//�E�G�|�������Z�b�g����֐�
	void WEAPON_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y);		//�E�G�|���ƃG�l�~�[�̏Փ˔��������֐�
	//int WEAPON_SPAWN_RANDOM();


	int WEAPON_ANIMATION_COUNT = 0;			//���e�̃A�j���[�V�����p�J�E���g


	bool WEAPON_flag_X = false;
	bool WEAPON_flag_Y = false;
	bool WEAPON_Next_flag = false;
};


#pragma once


#define GAME_ENEMY		"�N���X�}�X�L�����`�b�v\\�e�X�g.jpg"			//�L�����N�^�[�摜
#define ENEMY_BUNKATU	12		//�v���C���[�摜�̑�������
#define ENEMY_BUNKATU_X 4//3	//�v���C���[�摜�̉�������
#define ENEMY_BUNKATU_Y 3//4	//�v���C���[�摜�̏c������

#define ENEMY_MIN_SOEJI 1		//�G�l�~�[�̍ŏ��̉摜
#define ENEMY_MAX_SOEJI 12		//�G�l�~�[�̍Ō�̉摜

#define ENEMY_NUM 3				//��ʂɓo�ꂷ��G�l�~�[�̐�


class ENEMY
{
private:

	int ENEMY_HP;		//�G�l�~�[��HP
	int ENEMY_Speed;	//�G�l�~�[�̃X�s�[�h(�������x)

public:

	int ENEMY_X = WINDOW_WIDTH_RANDOM_ENEMY_X();	//�G�l�~�[��X���W(����X�ʒu�𗐐��Őݒ肵�Ă���)
	int ENEMY_Y;									//�G�l�~�[��Y���W
	int WINDOW_WIDTH_RANDOM_ENEMY_X();	//�G�l�~�[��X�ʒu�𗐐��Ő�������֐�
	int RANDOM();		//�G�l�~�[�̉摜�̓Y�����𗐐��Ő�������֐�
	int ENEMY_Handle[ENEMY_MAX_SOEJI];	//�G�l�~�[�̉摜�̓Y����������z��i�v�f���̓G�l�~�[�̉摜�̍Ō�̓Y�������j

	int Get_ENEMY_Speed();			//�G�l�~�[�̃X�s�[�h���擾
	int Get_ENEMY_Y();				//�G�l�~�[��X�ʒu���擾
	int Get_ENEMY_X();				//�G�l�~�[��Y�ʒu���擾
	void ENEMY_DRAW();				//�G�l�~�[�̕`�揈��������֐�
	void ENEMY_RESET();				//�G�l�~�[�̏�����������֐�
	int RANDOM_soeji = RANDOM();	//�G�l�~�[�̓Y�����𗐐�����擾
	

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

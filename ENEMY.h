#pragma once


#define GAME_ENEMY					"animals\\Bison.png"		//�G�l�~�[�̃L�����N�^�[�摜
#define ENEMY_BUNKATU	96		//�G�l�~�[�摜�̑�������
#define ENEMY_BUNKATU_X 12//3	//�G�l�~�[�摜�̉�������
#define ENEMY_BUNKATU_Y 8//4	//�G�l�~�[�摜�̏c������

#define ENEMY_MIN_SOEJI 1		//�G�l�~�[�̍ŏ��̉摜
#define ENEMY_MAX_SOEJI 96		//�G�l�~�[�̍Ō�̉摜

#define ENEMY_NUM 3				//��ʂɓo�ꂷ��G�l�~�[�̐�

#define ENEMY_EXPROSION_ANIMATION	"ANIMATION\\�Փˉ��o.png"	//�G�l�~�[�̔����A�j���[�V�����摜
#define ENEMY_ANIMATION_BUNKATU	6		//�G�l�~�[�摜�̑�������
#define ENEMY_ANIMATION_BUNKATU_X 5//3	//�G�l�~�[�摜�̉�������
#define ENEMY_ANIMATION_BUNKATU_Y 2//4	//�G�l�~�[�摜�̏c������
#define ENEMY_ANIMATION_MIN_SOEJI 1		//�G�l�~�[�̍ŏ��̉摜
#define ENEMY_ANIMATION_MAX_SOEJI 5		//�G�l�~�[�̍Ō�̉摜


class ENEMY
{
private:

	int ENEMY_HP;		//�G�l�~�[��HP
	int ENEMY_Speed;	//�G�l�~�[�̃X�s�[�h(�������x)

public:

	int ENEMY_X = WINDOW_WIDTH_RANDOM_ENEMY_X();	//�G�l�~�[��X���W(����X�ʒu�𗐐��Őݒ肵�Ă���)
	int ENEMY_Y;									//�G�l�~�[��Y���W
	int WINDOW_WIDTH_RANDOM_ENEMY_X();	//�G�l�~�[��X�ʒu�𗐐��Ő�������֐�
	int RANDOM();						//�G�l�~�[�̉摜�̓Y�����𗐐��Ő�������֐�
	int ENEMY_Handle[ENEMY_MAX_SOEJI];	//�G�l�~�[�̉摜�̓Y����������z��i�v�f���̓G�l�~�[�̉摜�̍Ō�̓Y�������j

	int Get_ENEMY_Speed();			//�G�l�~�[�̃X�s�[�h���擾
	int Get_ENEMY_Y();				//�G�l�~�[��X�ʒu���擾
	int Get_ENEMY_X();				//�G�l�~�[��Y�ʒu���擾
	void ENEMY_DRAW();				//�G�l�~�[�̕`�揈��������֐�
	void ENEMY_RESET();				//�G�l�~�[�̏�����������֐�
	int RANDOM_soeji = RANDOM();	//�G�l�~�[�̓Y�����𗐐�����擾

	bool ENEMY_EXPROSION_flag = false;	//�G�l�~�[�̔����t���O
	int ENEMY_ANIMATION_soeji = 0;	//�G�l�~�[�̃A�j���[�V�����p�Y����
	int ENEMY_ANIMATION_Handle[ENEMY_ANIMATION_MAX_SOEJI];	//�G�l�~�[�̃A�j���[�V�����摜�̓Y����������z��i�v�f���̓G�l�~�[�̉摜�̍Ō�̓Y�������j
	void ENEMY_ANIMATION_DRAW(int ,int);	//�G�l�~�[�̔����A�j���[�V������`�悷��֐�
	int ENEMY_COUNT = 0;			//�G�l�~�[�̃A�j���[�V�����p�J�E���g
	//int ENEMY_SPAWN_RANDOM();

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

//*******************�C���N���[�h*************
#include "DxLib.h"
#include "Keyboard_Get.h"
#include "PLAYER.h"
#include "ENEMY.h"
#include "WEAPON.h"
#include "SCORE.h"
#include "WINDOW_SIZE.h"
#include "FPS.h"
#include "DIFFICULTY_LEVEL.h"
#include "Background_Scroll.h"
#include "BGM.h"
//******************************************

//***********************�}�N����`******************************************************************
#define GAME_BackImage_TITLE	"BackImage\\�w�i.png"//"BackImage\\kaidou0331_800b.jpg"	//�^�C�g����ʔw�i�摜
#define GAME_TITLE_LOG			"BackImage\\game_title_font.png"	//�^�C�g�����S
#define GAME_BackImage_PLAY		"BackImage\\�w�i.png"				//�v���C��ʔw�i�摜
#define GAME_BackImage_CLEAR	"BackImage\\GAME_CLEAR.jpg"			//�N���A��ʔw�i�摜
#define GAME_BackImage_END		"BackImage\\GAME_OVER_2.jpg"			//�G���h��ʔw�i�摜

#define GAME_FPS_SPEED		60			//FPS��ݒ�

#define GAME_TITLE_LOG_UPPERLEFT_X		GAME_WIDTH / 4					//�^�C�g�����S�摜�̍���X���W
#define GAME_TITLE_LOG_UPPERLEFT_Y		GAME_HEIGHT / 3					//�^�C�g�����S�摜�̍���Y���W
#define GAME_TITLE_LOG_BOTTOMLEFT_X		GAME_WIDTH - GAME_WIDTH / 4		//�^�C�g�����S�摜�̉E��X���W
#define GAME_TITLE_LOG_BOTTOMLEFT_Y		GAME_HEIGHT - GAME_HEIGHT / 3	//�^�C�g�����S�摜�̉E��Y���W

#define LIMIT_TIME 60 //�������� 
#define PLAY_END_TIME 0 //�I������

#define PLAY_MUSIC "MUSIC\\crying again.mp3"		//�~���[�W�b�N����荞��
#define COLISION_MUSIC "MUSIC\\colision.mp3"		//�~���[�W�b�N����荞��
//*****************************************************************************************************

//****************�񋓌^************:
//�e��ʂ�ݒ�
enum GAME_SCREEN
{
	GAME_TITLE,	//�^�C�g�����
	GAME_PLAY,	//�v���C���
	GAME_CLEAR,	//�N���A���
	GAME_END	//�G���h���
};
//****************************************

//�Q�[����ʂ̑J�ڂ��Ǘ�����
GAME_SCREEN screen_state = GAME_TITLE;	//��ʑJ�ڂ��R���g���[������(�ŏ��̉�ʂ̓^�C�g�����)

//*************************************�v���g�^�C�v�錾******************************
void GAME_TITLE_DRAW();		//�^�C�g����ʂ�`��
void GAME_PLAY_DRAW();		//�v���C��ʂ�`��
void GAME_CLEAR_DRAW();		//�N���A��ʂ�`��
void GAME_END_DRAW();		//�G���h��ʂ�`��
//*************************************************************************************

//*****************�N���X*********************************************
FPS *fps = new FPS(GAME_FPS_SPEED);		//FPS�N���X�̃I�u�W�F�N�g�𐶐�
PLAYER *p = new PLAYER();				//�v���C���[�̃I�u�W�F�N�g�𐶐�����
//WEAPON *w = new WEAPON();				//�E�G�|���̃I�u�W�F�N�g�𐶐�����
WEAPON *w[WEAPON_NUM];					//�E�G�|���N���X���T��������
ENEMY *e[ENEMY_NUM];					//�G�l�~�[�N���X���R��������
SCORE *s = new SCORE();					//�X�R�A�̃I�u�W�F�N�g�𐶐�
DIFFICULTY *Difficulty_Level = new DIFFICULTY();		//��Փx�ύX��ݒ肷��N���X�𐶐�����
CLEARCONDITION *ClearCondition_Level = new CLEARCONDITION();
BACKGROUND *Background = new BACKGROUND();
BGM *bgm = new BGM();
//********************************************************************

//************************�摜�̃T�C�Y���擾����ϐ�**************************************
extern int PLAYER_Size;						//�v���C���[�摜�̃T�C�Y��LoadDivGrahp�Ŏ擾���邽��(PLAYER.cpp�ł������ϐ��𗘗p���邽�߁Aextern���g�p���Ă���)
extern int PLAYER_Size_W, PLAYER_Size_H;	//�v���C���[�摜�̉��T�C�Y�A�c�T�C�Y���擾			(PLAYER.cpp�ł������ϐ��𗘗p���邽�߁Aextern���g�p���Ă���)
extern int ENEMY_Size;						//�G�l�~�[�摜�̃T�C�Y��LoadDivGrahp�Ŏ擾���邽��	(ENEMY.cpp�ł������ϐ��𗘗p���邽�߁Aextern���g�p���Ă���)
extern int ENEMY_Size_W, ENEMY_Size_H;		//�G�l�~�[�摜�̉��T�C�Y�A�c�T�C�Y���擾			(ENEMY.cpp�ł������ϐ��𗘗p���邽�߁Aextern���g�p���Ă���)
extern int WEAPON_Size;						//�E�G�|���摜�̃T�C�Y��LoadDivGrahp�Ŏ擾���邽��	(ENEMY.cpp�ł������ϐ��𗘗p���邽�߁Aextern���g�p���Ă���)
extern int WEAPON_Size_W, WEAPON_Size_H;	//�G�l�~�[�摜�̉��T�C�Y�A�c�T�C�Y���擾			(ENEMY.cpp�ł������ϐ��𗘗p���邽�߁Aextern���g�p���Ă���)

extern int ENEMY_ANIMATION_Size;						//�G�l�~�[�摜�̃T�C�Y��LoadDivGrahp�Ŏ擾���邽��	(ENEMY.cpp�ł������ϐ��𗘗p���邽�߁Aextern���g�p���Ă���)
extern int ENEMY_ANIMATION_Size_W, ENEMY_ANIMATION_Size_H;		//�G�l�~�[�摜�̉��T�C�Y�A�c�T�C�Y���擾	(ENEMY.cpp�ł������ϐ��𗘗p���邽�߁Aextern���g�p���Ă���)

//*******************************************************************************************


//**********************�w�i�摜�����[�h����ϐ�**************************
int imgBack_Title = 0;
int imgTitle_log = 0;
int imgBack_End = 0;
int imgBack_Clear = 0;
//************************************************************************


//**********************���Ԃ��擾����ϐ�**************************
double GAME_TITLE_ELAPSEDTIME = 0; //�v���C��ʂɑJ�ڂ���܂ł̎��Ԃ��v��
int Get_WEAPON_Time;
double Get_Collision_Time;		//�G�l�~�[���E�G�|���ɂ����������Ԃ��擾����
double Get_Time = 0;			//GetNowCount()�p�̕ϐ��F�N�������玞�Ԃ��v������

//GetNowCount()�͋N�����Ă��玞�Ԃ��v�����邽�߁A�v���C��ʂɑJ�ڂ���܂ł̊|���������Ԃ������K�v������
//GetNowCount() - timerstart = �v���C��ʂɂȂ����玞�Ԃ��v������

//***************������`�悷��ϐ�*****************
int FontHandle_LIMIT = 0;
int FontHandle_ScreenTransition = 0;
//**************************************************

int count = 0;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ɐݒ�(TRUE: FALSE:�t���X�N���[��)
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������
	
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;				// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);			//�`��𗠉�ʂɐݒ�

	PLAYER_Size = LoadGraph(GAME_PLAYER);	//�v���C���[�摜�̏c�Ɖ��̃T�C�Y���擾���邽�߃��[�h����(�����Ɏ̂Ă�)

	GetGraphSize(PLAYER_Size, &PLAYER_Size_W, &PLAYER_Size_H);	//�v���C���[�摜�̏c�Ɖ��̃T�C�Y���擾

	DeleteGraph(PLAYER_Size);				//�v���C���[�摜�̏c�Ɖ��̃T�C�Y���擾������A�g���̂�

	//�v���C���[�摜���w�肵���������A�T�C�Y�œǂݍ���
	LoadDivGraph(GAME_PLAYER, PLAYER_BUNKATU, PLAYER_BUNKATU_X, PLAYER_BUNKATU_Y, PLAYER_Size_W / PLAYER_BUNKATU_X, PLAYER_Size_H / PLAYER_BUNKATU_Y, &p->PLAYER_Handle[0]);
	
	WEAPON_Size = LoadGraph(GAME_WEAPON);	//�E�G�|���摜�̏c�Ɖ��̃T�C�Y���擾���邽�߃��[�h����(�����Ɏ̂Ă�)

	GetGraphSize(WEAPON_Size, &WEAPON_Size_W, &WEAPON_Size_H);	//�E�G�|���摜�̏c�Ɖ��̃T�C�Y���擾

	DeleteGraph(WEAPON_Size);				//�E�G�|���摜�̏c�Ɖ��̃T�C�Y���擾������A�g���̂�

	//�E�G�|���摜���w�肵���������A�T�C�Y�œǂݍ���
	//LoadDivGraph(GAME_WEAPON, WEAPON_BUNKATU, WEAPON_BUNKATU_X, WEAPON_BUNKATU_Y, WEAPON_Size_W / WEAPON_BUNKATU_X, WEAPON_Size_H / WEAPON_BUNKATU_Y, &w->WEAPON_Handle[0]);

	for (int w_cnt = 0;  w_cnt < WEAPON_NUM;  w_cnt++)
	{
		//�z��̌����G�l�~�[�N���X�𐶐�����
		w[w_cnt] = new WEAPON();
		//�E�G�|���摜���w�肵���������A�T�C�Y�œǂݍ���
		LoadDivGraph(GAME_WEAPON, WEAPON_BUNKATU, WEAPON_BUNKATU_X, WEAPON_BUNKATU_Y, WEAPON_Size_W / WEAPON_BUNKATU_X, WEAPON_Size_H / WEAPON_BUNKATU_Y, &w[w_cnt]->WEAPON_Handle[0]);
	}

	//�v���C���[�摜�̏c�Ɖ��̃T�C�Y���擾���邽�߃��[�h����(�����Ɏ̂Ă�)
	ENEMY_Size = LoadGraph(GAME_ENEMY);	

	//�v���C���[�摜�̏c�Ɖ��̃T�C�Y���擾
	GetGraphSize(ENEMY_Size, &ENEMY_Size_W, &ENEMY_Size_H);	

	//�v���C���[�摜�̏c�Ɖ��̃T�C�Y���擾������A�g���̂�
	DeleteGraph(ENEMY_Size);

	//�G�l�~�[�̔����A�j���[�V�����p�摜�̏c�Ɖ��̃T�C�Y���擾���邽�߃��[�h����i�����Ɏ̂Ă�j
	ENEMY_ANIMATION_Size = LoadGraph(ENEMY_EXPROSION_ANIMATION);

	//�G�l�~�[�̔����A�j���[�V�����p�摜�̏c�Ɖ��̃T�C�Y���擾
	GetGraphSize(ENEMY_ANIMATION_Size, &ENEMY_ANIMATION_Size_W, &ENEMY_ANIMATION_Size_H);

	//�G�l�~�[�̔����A�j���[�V�����p�摜�̏c�Ɖ��̃T�C�Y���擾������A�g���̂�
	DeleteGraph(ENEMY_ANIMATION_Size);


	for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
	{
		//�z��̌����G�l�~�[�N���X�𐶐�����
		e[e_num] = new ENEMY();
		//�G�l�~�[�摜��z��̌����A�w�肵���������A�T�C�Y�œǂݍ���
		LoadDivGraph(GAME_ENEMY, ENEMY_BUNKATU, ENEMY_BUNKATU_X, ENEMY_BUNKATU_Y, ENEMY_Size_W / ENEMY_BUNKATU_X, ENEMY_Size_H / ENEMY_BUNKATU_Y, &e[e_num]->ENEMY_Handle[0]);

		//�����A�j���[�V�����̉摜��z��̌����A�w�肵���������A�T�C�Y�œǂݍ���
		LoadDivGraph(ENEMY_EXPROSION_ANIMATION, ENEMY_ANIMATION_BUNKATU, ENEMY_ANIMATION_BUNKATU_X, ENEMY_ANIMATION_BUNKATU_Y, ENEMY_ANIMATION_Size_W / ENEMY_ANIMATION_BUNKATU_X, ENEMY_ANIMATION_Size_H / ENEMY_ANIMATION_BUNKATU_Y, &e[e_num]->ENEMY_ANIMATION_Handle[0]);
	}
	//int ENEMY_BUNKATU_SIZE_X = 0,  ENEMY_BUNKATU_SIZE_Y= 0, ANIMATION_BUNKATU_SIZE_X = 0, ANIMATION_BUNKATU_SIZE_Y = 0;

	//GetGraphSize(e[0]->ENEMY_Handle[0], &ENEMY_BUNKATU_SIZE_X, &ENEMY_BUNKATU_SIZE_Y);	//�v���C���[�摜�̏c�Ɖ��̃T�C�Y���擾

	//GetGraphSize(e[0]->ENEMY_ANIMATION_Handle[0], &ANIMATION_BUNKATU_SIZE_X, &ANIMATION_BUNKATU_SIZE_Y);	//�v���C���[�摜�̏c�Ɖ��̃T�C�Y���擾

	//�^�C�g����ʂ̔w�i�̉摜��ǂݍ���
	imgBack_Title = LoadGraph(GAME_BackImage_TITLE);		//�^�C�g���w�i�摜��ǂݍ���(*���ӁFwhile���œǂݍ��ނ�FPS���ቺ����[����ǂݍ���ł��܂�����])
	//�^�C�g�����S�̉摜��ǂݍ���
	imgTitle_log = LoadGraph(GAME_TITLE_LOG);				//�^�C�g�����S�摜��ǂݍ���(*���ӁFwhile���œǂݍ��ނ�FPS���ቺ����[����ǂݍ���ł��܂�����])
	
	//�v���C��ʂ̔w�i�摜��ǂݍ���
	Background->imgBack_Scroll = LoadGraph(GAME_BackImage_PLAY);			//�v���C�w�i�摜��ǂݍ���(*���ӁFwhile���œǂݍ��ނ�FPS���ቺ����[����ǂݍ���ł��܂�����])

	//�N���A��ʂ̔w�i�摜��ǂݍ���
	imgBack_Clear = LoadGraph(GAME_BackImage_CLEAR);		//�N���A�w�i�摜��ǂݍ���(*���ӁFwhile���œǂݍ��ނ�FPS���ቺ����[����ǂݍ���ł��܂�����])

	//�G���h��ʂ̔w�i�摜��ǂݍ���
	imgBack_End = LoadGraph(GAME_BackImage_END);			//�G���h�w�i�摜��ǂݍ���(*���ӁFwhile���œǂݍ��ނ�FPS���ቺ����[����ǂݍ���ł��܂�����])
	
	//��ʑJ�ڂ��ē�����t�H���g�n���h�����쐬
	FontHandle_ScreenTransition = CreateFontToHandle(NULL, 50, 5);		//�����̑傫���ύX

	//�v���C���[��HP��`�悷��t�H���g�n���h�����쐬
	p->FontHandle_PLAYER_HP = CreateFontToHandle(NULL, 50, 5);		//�����̑傫���ύX

	//��Փx�ύX�p�̃t�H���g�n���h�����쐬
	Difficulty_Level->FontHandle_LV_SELECT = CreateFontToHandle(NULL, 50, 3);	//�����̑傫���ύX

	//�N���A�����ύX�p�̃t�H���g�n���h�����쐬
	ClearCondition_Level->FontHandle_ClearCondition_SELECT = CreateFontToHandle(NULL, 40, 3);	//�����̑傫���ύX

	//�������ԗp�̃t�H���g�n���h�����쐬
	FontHandle_LIMIT = CreateFontToHandle(NULL, 60, 3);		//�����̑傫���ύX

	//�l���X�R�A�`��p�̃t�H���g�n���h�����쐬
	s->FontHandle_SCORE = CreateFontToHandle(NULL, 50, 3); //�����̑傫���ύX

	//FPS�`��p�̃t�H���g�n���h�����쐬
	fps->FontHandle_FPS = CreateFontToHandle(NULL, 50, 3); //�����̑傫���ύX

	//�}�N���Œ�`�������y�t�@�C�������[�h���A���ʔԍ���MUSIC_Handle�Ɋi�[����
	bgm->MUSIC_Handle = LoadSoundMem(PLAY_MUSIC);

	//�}�N���Œ�`�������y�t�@�C�������[�h���A���ʔԍ���MUSIC_COLISION_Handle�Ɋi�[����
	bgm->MUSIC_COLISION_Handle = LoadSoundMem(COLISION_MUSIC);

	//�������[�v
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

		Keyboard_Update();  //�L�[�{�[�h�̍X�V

		fps->Update();		//FPS�̏���[�X�V]

		//���݂̎��Ԃ��擾
		Get_Time = GetNowCount();

		//�E�B���h�E�̃V�[�����
		switch (screen_state)
		{
		case GAME_TITLE:		//�Q�[���^�C�g�����

			bgm->PLAY_VOLUME_BGM();

			GAME_TITLE_DRAW();	//�^�C�g����ʂ�`��

			p->PLAYER_RESET();	//�v���C���[�������ʒu��

			//w->WEAPON_RESET();	//�E�G�|���������ʒu��
			for (int e_num = 0, w_cnt = 0; e_num < ENEMY_NUM, w_cnt < WEAPON_NUM; e_num++, w_cnt++)
			{
				e[e_num]->ENEMY_RESET();
				w[w_cnt]->WEAPON_RESET();	//�E�G�|���������ʒu��
			}

			s->SCORE_RESET();		//�X�R�A�̃��Z�b�g����֐�

			break;

		case GAME_PLAY:				//�Q�[���v���C���

			GAME_PLAY_DRAW();	//�v���C��ʂ�`��

			count++;
			//�E�G�|���ƃG�l�~�[�𕡐���������
			for (int w_cnt = 0, e_num = 0; e_num < ENEMY_NUM; w_cnt++, e_num++)
			{
				p->PLAYER_COLLISION_ENEMY(e[e_num]->ENEMY_X, e[e_num]->ENEMY_Y);		//�v���C���[�ƃG�l�~�[�̏Փ˔���
				w[w_cnt]->WEAPON_COLLISION_ENEMY(e[e_num]->ENEMY_X, e[e_num]->ENEMY_Y);	//�E�G�|���ƃG�l�~�[�̏Փ˔���

				e[e_num]->ENEMY_ANIMATION_COUNT++;
				e[e_num]->RANDOM_soeji = e[e_num]->ENEMY_RANDOM_soeji_Evacuation + (e[e_num]->ENEMY_ANIMATION_COUNT / ENEMY_ANIMATION_FRAME) % ENEMY_ANIMATION_PATTERN;

				//�����t���O��ture�̂Ƃ�
				if (e[e_num]->ENEMY_EXPROSION_flag == true)
				{
					if (ENEMY_HIT_TIME - (Get_Time - Get_Collision_Time) / 1000 <= PLAY_END_TIME)
					{
						e[e_num]->ENEMY_EXPROSION_flag = false;
					}
					//�G�l�~�[�̃A�j���[�V�����p�J�E���g
					e[e_num]->ENEMY_ANIMATION_COUNT++;
					//�����A�j���[�V����
					e[e_num]->ENEMY_ANIMATION_soeji = (e[e_num]->ENEMY_ANIMATION_COUNT / ENEMY_ANIMATION_EXPROSION_FRAME) % ENEMY_ANIMATION_EXPROSION_PATTERN;
					//�����A�j���[�V����
					e[e_num]->ENEMY_ANIMATION_DRAW((ENEMY_ANIMATION_Size_W / ENEMY_ANIMATION_BUNKATU_X / 2) - (ENEMY_Size_W / ENEMY_BUNKATU_X / 2), (ENEMY_ANIMATION_Size_H / ENEMY_ANIMATION_BUNKATU_Y / 2) - (ENEMY_Size_H / ENEMY_BUNKATU_Y / 2));
					
				}
				/*if (e[e_num]->ENEMY_COUNT >= 60)
				{
					e[e_num]->ENEMY_COUNT = 0;
				}*/
				e[e_num]->ENEMY_DRAW();		//�G�l�~�[�̕`�揈��
				//e[e_num]->ENEMY_ANIMATION_DRAW((ANIMATION_BUNKATU_SIZE_X / 2) - (ENEMY_BUNKATU_SIZE_X / 2), (ANIMATION_BUNKATU_SIZE_Y / 2) - (ENEMY_BUNKATU_SIZE_Y / 2));
				
				//���e�A�j���[�V�����p�J�E���g
				w[w_cnt]->WEAPON_ANIMATION_COUNT++;

				//���e�A�j���[�V��������
				w[w_cnt]->WEAPON_soeji = (w[w_cnt]->WEAPON_ANIMATION_COUNT / WEAPON_ANIMATION_EXPROSION_FRAME) % WEAPON_ANIMATION_PATTERN;

				//�E�G�|���̕`�揈��
				w[w_cnt]->WEAPON_DRAW((WEAPON_Size_W / WEAPON_BUNKATU_X / 2) - (PLAYER_Size_W / PLAYER_BUNKATU_X / 2), (WEAPON_Size_H / WEAPON_BUNKATU_Y / 2) - (PLAYER_Size_H / PLAYER_BUNKATU_Y / 2));
			}


			p->PLAYER_DRAW();	//�v���C���[�̕`�揈��


			//DrawFormatStringF(0,500, RGB(255, 255, 255), "ENEMY_X:%d", e[num]->ENEMY_X);

			//for (int num = 0; num < ENEMY_NUM; num++)
			//{
			//	p->PLAYER_COLLISION_ENEMY(e[num]->ENEMY_X, e[num]->ENEMY_Y);	//�v���C���[�ƃG�l�~�[�̏Փ˔���
			//	w->WEAPON_COLLISION_ENEMY(e[num]->ENEMY_X, e[num]->ENEMY_Y);
			//	
			//	e[num]->ENEMY_DRAW();		//�G�l�~�[�̕`�揈��
			//}
			/*DrawFormatStringF(0, 200, RGB(255, 255, 255), "ENEMY_X[1]:%d", e[0]->ENEMY_X);
			DrawFormatStringF(0, 350, RGB(255, 255, 255), "ENEMY_X[2]:%d", e[1]->ENEMY_X);
			DrawFormatStringF(0, 500, RGB(255, 255, 255), "ENEMY_X[3]:%d", e[2]->ENEMY_X);
			DrawFormatStringF(0, 400, RGB(255, 255, 255), "WEAPON_Y[w_cnt]:%d", w[2]->WEAPON_Y);*/
			//w->WEAPON_DRAW();

			//�g�[�^���X�R�A��`��
			s->DRAW_TOTAL_SCORE();

			//�������Ԃ̐ݒ�
			DrawFormatStringToHandle(400, 0, GetColor(150, 255, 255), FontHandle_LIMIT, "LIMIT_TIME�F%0.3lf�b", (LIMIT_TIME - (Get_Time - GAME_TITLE_ELAPSEDTIME) / 1000));	//�����̑傫���ύX);

			//DrawFormatStringToHandle(100, 0, GetColor(150, 255, 255), FontHandle_LIMIT, "LIMIT_TIME�F%d�b", (Get_Time - GAME_TITLE_ELAPSEDTIME) / 1000);	//�����̑傫���ύX);

			//�N���A�����̕ύX
			DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, ClearCondition_Level->TimeMode_Play_flag, false);

			break;

		case GAME_CLEAR:		//�Q�[���N���A���
			GAME_CLEAR_DRAW();
			s->DRAW_TOTAL_SCORE();	//�g�[�^���X�R�A��`��
			break;
		
		case GAME_END:			//�Q�[���G���h���
			GAME_END_DRAW();	//�G���h��ʂ�`��
			s->DRAW_TOTAL_SCORE();	//�g�[�^���X�R�A��`��
			break;

		default:
			break;
		}
		fps->Draw(0, 50);	//FPS�̏���[�`��]

		ScreenFlip();		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		fps->Wait();		//FPS�̏���[�҂�]
		
	}

	delete fps;		//fps�N���X�̉��
	delete p;		//PLAYER�N���X�̉��
	delete s;		//�X�R�A�N���X�̉��
	delete Difficulty_Level;		//��Փx�ύX�N���X�̉��
	delete ClearCondition_Level;	//�N���X�����ύX�N���X�̉��
	delete Background;				//�X�N���[������w�i�摜�N���X�̉��
	for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
	{
		delete w[w_cnt];		//WEAPON�N���X�̉��
	}
	for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
	{
		delete e[e_num];		//ENEMY�N���X�̉��
	}
	DxLib_End();				//�c�w���C�u�����g�p�̏I������

	return 0;					// �\�t�g�̏I�� 
}

//�^�C�g����ʂ�`�悷��֐�
void GAME_TITLE_DRAW() 
{
	//�^�C�g���摜�̔w�i�摜��`�悷��
	//DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, imgBack_Title, false);

	//�X�N���[������w�i�摜��`�悷��֐�
	Background->Background_Scroll_Draw();
	
	//�w�i���X�N���[������֐�
	Background->Background_Scroll();

	//�^�C�g�����S�̉摜��`�悷��
	DrawExtendGraph(GAME_TITLE_LOG_UPPERLEFT_X, GAME_TITLE_LOG_UPPERLEFT_Y, GAME_TITLE_LOG_BOTTOMLEFT_X, GAME_TITLE_LOG_BOTTOMLEFT_Y, imgTitle_log, true);

	//�G���^�[��ʂ֑J�ڂ��������`��
	DrawStringToHandle(0, 0, "�^�C�g���@�G���^�[�Ńv���C��ʂ�", RGB(255, 255, 255), FontHandle_ScreenTransition);

	//��Փx�ύX��`�悷��֐�
	Difficulty_Level->DIFFICULTY_LEVEL_SELECT_DRAW();

	//�N���A�����ύX��`�悷��֐�
	ClearCondition_Level->CLEAR_CONDITION_SELECT_DRAW();

	//�^�C�g����ʂŃN���A������ύX���A�l��ێ�����֐�
	ClearCondition_Level->CLEAR_CONDITION_SELECT_TITLE();

	//�^�C�g����ʂ�Easy,Normal,Hard��ύX�����l����ɓ�Փx�ύX�����{����֐�
	ClearCondition_Level->CLEAR_CONDITION_SELECT_PLAY();

	//�^�C�g����ʂ�Easy,Normal,Hard��ύX���A�l��ێ�����֐�
	Difficulty_Level->DIFFICULTY_LEVEL_TITLE();	

	//�^�C�g����ʂ�Easy,Normal,Hard��ύX�����l����ɓ�Փx�ύX�����{����֐�
	Difficulty_Level->DIFFICULTY_LEVEL_PLAY();	

	//�v���C��ʂŉ��y��炷�֐�
	bgm->PLAY_BGM();

	//�G���^�[�L�[�������ꂽ��
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1)
	{
		//�v���C��ʂ֑J�ڂ���
		screen_state = GAME_PLAY;

		//�v���C��ʂ֑J�ڂ���Ƃ��A�^�C�g����ʂł����������Ԃ�ϐ��ɓ����
		GAME_TITLE_ELAPSEDTIME = Get_Time;
	}	
}

//�v���C��ʂ�`�悷��֐�
void GAME_PLAY_DRAW()
{
	//�X�N���[������w�i�摜��`�悷��֐�
	Background->Background_Scroll_Draw();

	//�w�i���X�N���[������֐�
	Background->Background_Scroll();

	//�G���h��ʂ֑J�ڂ��������`��
	//DrawStringToHandle(0, 0, "�v���C �X�y�[�X�ŃG���h��ʂ�", RGB(255, 255, 255), FontHandle_ScreenTransition);

	//�v���C���[��HP��`�悷��֐�
	p->PLAYER_HP_DRAW();

	//�������Ԃ�0�b�ɂȂ�����(�X�R�A���[�h�̂Ƃ�)
	if (LIMIT_TIME - (Get_Time - GAME_TITLE_ELAPSEDTIME) / 1000 <= PLAY_END_TIME && ClearCondition_Level->ScoreMode_Play_flag == true)
	{
		screen_state = GAME_END;	//�G���h��ʂ֑J�ڂ���
	}

	//�������Ԃ�0�b�ɂȂ�����(�^�C�����[�h�̂Ƃ�)
	if (LIMIT_TIME - (Get_Time - GAME_TITLE_ELAPSEDTIME) / 1000 <= PLAY_END_TIME && ClearCondition_Level->TimeMode_Play_flag == true)
	{
		screen_state = GAME_CLEAR;	//�N���A��ʂ֑J�ڂ���
	}

	//�X�y�[�X�L�[�������ꂽ��
	if (Keyboard_Get(KEY_INPUT_SPACE) == 1)
	{
		screen_state = GAME_END;		//�G���h��ʂ֑J�ڂ���
	}

	//�g�[�^���X�R�A
	if (s->total_score >= GAME_CLEAR_SCORE)
	{
		screen_state = GAME_CLEAR;		//�G���h��ʂ֑J�ڂ���
	}
}

//�N���A��ʂ�`�悷��֐�
void GAME_CLEAR_DRAW() 
{
	//�N���A��ʗp�̔w�i��`��
	DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, imgBack_Clear, false);

	DrawStringToHandle(0, 0, "�N���A�@�o�b�N�X�y�[�X�Ń^�C�g����ʂ�", RGB(0, 0, 255), FontHandle_ScreenTransition);

	//�o�b�N�X�y�[�X�L�[�������ꂽ��
	if (Keyboard_Get(KEY_INPUT_BACK) == 1)
	{
		screen_state = GAME_TITLE;		//�^�C�g����ʂ֑J�ڂ���
	}

	DrawStringToHandle(0, 550, "�N���A�@�G�X�P�[�v�L�[�ŃQ�[���I��", RGB(0, 255, 255), FontHandle_ScreenTransition);

	//�G�X�P�[�v�L�[�������ꂽ��
	if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1)
	{
		DxLib_End();					//�Q�[���I��
	}

	//�l�������X�R�A��`�悷��֐�
	s->DRAW_TOTAL_SCORE();
}

//�G���h��ʂ�`�悷��֐�
void GAME_END_DRAW()
{

	//�G���h��ʂ̔w�i�摜��`�悷��
	DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, imgBack_End, false);

	DrawStringToHandle(0, 0, "�G���h�@�o�b�N�X�y�[�X�Ń^�C�g����ʂ�", RGB(0, 0, 255), FontHandle_ScreenTransition);

	//�o�b�N�X�y�[�X�L�[�������ꂽ��
	if (Keyboard_Get(KEY_INPUT_BACK) == 1)
	{
		screen_state = GAME_TITLE;		//�^�C�g����ʂ֑J�ڂ���
	}

	DrawStringToHandle(0, 550, "�G���h�@�G�X�P�[�v�L�[�ŃQ�[���I��", RGB(0, 255, 255), FontHandle_ScreenTransition);

	//�G�X�P�[�v�L�[�������ꂽ��
	if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1)
	{
		DxLib_End();					//�Q�[���I��
	}

	//�l�������X�R�A��`�悷��֐�
	s->DRAW_TOTAL_SCORE();
}

//�v���C���[�ƃG�l�~�[�̏Փ˔���
void PLAYER::PLAYER_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y)
{
	//�G�l�~�[�̐��ɉ����ČJ��Ԃ�
	for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
	{
		//�L�����ƃG�l�~�[�̓����蔻��
		if (((PLAYER_X > e[e_num]->ENEMY_X && PLAYER_X < e[e_num]->ENEMY_X + ENEMY_Size_W / ENEMY_BUNKATU_X) ||
			(e[e_num]->ENEMY_X > PLAYER_X && e[e_num]->ENEMY_X < PLAYER_X + PLAYER_Size_W / PLAYER_BUNKATU_X)) &&
			((PLAYER_Y > e[e_num]->ENEMY_Y && PLAYER_Y < e[e_num]->ENEMY_Y + ENEMY_Size_H / ENEMY_BUNKATU_Y) ||
			(e[e_num]->ENEMY_Y > PLAYER_Y &&  e[e_num]->ENEMY_Y < PLAYER_Y + PLAYER_Size_H / PLAYER_BUNKATU_Y)))
		{
			//�v���C���[�ɐG�ꂽ�G�l�~�[�̈ʒu��摜�̓Y���������Z�b�g����
			e[e_num]->ENEMY_RESET();
			
			//�G�l�~�[�ɐG�ꂽ��v���C���[�̗̑͂�����炷
			p->PLAYER_HP -= 1;
		}
	}

	//DrawFormatString(0, 50, RGB(255, 255, 255), "PLAYER�F%d", p->PLAYER_HP);	//�v���C���[�̗̑͂�`�悷��

	//�v���C���[�̗̑͂�0�ȉ��Ȃ�
	if (p->PLAYER_HP <= 0)
	{
		for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
		{
			//�v���C���[�ɐG�ꂽ�G�l�~�[�̈ʒu��摜�̓Y���������Z�b�g����
			e[e_num]->ENEMY_RESET();
		}
		screen_state = GAME_END;		//�G���h��ʂ֑J�ڂ���
	}
}

//�E�G�|����X�ʒu���擾
int WEAPON::Get_WEAPON_X()
{
	//A�L�[���������Ƃ�
	if (Keyboard_Get(KEY_INPUT_A) >= 1)
	{
		for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
		{
			w[w_cnt]->WEAPON_flag_X = true;		//A	�L�[���������Ƃ��A�E�G�|����X�t���O��true�ɂ��� (�E�G�|����X���W���v���C���[��X���W�Ɠ����ɂ���)
		}
	}

	
	for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
	{
		if (w[w_cnt]->WEAPON_flag_X == false)
		{
			w[w_cnt]->WEAPON_X = p->PLAYER_X;		//�E�G�|����X�t���O��false�̂Ƃ��A�E�G�|����X���W���v���C���[��X���W�Ɠ����ɂ���
		}
	}

	return WEAPON_X;
}

//�E�G�|����Y�ʒu���擾����֐�
int WEAPON::Get_WEAPON_Y()
{
		//WEAPON_Y = Get_PLAYER_Y() - WEAPON_Size_H / WEAPON_BUNKATU_Y;
	
		//A �L�[���������Ƃ��A������Y���W�����Z���邽�߂̃t���O
	
		
	//�E�G�|���𑀍삷��@A�@�L�[���������ꍇ
	if (Keyboard_Get(KEY_INPUT_A) >= 1 && count % 30 == 0) //)
	{
		for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
		{
			//if (w[w_cnt]->WEAPON_flag_Y == false)
			//{
				//if (0.5 - (Get_Time - Get_WEAPON_Time) / 1000 == PLAY_END_TIME)
				//{ 
					w[w_cnt]->WEAPON_flag_X = true;		//A	�L�[���������Ƃ��A�v���C���[��X���W���擾���邽�߂̃t���O
					w[w_cnt]->WEAPON_flag_Y = true;		//A �L�[���������Ƃ��A������Y���W�����Z���邽�߂̃t���O
					/*w[w_cnt]->WEAPON_X = p->PLAYER_X;
					w[w_cnt]->WEAPON_Y = p->PLAYER_Y;*/

					//w[w_cnt]->WEAPON_Next_flag = true;
					//Get_WEAPON_Time = Get_Time;
				//}
			//}
		}
	}

	//A �L�[���������Ƃ��A������Y���W�����Z���邽�߂̃t���O
	//if (w[0]->WEAPON_flag_Y == true)
	//{
	//	WEAPON_Y -= 5;//w[0]->Get_WEAPON_Speed(WEAPON_Speed);
	//}

	/*if (w[1]->WEAPON_flag_Y == true)
	{
		w[1]->WEAPON_Y -= w[1]->Get_WEAPON_Speed(WEAPON_Speed);
	}

	if (w[2]->WEAPON_flag_Y == true)
	{
		w[2]->WEAPON_Y -= w[2]->Get_WEAPON_Speed(WEAPON_Speed);
	}*/


	for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
	{
		if (w[w_cnt]->WEAPON_flag_Y == false)
		{
			w[w_cnt]->WEAPON_Y = p->PLAYER_Y;		//�E�G�|����Y�t���O��false�̂Ƃ��A�E�G�|����Y���W���v���C���[��Y���W�Ɠ����ɂ���
		}
		
		//A �L�[���������Ƃ��A������Y���W�����Z���邽�߂̃t���O
		if (w[w_cnt]->WEAPON_flag_Y == true)
		{
			WEAPON_Y -= w[w_cnt]->Get_WEAPON_Speed(WEAPON_Speed);
		}
		
		if (w[w_cnt]->WEAPON_flag_X == true && w[w_cnt]->WEAPON_Y == p->PLAYER_Y)// - (WEAPON_Size_H / WEAPON_BUNKATU_Y))
		{
			//�E�G�|����X���W���v���C���[��X���W�Ɠ����l�ɂ���
			w[w_cnt]->WEAPON_X = p->PLAYER_X;

			///�E�G�|����X�t���O��false�ɕύX����
			w[w_cnt]->WEAPON_flag_X = false;
		}

		//�E�G�|���摜��Y���W����ʊO(0�����Ⴂ�l)�ɓ��B�����Ƃ� //�`�揈���ł��炵��Y���W�𒲐�
		if (w[w_cnt]->WEAPON_Y + (PLAYER_Size_H / PLAYER_BUNKATU_Y / 2) < GAME_MIN_HEIGHT)
		{
			//�E�G�|����Y���W���v���C���[��Y���W����A�E�G�|���摜�T�C�Y���番�����A�������l�ɂ���
			//(�E�G�|���̉摜���v���C���[�̓���ɔz�u���邽��)
			if (w[w_cnt]->WEAPON_flag_Y == true)
			{
				//w[w_cnt]->WEAPON_Y = p->PLAYER_Y - (WEAPON_Size_H / WEAPON_BUNKATU_Y);
				w[w_cnt]->WEAPON_Y = p->PLAYER_Y;
				w[w_cnt]->WEAPON_X = p->PLAYER_X;

				//�E�G�|����Y�t���O��false�ɕύX����
				w[w_cnt]->WEAPON_flag_Y = false;
				//w[w_cnt]->WEAPON_Next_flag = false;
			}

		}
	}


			//�E�G�|����Y�t���O��(A�L�[��������)true���A�E�G�|����Y���W��(0�ȏ�)��ʓ��Ȃ�
			
			/*else
			{
				w[w_cnt]->WEAPON_Next_flag = false;
			}*/

	
	//for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
	//{
	//	////�`�揈���ł��炵��Y���W�𒲐�
	//	//if (w[w_cnt]->WEAPON_flag_Y == true && w[w_cnt]->WEAPON_Y + (PLAYER_Size_H / PLAYER_BUNKATU_Y / 2) >= GAME_MIN_HEIGHT) //&& w[w_cnt]->WEAPON_Next_flag == true)
	//	//{
	//	//	//window�̍��[�܂ňړ�����
	//	//	w[w_cnt]->WEAPON_Y -= w[w_cnt]->Get_WEAPON_Speed(WEAPON_Speed);
	//	//}
	//}
		
	return WEAPON_Y;
}


//�E�G�|���ƃG�l�~�[�̏Փ˔���
void WEAPON::WEAPON_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y)
{
		for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
		{
			for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
			{
				//�L�����ƃG�l�~�[�̓����蔻��
				if (((w[w_cnt]->WEAPON_X > e[e_num]->ENEMY_X && w[w_cnt]->WEAPON_X < e[e_num]->ENEMY_X + ENEMY_Size_W / ENEMY_BUNKATU_X) ||
					(e[e_num]->ENEMY_X > w[w_cnt]->WEAPON_X && e[e_num]->ENEMY_X < w[w_cnt]->WEAPON_X + WEAPON_Size_W / WEAPON_BUNKATU_X)) &&
					((w[w_cnt]->WEAPON_Y > e[e_num]->ENEMY_Y && w[w_cnt]->WEAPON_Y < e[e_num]->ENEMY_Y + ENEMY_Size_H / ENEMY_BUNKATU_Y) ||
					(e[e_num]->ENEMY_Y > w[w_cnt]->WEAPON_Y && e[e_num]->ENEMY_Y < w[w_cnt]->WEAPON_Y + WEAPON_Size_H / WEAPON_BUNKATU_Y)))
				{
					//PlaySoundMem(bgm->MUSIC_COLISION_Handle, DX_PLAYTYPE_BACK);
					//�E�G�|���ɐG�ꂽ�G�l�~�[�̈ʒu��摜�̓Y���������Z�b�g����

					//�v���C��ʂœG�ƃE�G�|�����Փ˂����Ƃ��̉��y��炷�֐�
					bgm->PLAY_COLISION_BGM();

					e[e_num]->ENEMY_RESET();

					w[w_cnt]->WEAPON_flag_X = false;		//A	�L�[���������Ƃ��A�v���C���[��X���W���擾���邽�߂̃t���O
					w[w_cnt]->WEAPON_flag_Y = false;		//A �L�[���������Ƃ��A������Y���W�����Z���邽�߂̃t���O

					e[e_num]->ENEMY_EXPROSION_flag = true;
					
					Get_Collision_Time = Get_Time;
					
					//�E�G�|����Y���W���v���C���[��Y���W����A�E�G�|���摜�T�C�Y���番�����A�������l�ɂ���
					//(�E�G�|���̉摜���v���C���[�̓���ɔz�u���邽��)
					//w[w_cnt]->WEAPON_Y = p->Get_PLAYER_Y() - (WEAPON_Size_H / WEAPON_BUNKATU_Y);
					w[w_cnt]->WEAPON_Y = p->Get_PLAYER_Y();

					s->TOTAL_SCORE();		//�l�������X�R�A��ێ����A�v�Z����֐�
				}
			}
		}

	//DrawFormatString(0, 50, RGB(255, 255, 255), "PLAYER�F%d", PLAYER_HP);

	////�v���C���[�̗̑͂�0�ȉ��Ȃ�
	//if (PLAYER_HP <= 0)
	//{
	//	for (int num = 0; num < ENEMY_NUM; num++)
	//	{
	//		//�v���C���[�ɐG�ꂽ�G�l�~�[�̈ʒu��摜�̓Y���������Z�b�g����
	//		e[num]->ENEMY_RESET();
	//	}
	//	screen_state = GAME_END;		//�G���h��ʂ֑J�ڂ���
	//}
}



//�G�l�~�[��Y�ʒu���擾����֐�
int ENEMY::Get_ENEMY_Y()
{
	/*if (fps->flameCount <= 10)
	{
		ENEMY_flag = true;
	}*/
	//if (ENEMY_flag == true)
	//{
		ENEMY_Y += Get_ENEMY_Speed();
	//}
	for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
	{
		if (e[e_num]->ENEMY_Y > GAME_HEIGHT)
		{
			e[e_num]->ENEMY_RESET();
			//ENEMY_flag = false;
		}
	}

	return ENEMY_Y;
}


//�^�C�g����ʂœ�Փx��ύX������A�e��Փx�ɉ����Ďc�@��G�l�~�[�̐��𒲐�����֐�
void DIFFICULTY::DIFFICULTY_LEVEL_PLAY()
{
	//Easy�@�c�@3
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1 && Lv_Select == Lv_Select_MIN)
	{
		p->PLAYER_HP = 3;			//�v���C���[�̎c�@��ύX
		screen_state = GAME_PLAY;	//�V�[�����Q�[����ʂɕύX
	}

	//Normal�@�c�@2
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1 && Lv_Select == Lv_Select_NORMAL)
	{
		p->PLAYER_HP = 2;			//�v���C���[�̎c�@��ύX
		screen_state = GAME_PLAY;	//�V�[�����Q�[����ʂɕύX
	}

	//Hard�@�c�@1
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1 && Lv_Select == Lv_Select_MAX)
	{
		p->PLAYER_HP = 1;			//�v���C���[�̎c�@��ύX
		screen_state = GAME_PLAY;	//�V�[�����Q�[����ʂɕύX
	}
}

//�N���A������ύX(�^�C�������X�R�A����)����֐�
void CLEARCONDITION::CLEAR_CONDITION_SELECT_PLAY()
{
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1 && ClearCondition_Select == ClearCondition_Select_TIME)
	{
		TimeMode_Play_flag = true;		//�^�C�����t���O:ON
		ScoreMode_Play_flag = false;	//�X�R�A���t���O:OFF
		screen_state = GAME_PLAY;		//�V�[�����Q�[����ʂɕύX
	}

	if (Keyboard_Get(KEY_INPUT_RETURN) == 1 && ClearCondition_Select == ClearCondition_Select_SCORE)
	{
		TimeMode_Play_flag = false;		//�^�C�����t���O:OFF
		ScoreMode_Play_flag = true;		//�X�R�A���t���O:ON
		screen_state = GAME_PLAY;		//�V�[�����Q�[����ʂɕύX
	}
}

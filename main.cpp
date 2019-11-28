#include "DxLib.h"
#include "Keyboard_Get.h"
#include "PLAYER.h"
#include "ENEMY.h"
#include "FPS.h"


#define GAME_BackImage_TITLE	"BackImage\\kaidou0331_800b.jpg"	//�^�C�g����ʔw�i�摜
#define GAME_TITLE_LOG			"BackImage\\game_title_font.png"	//�^�C�g�����S
#define GAME_BackImage_PLAY		"BackImage\\pipo-battlebg001b.jpg"	//�v���C��ʔw�i�摜
#define GAME_BackImage_END		"BackImage\\end_2.jpg"	//�G���h��ʔw�i�摜

#define GAME_FPS_SPEED					   60

#define GAME_TITLE_LOG_UPPERLEFT_X		GAME_WIDTH / 4		//�^�C�g�����S�摜�̍���X���W
#define GAME_TITLE_LOG_UPPERLEFT_Y		GAME_HEIGHT / 3		//�^�C�g�����S�摜�̍���Y���W
#define GAME_TITLE_LOG_BOTTOMLEFT_X		GAME_WIDTH - GAME_WIDTH / 4		//�^�C�g�����S�摜�̉E��X���W
#define GAME_TITLE_LOG_BOTTOMLEFT_Y		GAME_HEIGHT - GAME_HEIGHT / 3	//�^�C�g�����S�摜�̉E��Y���W

//�e��ʂ�ݒ�
enum GAME_SCREEN 
{
	GAME_TITLE,	//�^�C�g�����
	GAME_PLAY,	//�v���C���
	GAME_END	//�G���h���
};

//�Q�[����ʂ̑J�ڂ��Ǘ�����
GAME_SCREEN screen_state = GAME_TITLE;	//��ʑJ�ڂ��R���g���[������(�ŏ��̉�ʂ̓^�C�g�����)

//�v���g�^�C�v�錾
void GAME_TITLE_DRAW();	//�^�C�g����ʂ�`��
void GAME_PLAY_DRAW();	//�v���C��ʂ�`��
void GAME_END_DRAW();	//�G���h��ʂ�`��



FPS *fps = new FPS(GAME_FPS_SPEED);		//FPS�N���X�̃I�u�W�F�N�g�𐶐�
PLAYER *p = new PLAYER();				//�v���C���[�̃I�u�W�F�N�g�𐶐�����
ENEMY *e[3];							//�G�l�~�[�N���X���R��������




// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɐݒ�(TRUE: FALSE:�t���X�N���[��)
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������
	

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);	//�`��𗠉�ʂɐݒ�
	

	PLAYER_Size = LoadGraph(GAME_PLAYER);			//�L�����摜�@�̏c�Ɖ��̃T�C�Y���擾���邽�߃��[�h����(�����Ɏ̂Ă�)

	GetGraphSize(PLAYER_Size, &PLAYER_Size_W, &PLAYER_Size_H);	//�L�����摜�̏c�Ɖ��̃T�C�Y���擾

	DeleteGraph(PLAYER_Size);//�L�����摜�@�̏c�Ɖ��̃T�C�Y���擾������A�g���̂�

	LoadDivGraph(GAME_PLAYER, PLAYER_BUNKATU, PLAYER_BUNKATU_X, PLAYER_BUNKATU_Y, PLAYER_Size_W / PLAYER_BUNKATU_X, PLAYER_Size_H / PLAYER_BUNKATU_Y, &p->PLAYER_Handle[0]);
	


	ENEMY_Size = LoadGraph(GAME_ENEMY);			//�L�����摜�@�̏c�Ɖ��̃T�C�Y���擾���邽�߃��[�h����(�����Ɏ̂Ă�)

	GetGraphSize(ENEMY_Size, &ENEMY_Size_W, &ENEMY_Size_H);	//�L�����摜�̏c�Ɖ��̃T�C�Y���擾

	DeleteGraph(ENEMY_Size);//�L�����摜�@�̏c�Ɖ��̃T�C�Y���擾������A�g���̂�

	for (int num = 0; num < 3; num++)
	{
		e[num] = new ENEMY();
		LoadDivGraph(GAME_ENEMY, ENEMY_BUNKATU, ENEMY_BUNKATU_X, ENEMY_BUNKATU_Y, ENEMY_Size_W / ENEMY_BUNKATU_X, ENEMY_Size_H / ENEMY_BUNKATU_Y, &e[num]->ENEMY_Handle[0]);
	}

	//�^�C�g����ʂ̔w�i�̉摜��ǂݍ���
	int imgBack_Title = LoadGraph(GAME_BackImage_TITLE);		//�^�C�g���w�i�摜��ǂݍ���(*���ӁFwhile���œǂݍ��ނ�FPS���ቺ����[����ǂݍ���ł��܂�����])
	//�^�C�g�����S�̉摜��ǂݍ���
	int imgTitle_log = LoadGraph(GAME_TITLE_LOG);				//�^�C�g�����S�摜��ǂݍ���(*���ӁFwhile���œǂݍ��ނ�FPS���ቺ����[����ǂݍ���ł��܂�����])
	
	//�v���C��ʂ̔w�i�摜��ǂݍ���
	int imgBack_Play = LoadGraph(GAME_BackImage_PLAY);

	//�G���h��ʂ̔w�i�摜��ǂݍ���
	int	imgBack_End = LoadGraph(GAME_BackImage_END);
	
	


	while (TRUE)	//�������[�v
	{
		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��
		Keyboard_Update();   //�L�[�{�[�h�̍X�V

		fps->Update();		//FPS�̏���[�X�V]

		switch (screen_state)
		{
		case GAME_TITLE:
			
			//�w�i�̉摜��`�悷��
			DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, imgBack_Title, false);
			//�^�C�g�����S�̉摜��`�悷��
			DrawExtendGraph(GAME_TITLE_LOG_UPPERLEFT_X, GAME_TITLE_LOG_UPPERLEFT_Y, GAME_TITLE_LOG_BOTTOMLEFT_X, GAME_TITLE_LOG_BOTTOMLEFT_Y, imgTitle_log, true);
			
			GAME_TITLE_DRAW();	//�^�C�g����ʂ�`��

			p->PLAYER_RESET();	//�v���C���[�������ʒu��
	
			break;

		case GAME_PLAY:

			DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, imgBack_Play, false);
			GAME_PLAY_DRAW();	//�v���C��ʂ�`��
			p->PLAYER_DRAW();	//�v���C���[�̕`�揈��

			for (int num = 0; num < 3; num++)
			{
				p->PLAYER_COLLISION_ENEMY(e[num]->ENEMY_X, e[num]->ENEMY_Y);	//�v���C���[�ƃG�l�~�[�̏Փ˔���

				e[num]->ENEMY_DRAW();	//�G�l�~�[�̕`�揈��
			}
			
			
			break;

		case GAME_END:
			DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, imgBack_End, false);
			GAME_END_DRAW();	//�G���h��ʂ�`��
			break;

		default:
			break;
		}
		fps->Draw(0, 220);	//FPS�̏���[�`��]

		ScreenFlip();		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		fps->Wait();		//FPS�̏���[�҂�]
		
	}

	delete fps;
	delete p;

	for (int num = 0; num < 3; num++)
	{
		delete e[num];
	}
	DxLib_End();			//�c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

//�^�C�g����ʂ�`�悷��֐�
void GAME_TITLE_DRAW() 
{
	DrawString(0, 0, "�^�C�g���@�G���^�[�Ńv���C��ʂ�", RGB(255, 255, 255));

	//�G���^�[�L�[�������ꂽ��
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1)
	{
		screen_state = GAME_PLAY;		//�v���C��ʂ֑J�ڂ���
	}	
}

//�v���C��ʂ�`�悷��֐�
void GAME_PLAY_DRAW()
{
	DrawString(0, 0, "�v���C �X�y�[�X�ŃG���h��ʂ�", RGB(255, 255, 255));

	
	if (Keyboard_Get(KEY_INPUT_SPACE) == 1)
	{
		screen_state = GAME_END;		//�G���h��ʂ֑J�ڂ���
	}
}

//�G���h��ʂ�`�悷��֐�
void GAME_END_DRAW()
{
	DrawString(0, 0, "�G���h�@�o�b�N�X�y�[�X�Ń^�C�g����ʂ�", RGB(255, 255, 255));


	//�o�b�N�X�y�[�X�L�[�������ꂽ��
	if (Keyboard_Get(KEY_INPUT_BACK) == 1)
	{
		screen_state = GAME_TITLE;		//�^�C�g����ʂ֑J�ڂ���
	}

	DrawString(0, 50, "�G���h�@�G�X�P�[�v�L�[�ŃQ�[���I��", RGB(255, 255, 255));

	//�G�X�P�[�v�L�[�������ꂽ��
	if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1)
	{
		DxLib_End();					//�Q�[���I��
	}
}

//�v���C���[�ƃG�l�~�[�̏Փ˔���
void PLAYER::PLAYER_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y)
{
	//�L�����ƃG�l�~�[�̓����蔻��
	if (((PLAYER_X > ENEMY_X && PLAYER_X < ENEMY_X + ENEMY_Size_W / ENEMY_BUNKATU_X) ||
		(ENEMY_X > PLAYER_X && ENEMY_X < PLAYER_X + PLAYER_Size_W / PLAYER_BUNKATU_X)) &&
		((PLAYER_Y > ENEMY_Y && PLAYER_Y < ENEMY_Y + ENEMY_Size_H / ENEMY_BUNKATU_Y) ||
		(ENEMY_Y > PLAYER_Y && ENEMY_Y < PLAYER_Y + PLAYER_Size_H / PLAYER_BUNKATU_Y)))
	{
		for (int num = 0; num < 3; num++)
		{
			e[num]->ENEMY_RESET();
		}
		PLAYER_HP -=1;
		//screen_state = GAME_END;		//�G���h��ʂ֑J�ڂ���
	}

	DrawFormatString(0, 50, RGB(255, 255, 255), "PLAYER�F%d", PLAYER_HP);

	if (PLAYER_HP <= 0)
	{
		for (int num = 0; num < 3; num++)
		{
			e[num]->ENEMY_RESET();
		}
		screen_state = GAME_END;		//�G���h��ʂ֑J�ڂ���
	}
}

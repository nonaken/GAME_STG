#pragma once

#define Lv_Select_MIN 0			//��Փx�ύX�̍ŏ��l(EASY)
#define Lv_Select_NORMAL 1		//��Փx�ύX�̒l(�P�FNormal)
#define Lv_Select_MAX 2			//��Փx�ύX�̍ő�l(HARD)

#define ClearCondition_Select_TIME  0 	//�N���A�������^�C�����̂Ƃ��̒l(�O�F�^�C����)
#define ClearCondition_Select_SCORE 1	//�N���A�������X�R�A���̂Ƃ��̒l(�P�F�X�R�A��)


#define GAME_CLEAR_SCORE 2000		//�Q�[���N���A�ɕK�v�ȃX�R�A

//��Փx�ύX�p�N���X
class DIFFICULTY
{
public:
	//int Lv;			//��Փx�ύX�̃��x����`�悷�邽�߂̕ϐ�

	//�������񎟌��z��Ŋi�[���ALv_Select�̒l�œ�Փx�ύX������
	char Difficuty_Array[3][64] = { "Easy\n(�c�@:3)","Normal\n(�c�@:2)","Hard\n(�c�@:1)" };
	
	int Lv_Select = 0;		//��Փx�ύX�̃��x����ێ�����֐�(Easy�F0, Normal�F2, Hard�F3)
	int FontHandle_LV_SELECT = 0;		//��Փx�ύX�̃t�H���g�n���h���p�ϐ�

	void DIFFICULTY_LEVEL_SELECT_DRAW();//��Փx�ύX��`�悷��֐�
	void DIFFICULTY_LEVEL_TITLE();		//�v���C��ʂ�Easy,Normal,Hard�ɕύX���A�l��ێ�����֐�
	void DIFFICULTY_LEVEL_PLAY();		//�v���C��ʂ�Easy,Normal,Hard��ύX�����l����ɓ�Փx�ύX�����{����֐�
};

//�N���A�����ύX�p�N���X
class CLEARCONDITION
{
public:
	char ClearCondition_Array[2][32] = { "�^�C����[�����؂�]" , "�X�R�A��[2000�ȏ�]"};
 
	int FontHandle_ClearCondition_SELECT = 0;//�N���A�����ύX�̃t�H���g�n���h���p�ϐ�
	void CLEAR_CONDITION_SELECT_DRAW();	//�N���A�����ύX��`�悷��֐�

	//char ClearCondition[50];			//�N���A�����ύX�̃��x����`�悷�邽�߂̔z��
	int ClearCondition_Select = 0;		//�N���A�����ύX�̃��x����ێ�����֐�(TimeMode�F0, ScoreMode�F1)
	bool TimeMode_Play_flag = false;	//�N���A�������^�C�����[�h���ǂ����m�F���邽�߂̃t���O
	bool ScoreMode_Play_flag = false;	//�N���A�������X�R�A���[�h���ǂ����m�F���邽�߂̃t���O
	

	void CLEAR_CONDITION_SELECT_TITLE();	//�v���C��ʂŃ^�C�����[�h���A�X�R�A���[�h�ɕύX���A�l��ێ�����֐�
	void CLEAR_CONDITION_SELECT_PLAY();		//�v���C��ʂŃ^�C�����[�h���A�X�R�A���[�h�ɕύX�����l����ɃN���A�����ύX�����{����֐�
	void CLEAR_CONDITION_SELECT_PLAYMODE_DRAW();		//�v���C��ʂŃ^�C�����[�h���X�R�A���[�h���c���ł���悤�ɂǂ���̃��[�h���`�悷��
};
#pragma once

//��Փx�ύX�p�N���X
class DIFFICULTY
{
public:
	char Lv[25];			//��Փx�ύX�̃��x����`�悷�邽�߂̔z��
	int Lv_Select = 0;		//��Փx�ύX�̃��x����ێ�����֐�(Easy�F0, Normal�F2, Hard�F3)
	
	void DIFFICULTY_LEVEL_TITLE();		//�v���C��ʂ�Easy,Normal,Hard�ɕύX���A�l��ێ�����֐�
	void DIFFICULTY_LEVEL_PLAY();		//�v���C��ʂ�Easy,Normal,Hard��ύX�����l����ɓ�Փx�ύX�����{����֐�
};

//�N���A�����ύX�p�N���X
class CLEARCONDITION
{
public:
	char ClearCondition[50];			//�N���A�����ύX�̃��x����`�悷�邽�߂̔z��
	int ClearCondition_Select = 0;		//�N���A�����ύX�̃��x����ێ�����֐�(TimeMode�F0, ScoreMode�F1)
	bool TimeMode_Play_flag = false;	//�N���A�������^�C�����[�h���ǂ����m�F���邽�߂̃t���O
	bool ScoreMode_Play_flag = false;	//�N���A�������X�R�A���[�h���ǂ����m�F���邽�߂̃t���O
	

	void CLEAR_CONDITION_SELECT_TITLE();	//�v���C��ʂŃ^�C�����[�h���A�X�R�A���[�h�ɕύX���A�l��ێ�����֐�
	void CLEAR_CONDITION_SELECT_PLAY();		//�v���C��ʂŃ^�C�����[�h���A�X�R�A���[�h�ɕύX�����l����ɃN���A�����ύX�����{����֐�
};
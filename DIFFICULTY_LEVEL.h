#pragma once

//��Փx�ύX�p�N���X
class DIFFICULTY
{
public:
	char Lv[25];			//��Փx�ύX�̃��x����`�悷�邽�߂̔z��
	int Lv_Select = 0;		//��Փx�ύX�̃��x����ێ�����֐�(Easy�F0, Normal�F2, Hard�F3)
	
	void DIFFICULTY_LEVEL_TITLE();		//�v���C��ʂ�Easy,Normal,Hard��ύX���A�l��ێ�����֐�
	void DIFFICULTY_LEVEL_PLAY();		//�v���C��ʂ�Easy,Normal,Hard��ύX�����l����ɓ�Փx�ύX�����{����֐�
};
#pragma once
#include "ENEMY.h"

class SCORE
{
public:
	int score_board();			//�X�R�A�{�[�h��\������֐�
	int score = 50;				//�X�R�A�ݒ�
	int total_score;			//�l�������X�R�A��ێ�
	int TOTAL_SCORE();			//�l�������X�R�A��ێ����A�v�Z����֐�
	void DRAW_TOTAL_SCORE();	//�l�������X�R�A��`�悷��֐�
	void SCORE_RESET();			//�l�������X�R�A�����Z�b�g����֐�
};
#include "DxLib.h"
#include "SCORE.h"

//�l�������X�R�A��ێ����A�v�Z����֐�
int SCORE::TOTAL_SCORE()
{
	total_score += score;
	return total_score;
}


//�l�������X�R�A��`�悷��֐�
void SCORE::DRAW_TOTAL_SCORE()
{
	//DrawFormatStringF(300, 0, RGB(255, 255, 255), "TOTAL_SCORE:%d", total_score);
	DrawFormatStringToHandle(600, 70, GetColor(255, 255, 0), FontHandle_SCORE, "TOTAL_SCORE:%d", total_score);	//�����̑傫���ύX);
}

//int SCORE::score_board()
//{
//
//}

//�l�������X�R�A�����Z�b�g����֐�
void SCORE::SCORE_RESET() 
{
	total_score = 0;
}
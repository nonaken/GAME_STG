#include "DxLib.h"
#include "SCORE.h"

//�l�������X�R�A��ێ����A�v�Z����֐�
int SCORE::TOTAL_SCORE()
{
	total_score += score;
	/*if (ENEMY_Handle[0] || ENEMY_Handle[1] || ENEMY_Handle[2])
	{
		total_score += score;
	}

	if (ENEMY_Handle[3] || ENEMY_Handle[4] || ENEMY_Handle[5])
	{
		total_score += score * 2;
	}

	if (ENEMY_Handle[6] || ENEMY_Handle[7] || ENEMY_Handle[8])
	{
		total_score += score * 3;
	}

	if (ENEMY_Handle[9] || ENEMY_Handle[10] || ENEMY_Handle[11])
	{
		total_score += score * 4;
	}*/

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
#include "DxLib.h"
#include "SCORE.h"

int SCORE::TOTAL_SCORE()
{
	total_score += score;
	return total_score;
}



void SCORE::DRAW_TOTAL_SCORE()
{
	DrawFormatStringF(300, 500, RGB(255, 255, 255), "TOTAL_SCORE:%d", total_score);
}

//int SCORE::score_board()
//{
//
//}

void SCORE::SCORE_RESET() 
{
	total_score = 0;
}
#include "DxLib.h"
#include "SCORE.h"

//獲得したスコアを保持し、計算する関数
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


//獲得したスコアを描画する関数
void SCORE::DRAW_TOTAL_SCORE()
{
	//DrawFormatStringF(300, 0, RGB(255, 255, 255), "TOTAL_SCORE:%d", total_score);
	DrawFormatStringToHandle(600, 70, GetColor(255, 255, 0), FontHandle_SCORE, "TOTAL_SCORE:%d", total_score);	//文字の大きさ変更);
}

//int SCORE::score_board()
//{
//
//}

//獲得したスコアをリセットする関数
void SCORE::SCORE_RESET() 
{
	total_score = 0;
}
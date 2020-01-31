#include "DxLib.h"
#include "SCORE.h"

//獲得したスコアを保持し、計算する関数
int SCORE::TOTAL_SCORE()
{
	total_score += score;
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
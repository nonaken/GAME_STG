#pragma once
#include "ENEMY.h"

class SCORE
{
public:
	int score_board();			//スコアボードを表示する関数
	int score = 50;				//スコア設定
	int total_score;			//獲得したスコアを保持
	int TOTAL_SCORE();			//獲得したスコアを保持し、計算する関数
	void DRAW_TOTAL_SCORE();	//獲得したスコアを描画する関数
	void SCORE_RESET();			//獲得したスコアをリセットする関数
};
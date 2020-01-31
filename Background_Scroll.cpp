#include "DxLib.h"
#include"Background_Scroll.h"
#include "WINDOW_SIZE.h"

//スクロールする背景画像を描画する関数
void BACKGROUND::Background_Scroll_Draw()
{
	//////////////////////スクロールする背景を描画する処理/////////////////
	//スクロールする背景画像を描画する(１枚目)
	DrawExtendGraph(this->img_Back_Scroll_W, this->img_Back_Scroll_H, GAME_WIDTH, GAME_HEIGHT + this->img_Back_Scroll_H, this->imgBack_Scroll, false);

	//スクロールする背景画像を描画する(２枚目スクロール用)
	DrawExtendGraph(this->img_Back_Scroll_W, this->img_Back_Scroll_H - GAME_HEIGHT, GAME_WIDTH, this->img_Back_Scroll_H, this->imgBack_Scroll, false);
	///////////////////////////////////////////////////////////////////////////

}

//スクロール処理をする関数
void BACKGROUND::Background_Scroll()
{
	//２枚目の画像のスクロールが終わるまで加算する
	if (img_Back_Scroll_H < GAME_HEIGHT)
	{
		img_Back_Scroll_H += 5;
	}
	//２枚目の画像のスクロールが終わったらリセットする
	else
	{
		img_Back_Scroll_H = 0;
	}
}
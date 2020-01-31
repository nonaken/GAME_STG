#pragma once

class BACKGROUND
{
public:
	int img_Back_Scroll_W;		//縦スクロール背景 横サイズを保持する変数
	int img_Back_Scroll_H;		//縦スクロール背景 縦サイズを保持する変数
	int imgBack_Scroll = 0;		//スクロールする画像をロードするための変数

	void Background_Scroll_Draw();		//スクロールする背景画像を描画する関数
	void Background_Scroll();			//背景をスクロールする関数
};
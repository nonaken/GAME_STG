#pragma once

#define GAME_BackImage_TITLE	"BackImage\\背景.png"//"BackImage\\kaidou0331_800b.jpg"	//タイトル画面背景画像
#define GAME_TITLE_LOG			"BackImage\\game_title_font.png"	//タイトルロゴ
#define GAME_BackImage_PLAY		"BackImage\\背景.png"				//プレイ画面背景画像
#define GAME_BackImage_CLEAR	"BackImage\\GAME_CLEAR.jpg"			//クリア画面背景画像
#define GAME_BackImage_END		"BackImage\\GAME_OVER_2.jpg"			//エンド画面背景画像

class BACKGROUND
{
public:
	int img_Back_Scroll_W;		//縦スクロール背景 横サイズを保持する変数
	int img_Back_Scroll_H;		//縦スクロール背景 縦サイズを保持する変数
	int imgBack_Scroll = 0;		//スクロールする画像をロードするための変数

	void Background_Scroll_Draw();		//スクロールする背景画像を描画する関数
	void Background_Scroll();			//背景をスクロールする関数
};
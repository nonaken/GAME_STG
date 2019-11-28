#pragma once

#include "DxLib.h"
#include "Keyboard_Get.h"
#include "ENEMY.h"
#include "window_size.h"

#define GAME_PLAYER "クリスマスキャラチップ\\テスト.jpg"
#define PLAYER_BUNKATU	12			//プレイヤー画像の総分割数
#define PLAYER_BUNKATU_X 4//3		//プレイヤー画像の横分割数
#define PLAYER_BUNKATU_Y 3//4		//プレイヤー画像の縦分割数
#define PLAYER_MIN_SOEJI 1			//プレイヤーの最初の画像
#define PLAYER_MAX_SOEJI 12			//プレイヤーの最後の画像

int PLAYER_Size;					//プレイヤーの画像サイズをLoadDivGrahpで取得するため
int PLAYER_Size_W, PLAYER_Size_H;	//プレイヤー画像の横サイズ、縦サイズを取得

class PLAYER{
private:
	
	
	int PLAYER_HP = 3;						//プレイヤーの体力
	int PLAYER_Speed;					//プレイヤーのスピード

public:
	int PLAYER_X = 0;		//プレイヤーの初期X位置
	int PLAYER_Y = 0;		//プレイヤーの初期Y位置
	int PLAYER_soeji = 1;				//プレイヤーの添え字に使う
	int PLAYER_Handle[PLAYER_MAX_SOEJI];//プレイヤーのハンドル
	int Get_PLAYER_Speed();				//プレイヤーのスピードを関数で取得
	int Get_PLAYER_X();					//プレイヤーのX位置を関数で取得
	int Get_PLAYER_Y();					//プレイヤーのY位置を関数で取得
	void PLAYER_DRAW();					//プレイヤーを描画する関数
	void PLAYER_RESET();
	int cnt = 0;
	void PLAYER_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y);		//プレイヤーとエネミーの衝突判定

};

//プレイヤーのスピードを取得する関数
int PLAYER::Get_PLAYER_Speed()
{
	//プレイヤーのスピード設定
	PLAYER_Speed = 10;
	return PLAYER_Speed;
}

//プレイヤーのX位置を取得する関数
int PLAYER::Get_PLAYER_X()
{
	//プレイヤーを操作する　左　矢印キーを押した場合
	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1)
	{
		//windowの左端まで移動する
		if (PLAYER_X >= GAME_MIN_WIDTH)
		{
			PLAYER_X -= Get_PLAYER_Speed();
		}
		/*if (fps->Wait)
		{
			PLAYER_soeji = fps->Wait % 2;
		}*/
	}
	//プレイヤーを操作する　右　矢印キーを押した場合
	if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1)
	{
		//windowの右端まで移動する(プレイヤーの画像横サイズ分、値を減らす)　
		if (PLAYER_X <= GAME_WIDTH - PLAYER_Size_W / PLAYER_BUNKATU_X)
		{
			PLAYER_X += Get_PLAYER_Speed();
		}
	}
	return PLAYER_X;
}

//プレイヤーのY位置を取得する関数
int PLAYER::Get_PLAYER_Y()
{
	//プレイヤーを操作する　上　矢印キーを押した場合
	if (Keyboard_Get(KEY_INPUT_UP) >= 1)
	{
		//windowの上端まで移動する
		if (PLAYER_Y >= GAME_MIN_HEIGHT)
		{
			PLAYER_Y -= Get_PLAYER_Speed();
		}
	}
	//プレイヤーを操作する　下　矢印キーを押した場合
	if (Keyboard_Get(KEY_INPUT_DOWN) >= 1)
	{
		//windowの下端まで移動する(プレイヤーの画像縦サイズ分、値を減らす)
		if (PLAYER_Y <= GAME_HEIGHT - PLAYER_Size_H / PLAYER_BUNKATU_Y)
		{
			PLAYER_Y += Get_PLAYER_Speed();
		}
	}
	return PLAYER_Y;
}

//プレイヤーを描画する関数
void PLAYER::PLAYER_DRAW()
{
	DrawGraph(Get_PLAYER_X(), Get_PLAYER_Y(), PLAYER_Handle[PLAYER_soeji], TRUE);
}


void PLAYER::PLAYER_RESET()
{
	PLAYER_X = GAME_WIDTH / 2;
	PLAYER_Y = GAME_HEIGHT / 2;
	PLAYER_HP = 3;
}


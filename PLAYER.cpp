#include "DxLib.h"
#include "PLAYER.h"
#include "Keyboard_Get.h"
#include "WINDOW_SIZE.h"

int PLAYER_Size;					//プレイヤーの画像サイズをLoadDivGrahpで取得するため
int PLAYER_Size_W, PLAYER_Size_H;	//プレイヤー画像の横サイズ、縦サイズを取得

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

//プレイヤーを初期位置へ移動
void PLAYER::PLAYER_RESET()
{
	PLAYER_X = GAME_WIDTH / PLAYER_X_HALF;
	PLAYER_Y = GAME_HEIGHT / PLAYER_Y_HALF;
}

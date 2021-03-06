#include "DxLib.h"
#include "PLAYER.h"
#include "Keyboard_Get.h"
#include "WINDOW_SIZE.h"


int PLAYER_Size;					//プレイヤーの画像サイズをLoadDivGrahpで取得するため
int PLAYER_Size_W, PLAYER_Size_H;	//プレイヤー画像の横サイズ、縦サイズを取得

int PLAYER_HIT_ANIMATION_Size;						//プレイヤーの無敵アニメーション画像のサイズをLoadDivGrahpで取得するため	(ENEMY.cppでも同じ変数を利用するため、externを使用している)
int PLAYER_HIT_ANIMATION_Size_W, PLAYER_HIT_ANIMATION_Size_H;		//プレイヤーの無敵アニメーション画像の横サイズ、縦サイズを取得	(ENEMY.cppでも同じ変数を利用するため、externを使用している)


//プレイヤーのスピードを取得する関数
int PLAYER::Get_PLAYER_Speed()
{
	//プレイヤーのスピード設定
	PLAYER_Speed = 5;
	return PLAYER_Speed;
}

//プレイヤーのX位置を取得する関数
int PLAYER::Get_PLAYER_X()
{

	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1 && Keyboard_Get(KEY_INPUT_UP) >= 1 ||
		Keyboard_Get(KEY_INPUT_LEFT) >= 1 && Keyboard_Get(KEY_INPUT_DOWN) >= 1 ||
		Keyboard_Get(KEY_INPUT_RIGHT) >= 1 && Keyboard_Get(KEY_INPUT_UP) >= 1 ||
		Keyboard_Get(KEY_INPUT_RIGHT) >= 1 && Keyboard_Get(KEY_INPUT_DOWN) >= 1 ||
		Keyboard_Get(KEY_INPUT_LEFT) >= 1 && Keyboard_Get(KEY_INPUT_RIGHT) >= 1 ||
		Keyboard_Get(KEY_INPUT_LEFT) == 0 && Keyboard_Get(KEY_INPUT_RIGHT) == 0
		&& Keyboard_Get(KEY_INPUT_UP) == 0 && Keyboard_Get(KEY_INPUT_DOWN) == 0)
	{
		PLAYER_MOVE_flag = false;
		PLAYER_soeji = PLAYER_UP_SOEJI;
	}


	//プレイヤーを操作する　左　矢印キーを押した場合
	else if (Keyboard_Get(KEY_INPUT_LEFT) >= 1)
	{
		PLAYER_MOVE_flag = true;
		//windowの左端まで移動する
		if (PLAYER_X >= GAME_MIN_WIDTH)
		{
			if (PLAYER_MOVE_flag == true)
			{
				PLAYER_X -= Get_PLAYER_Speed();

				//アニメーション用カウント
				PLAYER_COUNT++;

				//左に移動するアニメーション
				PLAYER_soeji = PLAYER_LEFT_SOEJI + (PLAYER_COUNT / PLAYER_ANIMATION_FRAME) % PLAYER_ANIMETION_PATTERN;
			}
		}
		/*if (fps->Wait)
		{
			PLAYER_soeji = fps->Wait % 2;
		}*/
	}
	//プレイヤーを操作する　右　矢印キーを押した場合
	else if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1)
	{
		PLAYER_MOVE_flag = true;
		//windowの右端まで移動する(プレイヤーの画像横サイズ分、値を減らす)　
		if (PLAYER_X <= GAME_WIDTH - PLAYER_Size_W / PLAYER_BUNKATU_X)
		{
			if (PLAYER_MOVE_flag == true)
			{
				PLAYER_X += Get_PLAYER_Speed();

				//アニメーション用カウント
				PLAYER_COUNT++;

				//右に移動するアニメーション
				PLAYER_soeji = PLAYER_RIGHT_SOEJI + (PLAYER_COUNT / PLAYER_ANIMATION_FRAME) % PLAYER_ANIMETION_PATTERN;
			}
		}
	}

	//プレイヤーを操作する　右　矢印キーを押した場合
	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1 && Keyboard_Get(KEY_INPUT_RIGHT) >= 1)
	{
		PLAYER_soeji = PLAYER_UP_SOEJI;
	}

	return PLAYER_X;
}

//プレイヤーのY位置を取得する関数
int PLAYER::Get_PLAYER_Y()
{

	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1 && Keyboard_Get(KEY_INPUT_UP) >= 1 ||
		Keyboard_Get(KEY_INPUT_LEFT) >= 1 && Keyboard_Get(KEY_INPUT_DOWN) >= 1 ||
		Keyboard_Get(KEY_INPUT_RIGHT) >= 1 && Keyboard_Get(KEY_INPUT_UP) >= 1 ||
		Keyboard_Get(KEY_INPUT_RIGHT) >= 1 && Keyboard_Get(KEY_INPUT_DOWN) >= 1 ||
		Keyboard_Get(KEY_INPUT_UP) >= 1 && Keyboard_Get(KEY_INPUT_DOWN) >= 1)
	{
		PLAYER_MOVE_flag = false;
	}
	//プレイヤーを操作する　上　矢印キーを押した場合
	else if (Keyboard_Get(KEY_INPUT_UP) >= 1)
	{
		PLAYER_MOVE_flag = true;
		//windowの上端まで移動する
		if (PLAYER_Y >= GAME_MIN_HEIGHT)
		{
			if (PLAYER_MOVE_flag == true)
			{
				PLAYER_Y -= Get_PLAYER_Speed();

				//アニメーション用カウント
				PLAYER_COUNT++;

				//上に移動するアニメーション
				PLAYER_soeji = PLAYER_UP_SOEJI + (PLAYER_COUNT / PLAYER_ANIMATION_FRAME) % PLAYER_ANIMETION_PATTERN;
			}
		}
	}
	//プレイヤーを操作する　下　矢印キーを押した場合
	else if (Keyboard_Get(KEY_INPUT_DOWN) >= 1)
	{
		PLAYER_MOVE_flag = true;
		//windowの下端まで移動する(プレイヤーの画像縦サイズ分、値を減らす)
		if (PLAYER_Y <= GAME_HEIGHT - PLAYER_Size_H / PLAYER_BUNKATU_Y)
		{
			if (PLAYER_MOVE_flag == true)
			{
				PLAYER_Y += Get_PLAYER_Speed();

				//アニメーション用カウント
				PLAYER_COUNT++;

				//下に移動するアニメーション
				PLAYER_soeji = PLAYER_DOWN_SOEJI + (PLAYER_COUNT / PLAYER_ANIMATION_FRAME) % PLAYER_ANIMETION_PATTERN;
			}
		}
	}
	return PLAYER_Y;
}

//プレイヤーのHPを描画する関数
void PLAYER::PLAYER_HP_DRAW()
{
	DrawFormatStringToHandle(0, 0, GetColor(255, 0, 0), FontHandle_PLAYER_HP,"PLAYER：%d", PLAYER_HP);	//プレイヤーの体力を描画する
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


//エネミーの爆発アニメーションを描画する関数
void PLAYER::PLAYER_ANIMATION_DRAW(int x, int y)
{
	//DrawGraph(Get_ENEMY_X() - ENEMY_ANIMATION_Size_W / ENEMY_ANIMATION_BUNKATU_X / 2, Get_ENEMY_Y() - ENEMY_ANIMATION_Size_H / ENEMY_ANIMATION_BUNKATU_Y / 2, ENEMY_ANIMATION_Handle[ENEMY_ANIMATION_soeji], TRUE);

	DrawGraph(Get_PLAYER_X() - x, Get_PLAYER_Y() - y, PLAYER_HIT_ANIMATION_Handle[PLAYER_HIT_ANIMATION_soeji], TRUE);

}
#include "DxLib.h"
#include "WEAPON.h"
#include "Keyboard_Get.h"
#include "WINDOW_SIZE.h"

int WEAPON_Size;					//ウエポンの画像サイズをLoadDivGrahpで取得するため
int WEAPON_Size_W, WEAPON_Size_H;	//ウエポン画像の横サイズ、縦サイズを取得

//ウエポンのスピードを取得する関数
int WEAPON::Get_WEAPON_Speed(int WEAPON_Speed)
{
	//ウエポンのスピード設定
	WEAPON_Speed = 10;
	return WEAPON_Speed;
};

//ウエポンを描画する関数
void WEAPON::WEAPON_DRAW()
{
	DrawGraph(Get_WEAPON_X(), Get_WEAPON_Y(), WEAPON_Handle[WEAPON_soeji], TRUE);
};

//ウエポンをリセットする関数
void WEAPON::WEAPON_RESET()
{
	WEAPON_X = GAME_WIDTH / PLAYER_X_HALF;
	WEAPON_Y =(GAME_HEIGHT / PLAYER_Y_HALF) - (WEAPON_Size_H / WEAPON_BUNKATU_Y);
};


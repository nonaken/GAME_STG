#pragma once
#include"PLAYER.h"

#define GAME_WEAPON "クリスマスキャラチップ\\テスト.jpg"
#define WEAPON_BUNKATU	12			//プレイヤー画像の総分割数
#define WEAPON_BUNKATU_X 4//3		//プレイヤー画像の横分割数
#define WEAPON_BUNKATU_Y 3//4		//プレイヤー画像の縦分割数
#define WEAPON_MIN_SOEJI 1			//プレイヤーの最初の画像
#define WEAPON_MAX_SOEJI 12			//プレイヤーの最後の画像

#define WEAPON_X_HALF 2	//ウエポンのX位置をプレイヤーの画像サイズの半分に設定するためのマクロ定義

#define WEAPON_NUM 3				//画面に表示できるウエポンの数



class WEAPON : public PLAYER
{
private:
	int WEAPON_Speed = 15;			//ウエポン画像の上昇速度
public:
	int WEAPON_Handle[12];			//ウエポン画像を格納する配列の要素数
	int WEAPON_X;					//ウエポン画像のX位置をプレイヤーの画像サイズの半分に設定する
	int WEAPON_Y;					//ウエポン画像のY位置をプレイヤーのY位置引いた値とする(プレイヤーの上にくるようにする)
	int WEAPON_soeji = 0;			//ウエポン画像の添え字

	int Get_WEAPON_Speed();			//ウエポンのスピードを取得取得する関数
	int Get_WEAPON_Y();				//ウエポンのX位置を取得取得する関数
	int Get_WEAPON_X();				//ウエポンのY位置を取得取得する関数
	void WEAPON_DRAW();				//ウエポンを描画する関数
	void WEAPON_RESET();			//ウエポンをリセットする関数
	void WEAPON_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y);		//ウエポンとエネミーの衝突判定をする関数
};


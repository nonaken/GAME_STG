#pragma once
#include"PLAYER.h"

#define GAME_WEAPON "WEAPON\\おばけ3倍.png"//"WEAPON\\爆弾.png"
#define WEAPON_BUNKATU	12//60			//ウエポン画像の総分割数
#define WEAPON_BUNKATU_X 3//6		//ウエポン画像の横分割数
#define WEAPON_BUNKATU_Y 4//10		//ウエポン画像の縦分割数
#define WEAPON_MIN_SOEJI 1			//ウエポンの最初の画像
#define WEAPON_MAX_SOEJI 12//60			//ウエポンの最後の画像

#define WEAPON_X_HALF 2	//ウエポンのX位置をプレイヤーの画像サイズの半分に設定するためのマクロ定義

#define WEAPON_NUM 3				//画面に表示できるウエポンの数

#define WEAPON_ANIMATION_EXPROSION_FRAME	20	//ウエポンのアニメーション描画フレーム
#define WEAPON_ANIMATION_PATTERN		3		//ウエポンのアニメーションバターン
#define WEAPON_NEXT_ATACKSPEED 0.3				//ウエポンの発射時間


class WEAPON : public PLAYER
{
private:
	int WEAPON_Speed = 0;			//ウエポン画像の上昇速度
public:
	int WEAPON_Handle[WEAPON_MAX_SOEJI];	//ウエポン画像を格納する配列の要素数
	int WEAPON_X;							//ウエポン画像のX位置をプレイヤーの画像サイズの半分に設定する
	int WEAPON_Y;							//ウエポン画像のY位置をプレイヤーのY位置引いた値とする(プレイヤーの上にくるようにする)
	int WEAPON_soeji = 0;					//ウエポン画像の添え字

	int Get_WEAPON_Speed(int WEAPON_Speed);			//ウエポンのスピードを取得取得する関数
	int Get_WEAPON_Y();				//ウエポンのX位置を取得取得する関数
	int Get_WEAPON_X();				//ウエポンのY位置を取得取得する関数
	void WEAPON_DRAW(int, int);				//ウエポンを描画する関数
	void WEAPON_RESET();			//ウエポンをリセットする関数
	void WEAPON_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y);		//ウエポンとエネミーの衝突判定をする関数
	//int WEAPON_SPAWN_RANDOM();


	int WEAPON_ANIMATION_COUNT = 0;			//爆弾のアニメーション用カウント


	bool WEAPON_flag_X = false;
	bool WEAPON_flag_Y = false;
	bool WEAPON_Next_flag = false;
};


#pragma once

#include"WINDOW_SIZE.h"

#define GAME_PLAYER "animals\\$yaksaddle.png"//"PLAYER\\player_縮小.png"
#define PLAYER_BUNKATU	12			//プレイヤー画像の総分割数
#define PLAYER_BUNKATU_X 3//3		//プレイヤー画像の横分割数
#define PLAYER_BUNKATU_Y 4//4		//プレイヤー画像の縦分割数
#define PLAYER_MIN_SOEJI 1			//プレイヤーの最初の画像
#define PLAYER_MAX_SOEJI 12			//プレイヤーの最後の画像

#define PLAYER_X_HALF 2
#define PLAYER_Y_HALF 2


class PLAYER{
private:
	
	int PLAYER_Speed;		//プレイヤーのスピード

public:
	int PLAYER_HP = 3;		//プレイヤーの体力
	int PLAYER_X;		//プレイヤーの初期X位置
	int PLAYER_Y;		//プレイヤーの初期Y位置
	int PLAYER_soeji = 0;				//プレイヤーの添え字に使う
	int PLAYER_Handle[PLAYER_MAX_SOEJI];//プレイヤーのハンドル
	int Get_PLAYER_Speed();				//プレイヤーのスピードを関数で取得
	int Get_PLAYER_X();					//プレイヤーのX位置を関数で取得
	int Get_PLAYER_Y();					//プレイヤーのY位置を関数で取得
	void PLAYER_DRAW();					//プレイヤーを描画する関数
	void PLAYER_RESET();
	void PLAYER_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y);		//プレイヤーとエネミーの衝突判定をする関数
	int PLAYER_COUNT = 0;
};




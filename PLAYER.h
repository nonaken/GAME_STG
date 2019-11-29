#pragma once

#define GAME_PLAYER "クリスマスキャラチップ\\テスト.jpg"
#define PLAYER_BUNKATU	12			//プレイヤー画像の総分割数
#define PLAYER_BUNKATU_X 4//3		//プレイヤー画像の横分割数
#define PLAYER_BUNKATU_Y 3//4		//プレイヤー画像の縦分割数
#define PLAYER_MIN_SOEJI 1			//プレイヤーの最初の画像
#define PLAYER_MAX_SOEJI 12			//プレイヤーの最後の画像



class PLAYER{
private:
	int PLAYER_HP = 3;		//プレイヤーの体力
	int PLAYER_Speed;		//プレイヤーのスピード

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
	void PLAYER_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y);		//プレイヤーとエネミーの衝突判定をする関数
};




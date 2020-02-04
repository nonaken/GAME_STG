#pragma once

#include"WINDOW_SIZE.h"

#define GAME_PLAYER "animals\\魔王猫3倍.png"//"animals\\$yaksaddle.png"//"PLAYER\\player_縮小.png"
#define PLAYER_BUNKATU	12			//プレイヤー画像の総分割数
#define PLAYER_BUNKATU_X 3//3		//プレイヤー画像の横分割数
#define PLAYER_BUNKATU_Y 4//4		//プレイヤー画像の縦分割数
#define PLAYER_MIN_SOEJI 1			//プレイヤーの最初の画像
#define PLAYER_MAX_SOEJI 12			//プレイヤーの最後の画像

#define PLAYER_X_HALF 2				//プレイヤーの初期X位置(画面の横幅 / 2)
#define PLAYER_Y_HALF 2				//プレイヤーの初期Y位置(画面の縦幅 / 2)

#define PLAYER_INVINCIBLE_TIME 1	//プレイヤーの無敵時間


#define PLAYER_DOWN_SOEJI 0			//下向きの画像
#define PLAYER_UP_SOEJI 9			//上向きの画像
#define PLAYER_LEFT_SOEJI 3			//左向きの画像
#define PLAYER_RIGHT_SOEJI 6		//右向きの画像

#define PLAYER_HIT_INVINCIBLE_ANIMATION	"ANIMATION\\無敵.png"	//"ANIMATION\\無敵エフェクト2.png"//プレイヤーの無敵アニメーション画像
#define PLAYER_HIT_INVINCIBLE_ANIMATION_BUNKATU	12				//プレイヤーの無敵アニメーション画像の総分割数
#define PLAYER_HIT_INVINCIBLE_ANIMATION_BUNKATU_X 12			//プレイヤーの無敵アニメーション画像の横分割数
#define PLAYER_HIT_INVINCIBLE_ANIMATION_BUNKATU_Y 1				//プレイヤーの無敵アニメーション画像の縦分割数

#define PLAYER_HIT_INVINCIBLE_ANIMATION_FRAME 5//10				//プレイヤーの無敵アニメーションの描画を切り替えるフレーム数
#define PLAYER_HIT_INVINCIBLE_ANIMATION_PATTERN 12//3			//プレイヤーの無敵アニメーションの種類


#define PLAYER_ANIMATION_FRAME 5				//プレイヤーの無敵アニメーション描画を切り替えるフレーム数
#define PLAYER_ANIMETION_PATTERN 3				//プレイヤーの無敵アニメーション種類

#define PLAYER_HIT_ANIMATION_MIN_SOEJI 1		//プレイヤーの無敵アニメーションの最小値
#define PLAYER_HIT_ANIMATION_MAX_SOEJI 12		//プレイヤーの無敵アニメーションの最大値

//プレイヤーのクラス
class PLAYER{
private:
	
	int PLAYER_Speed;	//プレイヤーのスピード

public:
	int PLAYER_HP = 3;	//プレイヤーの体力
	int PLAYER_X;		//プレイヤーの初期X位置
	int PLAYER_Y;		//プレイヤーの初期Y位置
	int PLAYER_soeji = 0;				//プレイヤーの添え字に使う
	int PLAYER_Handle[PLAYER_MAX_SOEJI];//プレイヤーのハンドル
	int FontHandle_PLAYER_HP = 0;		//プレイヤーのHPを描画するフォントハンドル用変数

	bool PLAYER_MOVE_flag = false;		//プレイヤーが動いたか管理するフラグ(同時押しをできなくする)
	bool PLAYER_INVINCIBLE_flag = false;//プレイヤーが敵に触れたら一定時間無敵タイムにする(スコアは増えない)

	int Get_PLAYER_Speed();				//プレイヤーのスピードを関数で取得
	int Get_PLAYER_X();					//プレイヤーのX位置を関数で取得
	int Get_PLAYER_Y();					//プレイヤーのY位置を関数で取得
	void PLAYER_HP_DRAW();
	void PLAYER_DRAW();					//プレイヤーを描画する関数
	void PLAYER_RESET();				//プレイヤーの初期設定
	void PLAYER_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y);		//プレイヤーとエネミーの衝突判定をする関数
	int PLAYER_COUNT = 0;				//プレイヤーのアニメーション用カウント

	int PLAYER_HIT_ANIMATION_COUNT = 0;
	int PLAYER_HIT_ANIMATION_soeji = 0;
	int PLAYER_HIT_ANIMATION_Handle[PLAYER_HIT_ANIMATION_MAX_SOEJI];	//プレイヤーのアニメーション画像の添え字を入れる
	void PLAYER_ANIMATION_DRAW(int x, int y);
};




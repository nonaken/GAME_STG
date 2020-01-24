#pragma once


#define GAME_ENEMY					"animals\\Bison.png"		//エネミーのキャラクター画像
#define ENEMY_BUNKATU	96		//エネミー画像の総分割数
#define ENEMY_BUNKATU_X 12//3	//エネミー画像の横分割数
#define ENEMY_BUNKATU_Y 8//4	//エネミー画像の縦分割数

#define ENEMY_MIN_SOEJI 1		//エネミーの最初の画像
#define ENEMY_MAX_SOEJI 96		//エネミーの最後の画像

#define ENEMY_NUM 3				//画面に登場するエネミーの数

#define ENEMY_EXPROSION_ANIMATION	"ANIMATION\\衝突演出.png"	//エネミーの爆発アニメーション画像
#define ENEMY_ANIMATION_BUNKATU	6		//エネミー画像の総分割数
#define ENEMY_ANIMATION_BUNKATU_X 5//3	//エネミー画像の横分割数
#define ENEMY_ANIMATION_BUNKATU_Y 2//4	//エネミー画像の縦分割数
#define ENEMY_ANIMATION_MIN_SOEJI 1		//エネミーの最初の画像
#define ENEMY_ANIMATION_MAX_SOEJI 5		//エネミーの最後の画像


class ENEMY
{
private:

	int ENEMY_HP;		//エネミーのHP
	int ENEMY_Speed;	//エネミーのスピード(落下速度)

public:

	int ENEMY_X = WINDOW_WIDTH_RANDOM_ENEMY_X();	//エネミーのX座標(初期X位置を乱数で設定している)
	int ENEMY_Y;									//エネミーのY座標
	int WINDOW_WIDTH_RANDOM_ENEMY_X();	//エネミーのX位置を乱数で生成する関数
	int RANDOM();						//エネミーの画像の添え字を乱数で生成する関数
	int ENEMY_Handle[ENEMY_MAX_SOEJI];	//エネミーの画像の添え字を入れる配列（要素数はエネミーの画像の最後の添え字分）

	int Get_ENEMY_Speed();			//エネミーのスピードを取得
	int Get_ENEMY_Y();				//エネミーのX位置を取得
	int Get_ENEMY_X();				//エネミーのY位置を取得
	void ENEMY_DRAW();				//エネミーの描画処理をする関数
	void ENEMY_RESET();				//エネミーの初期化をする関数
	int RANDOM_soeji = RANDOM();	//エネミーの添え字を乱数から取得

	bool ENEMY_EXPROSION_flag = false;	//エネミーの爆発フラグ
	int ENEMY_ANIMATION_soeji = 0;	//エネミーのアニメーション用添え字
	int ENEMY_ANIMATION_Handle[ENEMY_ANIMATION_MAX_SOEJI];	//エネミーのアニメーション画像の添え字を入れる配列（要素数はエネミーの画像の最後の添え字分）
	void ENEMY_ANIMATION_DRAW(int ,int);	//エネミーの爆発アニメーションを描画する関数
	int ENEMY_COUNT = 0;			//エネミーのアニメーション用カウント
	//int ENEMY_SPAWN_RANDOM();

	//ENEMY();
	//~ENEMY();


};

//ENEMY::ENEMY()
//{
//	for (int num = 0; num < ENEMY_NUM; num++)
//	{
//		e[num] = NULL;
//	}
//}
//
//ENEMY::~ENEMY()
//{
//	for (int num = 0; num < ENEMY_NUM; num++)
//	{
//		delete e[num];
//	}
//}

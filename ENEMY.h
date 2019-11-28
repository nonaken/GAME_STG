#pragma once
#include "window_size.h"
#include <random>

#define GAME_ENEMY		"クリスマスキャラチップ\\テスト.jpg"			//キャラクター画像
#define ENEMY_BUNKATU	12		//プレイヤー画像の総分割数
#define ENEMY_BUNKATU_X 4//3	//プレイヤー画像の横分割数
#define ENEMY_BUNKATU_Y 3//4	//プレイヤー画像の縦分割数

#define ENEMY_MIN_SOEJI 1		//エネミーの最初の画像
#define ENEMY_MAX_SOEJI 12		//エネミーの最後の画像

#define ENEMY_NUM 3 //画面に登場するエネミーの数

int ENEMY_Size;	//画像の横と縦のサイズを調べるための変数
int ENEMY_Size_W, ENEMY_Size_H;

class ENEMY
{
private:

	int ENEMY_HP;
	int ENEMY_Speed;
	
public:
	
	int ENEMY_X = WINDOW_WIDTH_RANDOM_ENEMY_X();
	int ENEMY_Y;
	int WINDOW_WIDTH_RANDOM_ENEMY_X();
	int RANDOM();
	int ENEMY_Handle[ENEMY_MAX_SOEJI];
	
	int Get_ENEMY_Speed();
	int Get_ENEMY_Y();
	int Get_ENEMY_X();
	void ENEMY_DRAW();
	void ENEMY_RESET();
	int RANDOM_soeji = RANDOM();

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

//エネミーX座標を乱数で生成する
int ENEMY::RANDOM()
{

	std::random_device rd;

	std::mt19937 mt(rd());

	//ENEMY_RANDOM_X_DROW = true;
	//1～画面サイズの横幅までを乱数で決める
	std::uniform_int_distribution<int> RANDOM(ENEMY_MIN_SOEJI - 1, ENEMY_MAX_SOEJI - 1);	//添え字は最初１から数えるため

	return RANDOM(mt);
}

//エネミーのX位置を乱数で生成する関数
int ENEMY::WINDOW_WIDTH_RANDOM_ENEMY_X()
{
	std::random_device rd;

	std::mt19937 mt(rd());

	//1～画面サイズの横幅までを乱数で決める
	std::uniform_int_distribution<int> WINDOW_WIDTH_RANDOM_ENEMY_X(0, GAME_WIDTH - ENEMY_Size_W / ENEMY_BUNKATU_X);

	return WINDOW_WIDTH_RANDOM_ENEMY_X(mt);
}

//エネミーのスピードを設定する
int ENEMY::Get_ENEMY_Speed()
{
	ENEMY_Speed = 10;
	return ENEMY_Speed;
}


int ENEMY::Get_ENEMY_Y()
{
	ENEMY_Y += Get_ENEMY_Speed();
	if (ENEMY_Y > GAME_HEIGHT)
	{
		ENEMY_Y = 0;
		ENEMY_X = WINDOW_WIDTH_RANDOM_ENEMY_X();
		RANDOM_soeji = RANDOM();
	}

	return ENEMY_Y;
}

int ENEMY::Get_ENEMY_X()
{
	return ENEMY_X;
}


void ENEMY::ENEMY_DRAW()
{
	DrawGraph(Get_ENEMY_X(), Get_ENEMY_Y(), ENEMY_Handle[RANDOM_soeji], TRUE);
}

void ENEMY::ENEMY_RESET()
{
	ENEMY_Y = 0;
	ENEMY_X = WINDOW_WIDTH_RANDOM_ENEMY_X();
	RANDOM_soeji = RANDOM();
}



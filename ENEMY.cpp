#include "DxLib.h"
#include "WINDOW_SIZE.h"
#include <random>
#include "ENEMY.h"

int ENEMY_Size;						//エネミーの画像サイズをLoadDivGrahpで取得するため
int ENEMY_Size_W, ENEMY_Size_H;		//エネミーの画像の横サイズ、縦サイズを取得

int ENEMY_ANIMATION_Size;						//エネミー画像のサイズをLoadDivGrahpで取得するため	(ENEMY.cppでも同じ変数を利用するため、externを使用している)
int ENEMY_ANIMATION_Size_W, ENEMY_ANIMATION_Size_H;		//エネミー画像の横サイズ、縦サイズを取得	(ENEMY.cppでも同じ変数を利用するため、externを使用している)



//エネミーの添え字を乱数で生成する関数(乱数はメルセンヌ・ツイスタを使用)
int ENEMY::RANDOM()
{
	std::random_device rd;

	std::mt19937 mt(rd());

	//ENEMY_RANDOM_X_DROW = true;
	//エネミー画像の添え字の最小値から最大値までを乱数で決める
	//std::uniform_int_distribution<int> RANDOM(ENEMY_MIN_SOEJI - 1, ENEMY_MAX_SOEJI - 1);	//添え字は最初１から数えるため
	std::uniform_int_distribution<int> RANDOM(ENEMY_MIN_SOEJI - 1, ENEMY_RANDOM_soeji_MAX);	//添え字は最初１から数えるため
	
	//if (RANDOM(mt) != 0 || RANDOM(mt) % 3 != 0)
	//{
	//	std::uniform_int_distribution<int> RANDOM(ENEMY_MIN_SOEJI - 1, ENEMY_RANDOM_soeji_MAX);	//添え字は最初１から数えるため
	//}

	return RANDOM(mt);
}

//エネミーのX位置を乱数で生成する関数(乱数はメルセンヌ・ツイスタを使用)
int ENEMY::WINDOW_WIDTH_RANDOM_ENEMY_X()
{
	std::random_device rd;

	std::mt19937 mt(rd());

	//1～画面サイズの横幅までを乱数で決める
	std::uniform_int_distribution<int> WINDOW_WIDTH_RANDOM_ENEMY_X(0, GAME_WIDTH - ENEMY_Size_H / ENEMY_BUNKATU_X);

	return WINDOW_WIDTH_RANDOM_ENEMY_X(mt);
}

/*
//エネミーを乱数が指定したの数値になったら生成する
int ENEMY::ENEMY_SPAWN_RANDOM()
{
	std::random_device rd;

	std::mt19937 mt(rd());

	//ENEMY_RANDOM_X_DROW = true;
	//エネミー画像の添え字の最小値から最大値までを乱数で決める
	std::uniform_int_distribution<int> ENEMY_SPAWN_RANDOM(ENEMY_MIN_SOEJI - 1, 50);	//添え字は最初１から数えるため

	return ENEMY_SPAWN_RANDOM(mt);
}
*/

//エネミーのスピードを取得する関数
int ENEMY::Get_ENEMY_Speed()
{
	ENEMY_Speed = 5;
	return ENEMY_Speed;
}

//エネミーのX位置を取得する関数
int ENEMY::Get_ENEMY_X()
{
	return ENEMY_X;
}



//エネミーの描画処理をする関数
void ENEMY::ENEMY_DRAW()
{

	DrawGraph(Get_ENEMY_X(), Get_ENEMY_Y(), ENEMY_Handle[RANDOM_soeji], TRUE);
}

//エネミーの爆発アニメーションを描画する関数
void ENEMY::ENEMY_ANIMATION_DRAW(int x,int y)
{
	//DrawGraph(Get_ENEMY_X() - ENEMY_ANIMATION_Size_W / ENEMY_ANIMATION_BUNKATU_X / 2, Get_ENEMY_Y() - ENEMY_ANIMATION_Size_H / ENEMY_ANIMATION_BUNKATU_Y / 2, ENEMY_ANIMATION_Handle[ENEMY_ANIMATION_soeji], TRUE);

	DrawGraph(Get_ENEMY_X() - x, Get_ENEMY_Y() - y,ENEMY_ANIMATION_Handle[ENEMY_ANIMATION_soeji], TRUE);

}


//エネミーの初期化をする関数
void ENEMY::ENEMY_RESET()
{
		ENEMY_Y = GAME_MIN_HEIGHT - ENEMY_Size_H / ENEMY_BUNKATU_Y;
		ENEMY_X = WINDOW_WIDTH_RANDOM_ENEMY_X();
		RANDOM_soeji = RANDOM();
		if (RANDOM_soeji != 0 && RANDOM_soeji % ENEMY_ANIMATION_PATTERN != 0)
		{
			RANDOM_soeji = RANDOM();
		}
		else
		{
			ENEMY_RANDOM_soeji_Evacuation = RANDOM_soeji;
		}
}




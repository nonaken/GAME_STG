#include "DxLib.h"
#include "Keyboard_Get.h"
#include "PLAYER.h"
#include "ENEMY.h"
#include "WEAPON.h"
#include "WINDOW_SIZE.h"
#include "FPS.h"

#define GAME_BackImage_TITLE	"BackImage\\kaidou0331_800b.jpg"	//タイトル画面背景画像
#define GAME_TITLE_LOG			"BackImage\\game_title_font.png"	//タイトルロゴ
#define GAME_BackImage_PLAY		"BackImage\\背景_1.png"	//プレイ画面背景画像
#define GAME_BackImage_END		"BackImage\\end_2.jpg"				//エンド画面背景画像

#define GAME_FPS_SPEED		60			//FPSを設定

#define GAME_TITLE_LOG_UPPERLEFT_X		GAME_WIDTH / 4					//タイトルロゴ画像の左上X座標
#define GAME_TITLE_LOG_UPPERLEFT_Y		GAME_HEIGHT / 3					//タイトルロゴ画像の左上Y座標
#define GAME_TITLE_LOG_BOTTOMLEFT_X		GAME_WIDTH - GAME_WIDTH / 4		//タイトルロゴ画像の右下X座標
#define GAME_TITLE_LOG_BOTTOMLEFT_Y		GAME_HEIGHT - GAME_HEIGHT / 3	//タイトルロゴ画像の右下Y座標

//各画面を設定
enum GAME_SCREEN 
{
	GAME_TITLE,	//タイトル画面
	GAME_PLAY,	//プレイ画面
	GAME_END	//エンド画面
};

//ゲーム画面の遷移を管理する
GAME_SCREEN screen_state = GAME_TITLE;	//画面遷移をコントロールする(最初の画面はタイトル画面)

//プロトタイプ宣言
void GAME_TITLE_DRAW();	//タイトル画面を描画
void GAME_PLAY_DRAW();	//プレイ画面を描画
void GAME_END_DRAW();	//エンド画面を描画


FPS *fps = new FPS(GAME_FPS_SPEED);		//FPSクラスのオブジェクトを生成
PLAYER *p = new PLAYER();				//プレイヤーのオブジェクトを生成する
//WEAPON *w = new WEAPON();				//ウエポンのオブジェクトを生成する
WEAPON *w[WEAPON_NUM];				//ウエポンクラスを５つ生成する
ENEMY *e[ENEMY_NUM];					//エネミークラスを３つ生成する

extern int PLAYER_Size;						//プレイヤー画像のサイズをLoadDivGrahpで取得するため(PLAYER.cppでも同じ変数を利用するため、externを使用している)
extern int PLAYER_Size_W, PLAYER_Size_H;	//プレイヤー画像の横サイズ、縦サイズを取得			(PLAYER.cppでも同じ変数を利用するため、externを使用している)
extern int ENEMY_Size;						//エネミー画像のサイズをLoadDivGrahpで取得するため	(ENEMY.cppでも同じ変数を利用するため、externを使用している)
extern int ENEMY_Size_W, ENEMY_Size_H;		//エネミー画像の横サイズ、縦サイズを取得			(ENEMY.cppでも同じ変数を利用するため、externを使用している)
extern int WEAPON_Size;						//ウエポン画像のサイズをLoadDivGrahpで取得するため	(ENEMY.cppでも同じ変数を利用するため、externを使用している)
extern int WEAPON_Size_W, WEAPON_Size_H;	//エネミー画像の横サイズ、縦サイズを取得			(ENEMY.cppでも同じ変数を利用するため、externを使用している)


int img_Back_Play_W, img_Back_Play_H;
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);		// ウィンドウモードに設定(TRUE: FALSE:フルスクリーン)
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//指定の数値で画面を表示する
	
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);	//描画を裏画面に設定


	PLAYER_Size = LoadGraph(GAME_PLAYER);	//プレイヤー画像の縦と横のサイズを取得するためロードする(すぐに捨てる)

	GetGraphSize(PLAYER_Size, &PLAYER_Size_W, &PLAYER_Size_H);	//プレイヤー画像の縦と横のサイズを取得

	DeleteGraph(PLAYER_Size);				//プレイヤー画像の縦と横のサイズを取得したら、使い捨て

	//プレイヤー画像を指定した分割数、サイズで読み込む
	LoadDivGraph(GAME_PLAYER, PLAYER_BUNKATU, PLAYER_BUNKATU_X, PLAYER_BUNKATU_Y, PLAYER_Size_W / PLAYER_BUNKATU_X, PLAYER_Size_H / PLAYER_BUNKATU_Y, &p->PLAYER_Handle[0]);


	

	WEAPON_Size = LoadGraph(GAME_WEAPON);	//ウエポン画像の縦と横のサイズを取得するためロードする(すぐに捨てる)

	GetGraphSize(WEAPON_Size, &WEAPON_Size_W, &WEAPON_Size_H);	//ウエポン画像の縦と横のサイズを取得

	DeleteGraph(WEAPON_Size);				//ウエポン画像の縦と横のサイズを取得したら、使い捨て

	//ウエポン画像を指定した分割数、サイズで読み込む
	//LoadDivGraph(GAME_WEAPON, WEAPON_BUNKATU, WEAPON_BUNKATU_X, WEAPON_BUNKATU_Y, WEAPON_Size_W / WEAPON_BUNKATU_X, WEAPON_Size_H / WEAPON_BUNKATU_Y, &w->WEAPON_Handle[0]);

	for (int w_cnt = 0;  w_cnt < WEAPON_NUM;  w_cnt++)
	{
		//配列の個数分エネミークラスを生成する
		w[w_cnt] = new WEAPON();
		//ウエポン画像を指定した分割数、サイズで読み込む
		LoadDivGraph(GAME_WEAPON, WEAPON_BUNKATU, WEAPON_BUNKATU_X, WEAPON_BUNKATU_Y, WEAPON_Size_W / WEAPON_BUNKATU_X, WEAPON_Size_H / WEAPON_BUNKATU_Y, &w[w_cnt]->WEAPON_Handle[0]);
	}


	ENEMY_Size = LoadGraph(GAME_ENEMY);	//プレイヤー画像の縦と横のサイズを取得するためロードする(すぐに捨てる)

	GetGraphSize(ENEMY_Size, &ENEMY_Size_W, &ENEMY_Size_H);	//プレイヤー画像の縦と横のサイズを取得

	DeleteGraph(ENEMY_Size);			//プレイヤー画像の縦と横のサイズを取得したら、使い捨て

	for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
	{
		//配列の個数分エネミークラスを生成する
		e[e_num] = new ENEMY();
		//エネミー画像を配列の個数分、指定した分割数、サイズで読み込む
		LoadDivGraph(GAME_ENEMY, ENEMY_BUNKATU, ENEMY_BUNKATU_X, ENEMY_BUNKATU_Y, ENEMY_Size_W / ENEMY_BUNKATU_X, ENEMY_Size_H / ENEMY_BUNKATU_Y, &e[e_num]->ENEMY_Handle[0]);
	}


	//タイトル画面の背景の画像を読み込む
	int imgBack_Title = LoadGraph(GAME_BackImage_TITLE);		//タイトル背景画像を読み込む(*注意：while文で読み込むとFPSが低下する[毎回読み込んでしまうため])
	//タイトルロゴの画像を読み込む
	int imgTitle_log = LoadGraph(GAME_TITLE_LOG);				//タイトルロゴ画像を読み込む(*注意：while文で読み込むとFPSが低下する[毎回読み込んでしまうため])
	
	//プレイ画面の背景画像を読み込む
	int imgBack_Play = LoadGraph(GAME_BackImage_PLAY);			//プレイ背景画像を読み込む(*注意：while文で読み込むとFPSが低下する[毎回読み込んでしまうため])

	//エンド画面の背景画像を読み込む
	int	imgBack_End = LoadGraph(GAME_BackImage_END);			//エンド景画像を読み込む(*注意：while文で読み込むとFPSが低下する[毎回読み込んでしまうため])
	
	
	while (TRUE)	//無限ループ
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了

		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		Keyboard_Update();   //キーボードの更新

		fps->Update();		//FPSの処理[更新]

		switch (screen_state)
		{
		case GAME_TITLE:
			
			//タイトル画像の背景画像を描画する
			DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, imgBack_Title, false);

			//タイトルロゴの画像を描画する
			DrawExtendGraph(GAME_TITLE_LOG_UPPERLEFT_X, GAME_TITLE_LOG_UPPERLEFT_Y, GAME_TITLE_LOG_BOTTOMLEFT_X, GAME_TITLE_LOG_BOTTOMLEFT_Y, imgTitle_log, true);
			
			GAME_TITLE_DRAW();	//タイトル画面を描画

			p->PLAYER_RESET();	//プレイヤーを初期位置へ

			//w->WEAPON_RESET();	//ウエポンを初期位置へ
			for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
			{
				w[w_cnt]->WEAPON_RESET();	//ウエポンを初期位置へ
			}
	
			break;

		case GAME_PLAY:


			//////////////////////スクロール処理/////////////////
			//プレイ画面の背景画像を描画する(１枚目)
			DrawExtendGraph(img_Back_Play_W, img_Back_Play_H, GAME_WIDTH, GAME_HEIGHT + img_Back_Play_H, imgBack_Play, false);

			//プレイ画面の背景画像を描画する(２枚目スクロール用)
			DrawExtendGraph(img_Back_Play_W, img_Back_Play_H -GAME_HEIGHT, GAME_WIDTH, img_Back_Play_H, imgBack_Play, false);

			//２枚目の画像のスクロールが終わるまで加算する
			if (img_Back_Play_H < GAME_HEIGHT)
			{
				img_Back_Play_H += 5;
			}
			//２枚目の画像のスクロールが終わったらリセットする
			else
			{
				img_Back_Play_H = 0;
			}
			///////////////////////////////////////////////////////////////////////////

			GAME_PLAY_DRAW();	//プレイ画面を描画

			p->PLAYER_DRAW();	//プレイヤーの描画処理

			
			
			for (int w_cnt = 0, e_num = 0; w_cnt < WEAPON_NUM, e_num < ENEMY_NUM; w_cnt++, e_num++)
			{
				p->PLAYER_COLLISION_ENEMY(e[e_num]->ENEMY_X, e[e_num]->ENEMY_Y);	//プレイヤーとエネミーの衝突判定
				w[w_cnt]->PLAYER_COLLISION_ENEMY(e[e_num]->ENEMY_X, e[e_num]->ENEMY_Y);

				e[e_num]->ENEMY_DRAW();		//エネミーの描画処理
				w[w_cnt]->WEAPON_DRAW();
			}
			//DrawFormatStringF(0,500, RGB(255, 255, 255), "ENEMY_X:%d", e[num]->ENEMY_X);

			//for (int num = 0; num < ENEMY_NUM; num++)
			//{
			//	p->PLAYER_COLLISION_ENEMY(e[num]->ENEMY_X, e[num]->ENEMY_Y);	//プレイヤーとエネミーの衝突判定
			//	w->WEAPON_COLLISION_ENEMY(e[num]->ENEMY_X, e[num]->ENEMY_Y);
			//	
			//	e[num]->ENEMY_DRAW();		//エネミーの描画処理
			//}
			DrawFormatStringF(0,200, RGB(255, 255, 255), "ENEMY_X[1]:%d", e[0]->ENEMY_X);
			DrawFormatStringF(0, 350, RGB(255, 255, 255), "ENEMY_X[2]:%d", e[1]->ENEMY_X);
			DrawFormatStringF(0, 500, RGB(255, 255, 255), "ENEMY_X[3]:%d", e[2]->ENEMY_X);
			//w->WEAPON_DRAW();

			
			break;

		case GAME_END:

			//エンド画面の背景画像を描画する
			DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, imgBack_End, false);		
			GAME_END_DRAW();	//エンド画面を描画
			break;

		default:
			break;
		}
		fps->Draw(0, 220);	//FPSの処理[描画]

		ScreenFlip();		//モニタのリフレッシュレートの速さで裏画面を再描画

		fps->Wait();		//FPSの処理[待つ]
		
	}

	delete fps;		//fpsクラスの解放
	delete p;		//PLAYERクラスの解放
	//delete w;
	for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
	{
		delete w[w_cnt];
	}
	for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
	{
		delete e[e_num];		//ENEMYクラスの解放
	}
	DxLib_End();			//ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

//タイトル画面を描画する関数
void GAME_TITLE_DRAW() 
{
	DrawString(0, 0, "タイトル　エンターでプレイ画面へ", RGB(255, 255, 255));

	//エンターキーが押されたら
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1)
	{
		screen_state = GAME_PLAY;		//プレイ画面へ遷移する
	}	
}

//プレイ画面を描画する関数
void GAME_PLAY_DRAW()
{
	DrawString(0, 0, "プレイ スペースでエンド画面へ", RGB(255, 255, 255));

	//スペースキーが押されたら
	if (Keyboard_Get(KEY_INPUT_SPACE) == 1)
	{
		screen_state = GAME_END;		//エンド画面へ遷移する
	}
}

//エンド画面を描画する関数
void GAME_END_DRAW()
{
	DrawString(0, 0, "エンド　バックスペースでタイトル画面へ", RGB(255, 255, 255));


	//バックスペースキーが押されたら
	if (Keyboard_Get(KEY_INPUT_BACK) == 1)
	{
		screen_state = GAME_TITLE;		//タイトル画面へ遷移する
	}

	DrawString(0, 50, "エンド　エスケープキーでゲーム終了", RGB(255, 255, 255));

	//エスケープキーが押されたら
	if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1)
	{
		DxLib_End();					//ゲーム終了
	}
}

//プレイヤーとエネミーの衝突判定
void PLAYER::PLAYER_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y)
{
	for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
	{
		//キャラとエネミーの当たり判定
		if (((PLAYER_X > e[e_num]->ENEMY_X && PLAYER_X < e[e_num]->ENEMY_X + ENEMY_Size_W / ENEMY_BUNKATU_X) ||
			(e[e_num]->ENEMY_X > PLAYER_X && e[e_num]->ENEMY_X < PLAYER_X + PLAYER_Size_W / PLAYER_BUNKATU_X)) &&
			((PLAYER_Y > e[e_num]->ENEMY_Y && PLAYER_Y < e[e_num]->ENEMY_Y + ENEMY_Size_H / ENEMY_BUNKATU_Y) ||
			(e[e_num]->ENEMY_Y > PLAYER_Y &&  e[e_num]->ENEMY_Y < PLAYER_Y + PLAYER_Size_H / PLAYER_BUNKATU_Y)))
		{
			//プレイヤーに触れたエネミーの位置や画像の添え字をリセットする
			e[e_num]->ENEMY_RESET();

			//エネミーに触れたらプレイヤーの体力を一つ減らす
			PLAYER_HP -= 1;
		}
	}

	DrawFormatString(0, 50, RGB(255, 255, 255), "PLAYER：%d", PLAYER_HP);

	//プレイヤーの体力が0以下なら
	if (PLAYER_HP <= 0)
	{
		for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
		{
			//プレイヤーに触れたエネミーの位置や画像の添え字をリセットする
			e[e_num]->ENEMY_RESET();
		}
		screen_state = GAME_END;		//エンド画面へ遷移する
	}
}

//ウエポンのY位置を取得する関数
int WEAPON::Get_WEAPON_Y()
{
	//WEAPON_Y = Get_PLAYER_Y() - WEAPON_Size_H / WEAPON_BUNKATU_Y;
	//ウエポンを操作する　A　キーを押した場合
	if (Keyboard_Get(KEY_INPUT_A) >= 1)
	{
		WEAPON_flag_X = true;		//A	キーを押したとき、プレイヤーのX座標を取得するためのフラグ
		WEAPON_flag_Y = true;		//A キーを押したとき、自動でY座標を加算するためのフラグ
	}

	//ウエポンXフラグがtrueかつ、ウエポンのY座標が初期位置でなければ
	if (WEAPON_flag_X == true && WEAPON_Y == p->Get_PLAYER_Y() - (WEAPON_Size_H / WEAPON_BUNKATU_Y))
	{
		//ウエポンのX座標をプレイヤーのX座標と同じ値にする
		WEAPON_X = p->PLAYER_X;

		WEAPON_flag_X = false;
	}

	//ウエポンのYフラグが(Aキーを押した)trueかつ、ウエポンのY座標が(0以上)画面内なら
	if (WEAPON_flag_Y == true && WEAPON_Y >= GAME_MIN_HEIGHT)
	{
		//windowの左端まで移動する	
		WEAPON_Y -= Get_WEAPON_Speed();
		
		/*if (fps->Wait)
		{
			PLAYER_soeji = fps->Wait % 2;
		}*/
	}
	//ウエポン画像のY座標が画面外(0よりも低い値)に到達したとき
	if (WEAPON_Y < GAME_MIN_HEIGHT)
	{
		//ウエポンのY座標をプレイヤーのY座標から、ウエポン画像サイズから分割し、引いた値にする
		//(ウエポンの画像をプレイヤーの頭上に配置するため)
		if (WEAPON_flag_Y == true)
		{
			WEAPON_Y = p->Get_PLAYER_Y() - (WEAPON_Size_H / WEAPON_BUNKATU_Y);
			WEAPON_flag_Y = false;
		}
	}
	return WEAPON_Y;
};


//ウエポンとエネミーの衝突判定
void WEAPON::WEAPON_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y)
{
	for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
	{
		//キャラとエネミーの当たり判定
		if (((WEAPON_X > e[e_num]->ENEMY_X && WEAPON_X < e[e_num]->ENEMY_X + ENEMY_Size_W / ENEMY_BUNKATU_X) ||
			(e[e_num]->ENEMY_X > WEAPON_X && e[e_num]->ENEMY_X < WEAPON_X + WEAPON_Size_W / WEAPON_BUNKATU_X)) &&
			((WEAPON_Y > e[e_num]->ENEMY_Y && WEAPON_Y < e[e_num]->ENEMY_Y + ENEMY_Size_H / ENEMY_BUNKATU_Y) ||
			(e[e_num]->ENEMY_Y > WEAPON_Y && e[e_num]->ENEMY_Y < WEAPON_Y + WEAPON_Size_H / WEAPON_BUNKATU_Y)))
		{
				//ウエポンに触れたエネミーの位置や画像の添え字をリセットする
				e[e_num]->ENEMY_RESET();
				WEAPON_flag_X = false;		//A	キーを押したとき、プレイヤーのX座標を取得するためのフラグ
				WEAPON_flag_Y = false;		//A キーを押したとき、自動でY座標を加算するためのフラグ

				//ウエポンのY座標をプレイヤーのY座標から、ウエポン画像サイズから分割し、引いた値にする
				//(ウエポンの画像をプレイヤーの頭上に配置するため)
				WEAPON_Y = p->Get_PLAYER_Y() - (WEAPON_Size_H / WEAPON_BUNKATU_Y);
		}
	}

	//DrawFormatString(0, 50, RGB(255, 255, 255), "PLAYER：%d", PLAYER_HP);

	////プレイヤーの体力が0以下なら
	//if (PLAYER_HP <= 0)
	//{
	//	for (int num = 0; num < ENEMY_NUM; num++)
	//	{
	//		//プレイヤーに触れたエネミーの位置や画像の添え字をリセットする
	//		e[num]->ENEMY_RESET();
	//	}
	//	screen_state = GAME_END;		//エンド画面へ遷移する
	//}
}



//エネミーのY位置を取得する関数
int ENEMY::Get_ENEMY_Y()
{
	/*if (fps->flameCount <= 10)
	{
		ENEMY_flag = true;
	}*/
	//if (ENEMY_flag == true)
	//{
		ENEMY_Y += Get_ENEMY_Speed();
	//}
	for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
	{
		if (e[e_num]->ENEMY_Y > GAME_HEIGHT)
		{
			e[e_num]->ENEMY_Y = GAME_MIN_HEIGHT - ENEMY_Size_H / ENEMY_BUNKATU_Y;
			e[e_num]->ENEMY_X = WINDOW_WIDTH_RANDOM_ENEMY_X();
			RANDOM_soeji = RANDOM();
			//ENEMY_flag = false;
		}
	}

	return ENEMY_Y;
}


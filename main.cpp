#include "DxLib.h"
#include "Keyboard_Get.h"
#include "PLAYER.h"
#include "ENEMY.h"
#include "WEAPON.h"
#include "SCORE.h"
#include "WINDOW_SIZE.h"
#include "FPS.h"
#include "DIFFICULTY_LEVEL.h"

#define GAME_BackImage_TITLE	"BackImage\\kaidou0331_800b.jpg"	//タイトル画面背景画像
#define GAME_TITLE_LOG			"BackImage\\game_title_font.png"	//タイトルロゴ
#define GAME_BackImage_PLAY		"BackImage\\背景_1.png"	//プレイ画面背景画像
#define GAME_BackImage_END		"BackImage\\GAME_OVER.jpg"				//エンド画面背景画像

#define GAME_FPS_SPEED		60			//FPSを設定

#define GAME_TITLE_LOG_UPPERLEFT_X		GAME_WIDTH / 4					//タイトルロゴ画像の左上X座標
#define GAME_TITLE_LOG_UPPERLEFT_Y		GAME_HEIGHT / 3					//タイトルロゴ画像の左上Y座標
#define GAME_TITLE_LOG_BOTTOMLEFT_X		GAME_WIDTH - GAME_WIDTH / 4		//タイトルロゴ画像の右下X座標
#define GAME_TITLE_LOG_BOTTOMLEFT_Y		GAME_HEIGHT - GAME_HEIGHT / 3	//タイトルロゴ画像の右下Y座標

#define LIMIT_TIME 60 //制限時間 
#define  PLAY_END_TIME 0 //終了時間

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
SCORE *s = new SCORE();			//スコアのオブジェクトを生成
DIFFICULTY *Difficulty_Level = new DIFFICULTY();

extern int PLAYER_Size;						//プレイヤー画像のサイズをLoadDivGrahpで取得するため(PLAYER.cppでも同じ変数を利用するため、externを使用している)
extern int PLAYER_Size_W, PLAYER_Size_H;	//プレイヤー画像の横サイズ、縦サイズを取得			(PLAYER.cppでも同じ変数を利用するため、externを使用している)
extern int ENEMY_Size;						//エネミー画像のサイズをLoadDivGrahpで取得するため	(ENEMY.cppでも同じ変数を利用するため、externを使用している)
extern int ENEMY_Size_W, ENEMY_Size_H;		//エネミー画像の横サイズ、縦サイズを取得			(ENEMY.cppでも同じ変数を利用するため、externを使用している)
extern int WEAPON_Size;						//ウエポン画像のサイズをLoadDivGrahpで取得するため	(ENEMY.cppでも同じ変数を利用するため、externを使用している)
extern int WEAPON_Size_W, WEAPON_Size_H;	//エネミー画像の横サイズ、縦サイズを取得			(ENEMY.cppでも同じ変数を利用するため、externを使用している)


int img_Back_Play_W, img_Back_Play_H;


int GAME_TITLE_ELAPSEDTIME; //プレイ画面に遷移するまでの時間を計測
int Get_Time = 0; //GetNowCount()用の変数：起動したら時間を計測する

//GetNowCount()は起動してから時間を計測するため、プレイ画面に遷移するまでの掛かった時間を引く必要がある
//GetNowCount() - timerstart = プレイ画面になったら時間を計測する

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
	
	//難易度変更用のフォントハンドルを作成
	int FontHandle_LV_SELECT = CreateFontToHandle(NULL, 70, 3);	//文字の大きさ変更

	//制限時間用のフォントハンドルを作成
	int FontHandle_LIMIT = CreateFontToHandle(NULL, 60, 3);	//文字の大きさ変更

	
	

	while (TRUE)	//無限ループ
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了

		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		Keyboard_Update();   //キーボードの更新

		fps->Update();		//FPSの処理[更新]

		//現在の時間を取得
		Get_Time = GetNowCount();

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


			DrawFormatStringToHandle(100, 400, GetColor(255, 0, 255), FontHandle_LV_SELECT, "難易度：%s", Difficulty_Level->Lv);

			Difficulty_Level->DIFFICULTY_LEVEL_TITLE();

			Difficulty_Level->DIFFICULTY_LEVEL_PLAY();

			s->SCORE_RESET();

			break;

		case GAME_PLAY: 

			//////////////////////スクロール処理/////////////////
			//プレイ画面の背景画像を描画する(１枚目)
			DrawExtendGraph(img_Back_Play_W, img_Back_Play_H, GAME_WIDTH, GAME_HEIGHT + img_Back_Play_H, imgBack_Play, false);

			//プレイ画面の背景画像を描画する(２枚目スクロール用)
			DrawExtendGraph(img_Back_Play_W, img_Back_Play_H - GAME_HEIGHT, GAME_WIDTH, img_Back_Play_H, imgBack_Play, false);

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




			for (int w_cnt = 0, e_num = 0; w_cnt < WEAPON_NUM, e_num < ENEMY_NUM; w_cnt++, e_num++)
			{
				p->PLAYER_COLLISION_ENEMY(e[e_num]->ENEMY_X, e[e_num]->ENEMY_Y);	//プレイヤーとエネミーの衝突判定
				w[w_cnt]->WEAPON_COLLISION_ENEMY(e[e_num]->ENEMY_X, e[e_num]->ENEMY_Y);	//ウエポンとエネミーの衝突判定

				e[e_num]->ENEMY_DRAW();		//エネミーの描画処理
				w[w_cnt]->WEAPON_DRAW();	//ウエポンの描画処理
			}


			p->PLAYER_DRAW();	//プレイヤーの描画処理


			//DrawFormatStringF(0,500, RGB(255, 255, 255), "ENEMY_X:%d", e[num]->ENEMY_X);

			//for (int num = 0; num < ENEMY_NUM; num++)
			//{
			//	p->PLAYER_COLLISION_ENEMY(e[num]->ENEMY_X, e[num]->ENEMY_Y);	//プレイヤーとエネミーの衝突判定
			//	w->WEAPON_COLLISION_ENEMY(e[num]->ENEMY_X, e[num]->ENEMY_Y);
			//	
			//	e[num]->ENEMY_DRAW();		//エネミーの描画処理
			//}
			DrawFormatStringF(0, 200, RGB(255, 255, 255), "ENEMY_X[1]:%d", e[0]->ENEMY_X);
			DrawFormatStringF(0, 350, RGB(255, 255, 255), "ENEMY_X[2]:%d", e[1]->ENEMY_X);
			DrawFormatStringF(0, 500, RGB(255, 255, 255), "ENEMY_X[3]:%d", e[2]->ENEMY_X);
			DrawFormatStringF(0, 400, RGB(255, 255, 255), "WEAPON_Y[w_cnt]:%d", w[2]->WEAPON_Y);
			//w->WEAPON_DRAW();
			s->DRAW_TOTAL_SCORE();


			//制限時間の設定
			DrawFormatStringToHandle(500, 0, GetColor(255, 255, 255), FontHandle_LIMIT, "LIMIT_TIME：%d秒", (LIMIT_TIME - (Get_Time - GAME_TITLE_ELAPSEDTIME) / 1000));	//文字の大きさ変更);

			//制限時間が0秒になったら
			if (LIMIT_TIME - (Get_Time - GAME_TITLE_ELAPSEDTIME) / 1000 <= PLAY_END_TIME)
			{
				screen_state = GAME_END;
			}

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
		GAME_TITLE_ELAPSEDTIME = Get_Time;			//プレイ画面へ遷移するとき、タイトル画面でかかった時間を変数に入れる
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
			p->PLAYER_HP -= 1;
		}
	}

	DrawFormatString(0, 50, RGB(255, 255, 255), "PLAYER：%d", p->PLAYER_HP);

	//プレイヤーの体力が0以下なら
	if (p->PLAYER_HP <= 0)
	{
		for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
		{
			//プレイヤーに触れたエネミーの位置や画像の添え字をリセットする
			e[e_num]->ENEMY_RESET();
		}
		screen_state = GAME_END;		//エンド画面へ遷移する
	}
}

//ウエポンのX位置を取得
int WEAPON::Get_WEAPON_X()
{
	if (Keyboard_Get(KEY_INPUT_A) >= 1)
	{
		WEAPON_flag_X = true;		//A	キーを押したとき、プレイヤーのX座標を取得するためのフラグ
	}

	if (WEAPON_flag_X == false)
	{
		WEAPON_X = p->PLAYER_X;
	}
	return WEAPON_X;
};

//ウエポンのY位置を取得する関数
int WEAPON::Get_WEAPON_Y()
{
		
		//WEAPON_Y = Get_PLAYER_Y() - WEAPON_Size_H / WEAPON_BUNKATU_Y;
		//ウエポンを操作する　A　キーを押した場合
		if (Keyboard_Get(KEY_INPUT_A) >= 1)
		{
			WEAPON_flag_Y = true;		//A キーを押したとき、自動でY座標を加算するためのフラグ

			//for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
			//{
			//	w[w_cnt]->WEAPON_flag_X = true;		//A	キーを押したとき、プレイヤーのX座標を取得するためのフラグ
			//	w[w_cnt]->WEAPON_flag_Y = true;		//A キーを押したとき、自動でY座標を加算するためのフラグ
			//}
		}

		if (WEAPON_flag_X == false)
		{
			WEAPON_Y = p->PLAYER_Y;
		}

		//A キーを押したとき、自動でY座標を加算するためのフラグ
		if (WEAPON_flag_Y == true)
		{
			WEAPON_Y -= Get_WEAPON_Speed(WEAPON_Speed);
		}

		for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
		{	
			if (w[w_cnt]->WEAPON_flag_X == true && w[w_cnt]->WEAPON_Y == p->PLAYER_Y)// - (WEAPON_Size_H / WEAPON_BUNKATU_Y))
			{
				//ウエポンのX座標をプレイヤーのX座標と同じ値にする
				w[w_cnt]->WEAPON_X = p->PLAYER_X;


				w[w_cnt]->WEAPON_flag_X = false;
			}

			//ウエポンのYフラグが(Aキーを押した)trueかつ、ウエポンのY座標が(0以上)画面内なら
			if (w[w_cnt]->WEAPON_flag_Y == true && w[w_cnt]->WEAPON_Y >= GAME_MIN_HEIGHT)
			{
				//windowの左端まで移動する	
				//w[w_cnt]->WEAPON_Y -= w[w_cnt]->Get_WEAPON_Speed(WEAPON_Speed);
			
			}

			//ウエポン画像のY座標が画面外(0よりも低い値)に到達したとき
			if (w[w_cnt]->WEAPON_Y < GAME_MIN_HEIGHT)
			{
				//ウエポンのY座標をプレイヤーのY座標から、ウエポン画像サイズから分割し、引いた値にする
				//(ウエポンの画像をプレイヤーの頭上に配置するため)
				if (w[w_cnt]->WEAPON_flag_Y == true)
				{
					//w[w_cnt]->WEAPON_Y = p->PLAYER_Y - (WEAPON_Size_H / WEAPON_BUNKATU_Y);
					w[w_cnt]->WEAPON_Y = p->PLAYER_Y;
					w[w_cnt]->WEAPON_X = p->PLAYER_X;

					w[w_cnt]->WEAPON_flag_Y = false;
				}
			}
		}
	return WEAPON_Y;
};


//ウエポンとエネミーの衝突判定
void WEAPON::WEAPON_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y)
{
		for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
		{
			for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
			{
				//キャラとエネミーの当たり判定
				if (((w[w_cnt]->WEAPON_X > e[e_num]->ENEMY_X && w[w_cnt]->WEAPON_X < e[e_num]->ENEMY_X + ENEMY_Size_W / ENEMY_BUNKATU_X) ||
					(e[e_num]->ENEMY_X > w[w_cnt]->WEAPON_X && e[e_num]->ENEMY_X < w[w_cnt]->WEAPON_X + WEAPON_Size_W / WEAPON_BUNKATU_X)) &&
					((w[w_cnt]->WEAPON_Y > e[e_num]->ENEMY_Y && w[w_cnt]->WEAPON_Y < e[e_num]->ENEMY_Y + ENEMY_Size_H / ENEMY_BUNKATU_Y) ||
					(e[e_num]->ENEMY_Y > w[w_cnt]->WEAPON_Y && e[e_num]->ENEMY_Y < w[w_cnt]->WEAPON_Y + WEAPON_Size_H / WEAPON_BUNKATU_Y)))
				{
					//ウエポンに触れたエネミーの位置や画像の添え字をリセットする
					e[e_num]->ENEMY_RESET();

					w[w_cnt]->WEAPON_flag_X = false;		//A	キーを押したとき、プレイヤーのX座標を取得するためのフラグ
					w[w_cnt]->WEAPON_flag_Y = false;		//A キーを押したとき、自動でY座標を加算するためのフラグ

					//ウエポンのY座標をプレイヤーのY座標から、ウエポン画像サイズから分割し、引いた値にする
					//(ウエポンの画像をプレイヤーの頭上に配置するため)
					//w[w_cnt]->WEAPON_Y = p->Get_PLAYER_Y() - (WEAPON_Size_H / WEAPON_BUNKATU_Y);
					w[w_cnt]->WEAPON_Y = p->Get_PLAYER_Y();
					s->TOTAL_SCORE();


				}
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


//タイトル画面で難易度を変更したら、各難易度に応じて残機やエネミーの数を調整する関数
void DIFFICULTY::DIFFICULTY_LEVEL_PLAY()
{
	//Easy　残機3
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1 && Lv_Select == 0)
	{
		p->PLAYER_HP = 3;
		screen_state = GAME_PLAY;	//シーンをゲーム画面に変更
	}

	//Normal　残機2
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1 && Lv_Select == 1)
	{
		p->PLAYER_HP = 2;
		screen_state = GAME_PLAY;	//シーンをゲーム画面に変更
	}

	//Hard　残機1
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1 && Lv_Select == 2)
	{
		p->PLAYER_HP = 1;
		screen_state = GAME_PLAY;	//シーンをゲーム画面に変更
	}
}


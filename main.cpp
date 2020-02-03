//*******************インクルード*************
#include "DxLib.h"
#include "Keyboard_Get.h"
#include "PLAYER.h"
#include "ENEMY.h"
#include "WEAPON.h"
#include "SCORE.h"
#include "WINDOW_SIZE.h"
#include "FPS.h"
#include "DIFFICULTY_LEVEL.h"
#include "Background_Scroll.h"
#include "BGM.h"
//******************************************

//***********************マクロ定義******************************************************************
#define GAME_BackImage_TITLE	"BackImage\\背景.png"//"BackImage\\kaidou0331_800b.jpg"	//タイトル画面背景画像
#define GAME_TITLE_LOG			"BackImage\\game_title_font.png"	//タイトルロゴ
#define GAME_BackImage_PLAY		"BackImage\\背景.png"				//プレイ画面背景画像
#define GAME_BackImage_CLEAR	"BackImage\\GAME_CLEAR.jpg"			//クリア画面背景画像
#define GAME_BackImage_END		"BackImage\\GAME_OVER_2.jpg"			//エンド画面背景画像

#define GAME_FPS_SPEED		60			//FPSを設定

#define GAME_TITLE_LOG_UPPERLEFT_X		GAME_WIDTH / 4					//タイトルロゴ画像の左上X座標
#define GAME_TITLE_LOG_UPPERLEFT_Y		GAME_HEIGHT / 3					//タイトルロゴ画像の左上Y座標
#define GAME_TITLE_LOG_BOTTOMLEFT_X		GAME_WIDTH - GAME_WIDTH / 4		//タイトルロゴ画像の右下X座標
#define GAME_TITLE_LOG_BOTTOMLEFT_Y		GAME_HEIGHT - GAME_HEIGHT / 3	//タイトルロゴ画像の右下Y座標

#define LIMIT_TIME 60 //制限時間 
#define PLAY_END_TIME 0 //終了時間

#define PLAY_MUSIC "MUSIC\\crying again.mp3"		//ミュージックを取り込む
#define COLISION_MUSIC "MUSIC\\colision.mp3"		//ミュージックを取り込む
//*****************************************************************************************************

//****************列挙型************:
//各画面を設定
enum GAME_SCREEN
{
	GAME_TITLE,	//タイトル画面
	GAME_PLAY,	//プレイ画面
	GAME_CLEAR,	//クリア画面
	GAME_END	//エンド画面
};
//****************************************

//ゲーム画面の遷移を管理する
GAME_SCREEN screen_state = GAME_TITLE;	//画面遷移をコントロールする(最初の画面はタイトル画面)

//*************************************プロトタイプ宣言******************************
void GAME_TITLE_DRAW();		//タイトル画面を描画
void GAME_PLAY_DRAW();		//プレイ画面を描画
void GAME_CLEAR_DRAW();		//クリア画面を描画
void GAME_END_DRAW();		//エンド画面を描画
//*************************************************************************************

//*****************クラス*********************************************
FPS *fps = new FPS(GAME_FPS_SPEED);		//FPSクラスのオブジェクトを生成
PLAYER *p = new PLAYER();				//プレイヤーのオブジェクトを生成する
//WEAPON *w = new WEAPON();				//ウエポンのオブジェクトを生成する
WEAPON *w[WEAPON_NUM];					//ウエポンクラスを５つ生成する
ENEMY *e[ENEMY_NUM];					//エネミークラスを３つ生成する
SCORE *s = new SCORE();					//スコアのオブジェクトを生成
DIFFICULTY *Difficulty_Level = new DIFFICULTY();		//難易度変更を設定するクラスを生成する
CLEARCONDITION *ClearCondition_Level = new CLEARCONDITION();
BACKGROUND *Background = new BACKGROUND();
BGM *bgm = new BGM();
//********************************************************************

//************************画像のサイズを取得する変数**************************************
extern int PLAYER_Size;						//プレイヤー画像のサイズをLoadDivGrahpで取得するため(PLAYER.cppでも同じ変数を利用するため、externを使用している)
extern int PLAYER_Size_W, PLAYER_Size_H;	//プレイヤー画像の横サイズ、縦サイズを取得			(PLAYER.cppでも同じ変数を利用するため、externを使用している)
extern int ENEMY_Size;						//エネミー画像のサイズをLoadDivGrahpで取得するため	(ENEMY.cppでも同じ変数を利用するため、externを使用している)
extern int ENEMY_Size_W, ENEMY_Size_H;		//エネミー画像の横サイズ、縦サイズを取得			(ENEMY.cppでも同じ変数を利用するため、externを使用している)
extern int WEAPON_Size;						//ウエポン画像のサイズをLoadDivGrahpで取得するため	(ENEMY.cppでも同じ変数を利用するため、externを使用している)
extern int WEAPON_Size_W, WEAPON_Size_H;	//エネミー画像の横サイズ、縦サイズを取得			(ENEMY.cppでも同じ変数を利用するため、externを使用している)

extern int ENEMY_ANIMATION_Size;						//エネミー画像のサイズをLoadDivGrahpで取得するため	(ENEMY.cppでも同じ変数を利用するため、externを使用している)
extern int ENEMY_ANIMATION_Size_W, ENEMY_ANIMATION_Size_H;		//エネミー画像の横サイズ、縦サイズを取得	(ENEMY.cppでも同じ変数を利用するため、externを使用している)

//*******************************************************************************************


//**********************背景画像をロードする変数**************************
int imgBack_Title = 0;
int imgTitle_log = 0;
int imgBack_End = 0;
int imgBack_Clear = 0;
//************************************************************************


//**********************時間を取得する変数**************************
double GAME_TITLE_ELAPSEDTIME = 0; //プレイ画面に遷移するまでの時間を計測
int Get_WEAPON_Time;
double Get_Collision_Time;		//エネミーがウエポンにあたった時間を取得する
double Get_Time = 0;			//GetNowCount()用の変数：起動したら時間を計測する

//GetNowCount()は起動してから時間を計測するため、プレイ画面に遷移するまでの掛かった時間を引く必要がある
//GetNowCount() - timerstart = プレイ画面になったら時間を計測する

//***************文字を描画する変数*****************
int FontHandle_LIMIT = 0;
int FontHandle_ScreenTransition = 0;
//**************************************************

int count = 0;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);		// ウィンドウモードに設定(TRUE: FALSE:フルスクリーン)
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//指定の数値で画面を表示する
	
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);			//描画を裏画面に設定

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

	//プレイヤー画像の縦と横のサイズを取得するためロードする(すぐに捨てる)
	ENEMY_Size = LoadGraph(GAME_ENEMY);	

	//プレイヤー画像の縦と横のサイズを取得
	GetGraphSize(ENEMY_Size, &ENEMY_Size_W, &ENEMY_Size_H);	

	//プレイヤー画像の縦と横のサイズを取得したら、使い捨て
	DeleteGraph(ENEMY_Size);

	//エネミーの爆発アニメーション用画像の縦と横のサイズを取得するためロードする（すぐに捨てる）
	ENEMY_ANIMATION_Size = LoadGraph(ENEMY_EXPROSION_ANIMATION);

	//エネミーの爆発アニメーション用画像の縦と横のサイズを取得
	GetGraphSize(ENEMY_ANIMATION_Size, &ENEMY_ANIMATION_Size_W, &ENEMY_ANIMATION_Size_H);

	//エネミーの爆発アニメーション用画像の縦と横のサイズを取得したら、使い捨て
	DeleteGraph(ENEMY_ANIMATION_Size);


	for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
	{
		//配列の個数分エネミークラスを生成する
		e[e_num] = new ENEMY();
		//エネミー画像を配列の個数分、指定した分割数、サイズで読み込む
		LoadDivGraph(GAME_ENEMY, ENEMY_BUNKATU, ENEMY_BUNKATU_X, ENEMY_BUNKATU_Y, ENEMY_Size_W / ENEMY_BUNKATU_X, ENEMY_Size_H / ENEMY_BUNKATU_Y, &e[e_num]->ENEMY_Handle[0]);

		//爆発アニメーションの画像を配列の個数分、指定した分割数、サイズで読み込む
		LoadDivGraph(ENEMY_EXPROSION_ANIMATION, ENEMY_ANIMATION_BUNKATU, ENEMY_ANIMATION_BUNKATU_X, ENEMY_ANIMATION_BUNKATU_Y, ENEMY_ANIMATION_Size_W / ENEMY_ANIMATION_BUNKATU_X, ENEMY_ANIMATION_Size_H / ENEMY_ANIMATION_BUNKATU_Y, &e[e_num]->ENEMY_ANIMATION_Handle[0]);
	}
	//int ENEMY_BUNKATU_SIZE_X = 0,  ENEMY_BUNKATU_SIZE_Y= 0, ANIMATION_BUNKATU_SIZE_X = 0, ANIMATION_BUNKATU_SIZE_Y = 0;

	//GetGraphSize(e[0]->ENEMY_Handle[0], &ENEMY_BUNKATU_SIZE_X, &ENEMY_BUNKATU_SIZE_Y);	//プレイヤー画像の縦と横のサイズを取得

	//GetGraphSize(e[0]->ENEMY_ANIMATION_Handle[0], &ANIMATION_BUNKATU_SIZE_X, &ANIMATION_BUNKATU_SIZE_Y);	//プレイヤー画像の縦と横のサイズを取得

	//タイトル画面の背景の画像を読み込む
	imgBack_Title = LoadGraph(GAME_BackImage_TITLE);		//タイトル背景画像を読み込む(*注意：while文で読み込むとFPSが低下する[毎回読み込んでしまうため])
	//タイトルロゴの画像を読み込む
	imgTitle_log = LoadGraph(GAME_TITLE_LOG);				//タイトルロゴ画像を読み込む(*注意：while文で読み込むとFPSが低下する[毎回読み込んでしまうため])
	
	//プレイ画面の背景画像を読み込む
	Background->imgBack_Scroll = LoadGraph(GAME_BackImage_PLAY);			//プレイ背景画像を読み込む(*注意：while文で読み込むとFPSが低下する[毎回読み込んでしまうため])

	//クリア画面の背景画像を読み込む
	imgBack_Clear = LoadGraph(GAME_BackImage_CLEAR);		//クリア背景画像を読み込む(*注意：while文で読み込むとFPSが低下する[毎回読み込んでしまうため])

	//エンド画面の背景画像を読み込む
	imgBack_End = LoadGraph(GAME_BackImage_END);			//エンド背景画像を読み込む(*注意：while文で読み込むとFPSが低下する[毎回読み込んでしまうため])
	
	//画面遷移を案内するフォントハンドルを作成
	FontHandle_ScreenTransition = CreateFontToHandle(NULL, 50, 5);		//文字の大きさ変更

	//プレイヤーのHPを描画するフォントハンドルを作成
	p->FontHandle_PLAYER_HP = CreateFontToHandle(NULL, 50, 5);		//文字の大きさ変更

	//難易度変更用のフォントハンドルを作成
	Difficulty_Level->FontHandle_LV_SELECT = CreateFontToHandle(NULL, 50, 3);	//文字の大きさ変更

	//クリア条件変更用のフォントハンドルを作成
	ClearCondition_Level->FontHandle_ClearCondition_SELECT = CreateFontToHandle(NULL, 40, 3);	//文字の大きさ変更

	//制限時間用のフォントハンドルを作成
	FontHandle_LIMIT = CreateFontToHandle(NULL, 60, 3);		//文字の大きさ変更

	//獲得スコア描画用のフォントハンドルを作成
	s->FontHandle_SCORE = CreateFontToHandle(NULL, 50, 3); //文字の大きさ変更

	//FPS描画用のフォントハンドルを作成
	fps->FontHandle_FPS = CreateFontToHandle(NULL, 50, 3); //文字の大きさ変更

	//マクロで定義した音楽ファイルをロードし、識別番号をMUSIC_Handleに格納する
	bgm->MUSIC_Handle = LoadSoundMem(PLAY_MUSIC);

	//マクロで定義した音楽ファイルをロードし、識別番号をMUSIC_COLISION_Handleに格納する
	bgm->MUSIC_COLISION_Handle = LoadSoundMem(COLISION_MUSIC);

	//無限ループ
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了

		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		Keyboard_Update();  //キーボードの更新

		fps->Update();		//FPSの処理[更新]

		//現在の時間を取得
		Get_Time = GetNowCount();

		//ウィンドウのシーン状態
		switch (screen_state)
		{
		case GAME_TITLE:		//ゲームタイトル画面

			bgm->PLAY_VOLUME_BGM();

			GAME_TITLE_DRAW();	//タイトル画面を描画

			p->PLAYER_RESET();	//プレイヤーを初期位置へ

			//w->WEAPON_RESET();	//ウエポンを初期位置へ
			for (int e_num = 0, w_cnt = 0; e_num < ENEMY_NUM, w_cnt < WEAPON_NUM; e_num++, w_cnt++)
			{
				e[e_num]->ENEMY_RESET();
				w[w_cnt]->WEAPON_RESET();	//ウエポンを初期位置へ
			}

			s->SCORE_RESET();		//スコアのリセットする関数

			break;

		case GAME_PLAY:				//ゲームプレイ画面

			GAME_PLAY_DRAW();	//プレイ画面を描画

			count++;
			//ウエポンとエネミーを複数生成する
			for (int w_cnt = 0, e_num = 0; e_num < ENEMY_NUM; w_cnt++, e_num++)
			{
				p->PLAYER_COLLISION_ENEMY(e[e_num]->ENEMY_X, e[e_num]->ENEMY_Y);		//プレイヤーとエネミーの衝突判定
				w[w_cnt]->WEAPON_COLLISION_ENEMY(e[e_num]->ENEMY_X, e[e_num]->ENEMY_Y);	//ウエポンとエネミーの衝突判定

				e[e_num]->ENEMY_ANIMATION_COUNT++;
				e[e_num]->RANDOM_soeji = e[e_num]->ENEMY_RANDOM_soeji_Evacuation + (e[e_num]->ENEMY_ANIMATION_COUNT / ENEMY_ANIMATION_FRAME) % ENEMY_ANIMATION_PATTERN;

				//爆発フラグがtureのとき
				if (e[e_num]->ENEMY_EXPROSION_flag == true)
				{
					if (ENEMY_HIT_TIME - (Get_Time - Get_Collision_Time) / 1000 <= PLAY_END_TIME)
					{
						e[e_num]->ENEMY_EXPROSION_flag = false;
					}
					//エネミーのアニメーション用カウント
					e[e_num]->ENEMY_ANIMATION_COUNT++;
					//爆発アニメーション
					e[e_num]->ENEMY_ANIMATION_soeji = (e[e_num]->ENEMY_ANIMATION_COUNT / ENEMY_ANIMATION_EXPROSION_FRAME) % ENEMY_ANIMATION_EXPROSION_PATTERN;
					//爆発アニメーション
					e[e_num]->ENEMY_ANIMATION_DRAW((ENEMY_ANIMATION_Size_W / ENEMY_ANIMATION_BUNKATU_X / 2) - (ENEMY_Size_W / ENEMY_BUNKATU_X / 2), (ENEMY_ANIMATION_Size_H / ENEMY_ANIMATION_BUNKATU_Y / 2) - (ENEMY_Size_H / ENEMY_BUNKATU_Y / 2));
					
				}
				/*if (e[e_num]->ENEMY_COUNT >= 60)
				{
					e[e_num]->ENEMY_COUNT = 0;
				}*/
				e[e_num]->ENEMY_DRAW();		//エネミーの描画処理
				//e[e_num]->ENEMY_ANIMATION_DRAW((ANIMATION_BUNKATU_SIZE_X / 2) - (ENEMY_BUNKATU_SIZE_X / 2), (ANIMATION_BUNKATU_SIZE_Y / 2) - (ENEMY_BUNKATU_SIZE_Y / 2));
				
				//爆弾アニメーション用カウント
				w[w_cnt]->WEAPON_ANIMATION_COUNT++;

				//爆弾アニメーション処理
				w[w_cnt]->WEAPON_soeji = (w[w_cnt]->WEAPON_ANIMATION_COUNT / WEAPON_ANIMATION_EXPROSION_FRAME) % WEAPON_ANIMATION_PATTERN;

				//ウエポンの描画処理
				w[w_cnt]->WEAPON_DRAW((WEAPON_Size_W / WEAPON_BUNKATU_X / 2) - (PLAYER_Size_W / PLAYER_BUNKATU_X / 2), (WEAPON_Size_H / WEAPON_BUNKATU_Y / 2) - (PLAYER_Size_H / PLAYER_BUNKATU_Y / 2));
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
			/*DrawFormatStringF(0, 200, RGB(255, 255, 255), "ENEMY_X[1]:%d", e[0]->ENEMY_X);
			DrawFormatStringF(0, 350, RGB(255, 255, 255), "ENEMY_X[2]:%d", e[1]->ENEMY_X);
			DrawFormatStringF(0, 500, RGB(255, 255, 255), "ENEMY_X[3]:%d", e[2]->ENEMY_X);
			DrawFormatStringF(0, 400, RGB(255, 255, 255), "WEAPON_Y[w_cnt]:%d", w[2]->WEAPON_Y);*/
			//w->WEAPON_DRAW();

			//トータルスコアを描画
			s->DRAW_TOTAL_SCORE();

			//制限時間の設定
			DrawFormatStringToHandle(400, 0, GetColor(150, 255, 255), FontHandle_LIMIT, "LIMIT_TIME：%0.3lf秒", (LIMIT_TIME - (Get_Time - GAME_TITLE_ELAPSEDTIME) / 1000));	//文字の大きさ変更);

			//DrawFormatStringToHandle(100, 0, GetColor(150, 255, 255), FontHandle_LIMIT, "LIMIT_TIME：%d秒", (Get_Time - GAME_TITLE_ELAPSEDTIME) / 1000);	//文字の大きさ変更);

			//クリア条件の変更
			DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, ClearCondition_Level->TimeMode_Play_flag, false);

			break;

		case GAME_CLEAR:		//ゲームクリア画面
			GAME_CLEAR_DRAW();
			s->DRAW_TOTAL_SCORE();	//トータルスコアを描画
			break;
		
		case GAME_END:			//ゲームエンド画面
			GAME_END_DRAW();	//エンド画面を描画
			s->DRAW_TOTAL_SCORE();	//トータルスコアを描画
			break;

		default:
			break;
		}
		fps->Draw(0, 50);	//FPSの処理[描画]

		ScreenFlip();		//モニタのリフレッシュレートの速さで裏画面を再描画

		fps->Wait();		//FPSの処理[待つ]
		
	}

	delete fps;		//fpsクラスの解放
	delete p;		//PLAYERクラスの解放
	delete s;		//スコアクラスの解放
	delete Difficulty_Level;		//難易度変更クラスの解放
	delete ClearCondition_Level;	//クラス条件変更クラスの解放
	delete Background;				//スクロールする背景画像クラスの解放
	for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
	{
		delete w[w_cnt];		//WEAPONクラスの解放
	}
	for (int e_num = 0; e_num < ENEMY_NUM; e_num++)
	{
		delete e[e_num];		//ENEMYクラスの解放
	}
	DxLib_End();				//ＤＸライブラリ使用の終了処理

	return 0;					// ソフトの終了 
}

//タイトル画面を描画する関数
void GAME_TITLE_DRAW() 
{
	//タイトル画像の背景画像を描画する
	//DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, imgBack_Title, false);

	//スクロールする背景画像を描画する関数
	Background->Background_Scroll_Draw();
	
	//背景をスクロールする関数
	Background->Background_Scroll();

	//タイトルロゴの画像を描画する
	DrawExtendGraph(GAME_TITLE_LOG_UPPERLEFT_X, GAME_TITLE_LOG_UPPERLEFT_Y, GAME_TITLE_LOG_BOTTOMLEFT_X, GAME_TITLE_LOG_BOTTOMLEFT_Y, imgTitle_log, true);

	//エンター画面へ遷移する条件を描画
	DrawStringToHandle(0, 0, "タイトル　エンターでプレイ画面へ", RGB(255, 255, 255), FontHandle_ScreenTransition);

	//難易度変更を描画する関数
	Difficulty_Level->DIFFICULTY_LEVEL_SELECT_DRAW();

	//クリア条件変更を描画する関数
	ClearCondition_Level->CLEAR_CONDITION_SELECT_DRAW();

	//タイトル画面でクリア条件を変更し、値を保持する関数
	ClearCondition_Level->CLEAR_CONDITION_SELECT_TITLE();

	//タイトル画面でEasy,Normal,Hardを変更した値を基に難易度変更を実施する関数
	ClearCondition_Level->CLEAR_CONDITION_SELECT_PLAY();

	//タイトル画面でEasy,Normal,Hardを変更し、値を保持する関数
	Difficulty_Level->DIFFICULTY_LEVEL_TITLE();	

	//タイトル画面でEasy,Normal,Hardを変更した値を基に難易度変更を実施する関数
	Difficulty_Level->DIFFICULTY_LEVEL_PLAY();	

	//プレイ画面で音楽を鳴らす関数
	bgm->PLAY_BGM();

	//エンターキーが押されたら
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1)
	{
		//プレイ画面へ遷移する
		screen_state = GAME_PLAY;

		//プレイ画面へ遷移するとき、タイトル画面でかかった時間を変数に入れる
		GAME_TITLE_ELAPSEDTIME = Get_Time;
	}	
}

//プレイ画面を描画する関数
void GAME_PLAY_DRAW()
{
	//スクロールする背景画像を描画する関数
	Background->Background_Scroll_Draw();

	//背景をスクロールする関数
	Background->Background_Scroll();

	//エンド画面へ遷移する条件を描画
	//DrawStringToHandle(0, 0, "プレイ スペースでエンド画面へ", RGB(255, 255, 255), FontHandle_ScreenTransition);

	//プレイヤーのHPを描画する関数
	p->PLAYER_HP_DRAW();

	//制限時間が0秒になったら(スコアモードのとき)
	if (LIMIT_TIME - (Get_Time - GAME_TITLE_ELAPSEDTIME) / 1000 <= PLAY_END_TIME && ClearCondition_Level->ScoreMode_Play_flag == true)
	{
		screen_state = GAME_END;	//エンド画面へ遷移する
	}

	//制限時間が0秒になったら(タイムモードのとき)
	if (LIMIT_TIME - (Get_Time - GAME_TITLE_ELAPSEDTIME) / 1000 <= PLAY_END_TIME && ClearCondition_Level->TimeMode_Play_flag == true)
	{
		screen_state = GAME_CLEAR;	//クリア画面へ遷移する
	}

	//スペースキーが押されたら
	if (Keyboard_Get(KEY_INPUT_SPACE) == 1)
	{
		screen_state = GAME_END;		//エンド画面へ遷移する
	}

	//トータルスコア
	if (s->total_score >= GAME_CLEAR_SCORE)
	{
		screen_state = GAME_CLEAR;		//エンド画面へ遷移する
	}
}

//クリア画面を描画する関数
void GAME_CLEAR_DRAW() 
{
	//クリア画面用の背景を描画
	DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, imgBack_Clear, false);

	DrawStringToHandle(0, 0, "クリア　バックスペースでタイトル画面へ", RGB(0, 0, 255), FontHandle_ScreenTransition);

	//バックスペースキーが押されたら
	if (Keyboard_Get(KEY_INPUT_BACK) == 1)
	{
		screen_state = GAME_TITLE;		//タイトル画面へ遷移する
	}

	DrawStringToHandle(0, 550, "クリア　エスケープキーでゲーム終了", RGB(0, 255, 255), FontHandle_ScreenTransition);

	//エスケープキーが押されたら
	if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1)
	{
		DxLib_End();					//ゲーム終了
	}

	//獲得したスコアを描画する関数
	s->DRAW_TOTAL_SCORE();
}

//エンド画面を描画する関数
void GAME_END_DRAW()
{

	//エンド画面の背景画像を描画する
	DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, imgBack_End, false);

	DrawStringToHandle(0, 0, "エンド　バックスペースでタイトル画面へ", RGB(0, 0, 255), FontHandle_ScreenTransition);

	//バックスペースキーが押されたら
	if (Keyboard_Get(KEY_INPUT_BACK) == 1)
	{
		screen_state = GAME_TITLE;		//タイトル画面へ遷移する
	}

	DrawStringToHandle(0, 550, "エンド　エスケープキーでゲーム終了", RGB(0, 255, 255), FontHandle_ScreenTransition);

	//エスケープキーが押されたら
	if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1)
	{
		DxLib_End();					//ゲーム終了
	}

	//獲得したスコアを描画する関数
	s->DRAW_TOTAL_SCORE();
}

//プレイヤーとエネミーの衝突判定
void PLAYER::PLAYER_COLLISION_ENEMY(int ENEMY_X, int ENEMY_Y)
{
	//エネミーの数に応じて繰り返す
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

	//DrawFormatString(0, 50, RGB(255, 255, 255), "PLAYER：%d", p->PLAYER_HP);	//プレイヤーの体力を描画する

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
	//Aキーを押したとき
	if (Keyboard_Get(KEY_INPUT_A) >= 1)
	{
		for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
		{
			w[w_cnt]->WEAPON_flag_X = true;		//A	キーを押したとき、ウエポンのXフラグをtrueにする (ウエポンのX座標をプレイヤーのX座標と同じにする)
		}
	}

	
	for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
	{
		if (w[w_cnt]->WEAPON_flag_X == false)
		{
			w[w_cnt]->WEAPON_X = p->PLAYER_X;		//ウエポンのXフラグがfalseのとき、ウエポンのX座標をプレイヤーのX座標と同じにする
		}
	}

	return WEAPON_X;
}

//ウエポンのY位置を取得する関数
int WEAPON::Get_WEAPON_Y()
{
		//WEAPON_Y = Get_PLAYER_Y() - WEAPON_Size_H / WEAPON_BUNKATU_Y;
	
		//A キーを押したとき、自動でY座標を加算するためのフラグ
	
		
	//ウエポンを操作する　A　キーを押した場合
	if (Keyboard_Get(KEY_INPUT_A) >= 1 && count % 30 == 0) //)
	{
		for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
		{
			//if (w[w_cnt]->WEAPON_flag_Y == false)
			//{
				//if (0.5 - (Get_Time - Get_WEAPON_Time) / 1000 == PLAY_END_TIME)
				//{ 
					w[w_cnt]->WEAPON_flag_X = true;		//A	キーを押したとき、プレイヤーのX座標を取得するためのフラグ
					w[w_cnt]->WEAPON_flag_Y = true;		//A キーを押したとき、自動でY座標を加算するためのフラグ
					/*w[w_cnt]->WEAPON_X = p->PLAYER_X;
					w[w_cnt]->WEAPON_Y = p->PLAYER_Y;*/

					//w[w_cnt]->WEAPON_Next_flag = true;
					//Get_WEAPON_Time = Get_Time;
				//}
			//}
		}
	}

	//A キーを押したとき、自動でY座標を加算するためのフラグ
	//if (w[0]->WEAPON_flag_Y == true)
	//{
	//	WEAPON_Y -= 5;//w[0]->Get_WEAPON_Speed(WEAPON_Speed);
	//}

	/*if (w[1]->WEAPON_flag_Y == true)
	{
		w[1]->WEAPON_Y -= w[1]->Get_WEAPON_Speed(WEAPON_Speed);
	}

	if (w[2]->WEAPON_flag_Y == true)
	{
		w[2]->WEAPON_Y -= w[2]->Get_WEAPON_Speed(WEAPON_Speed);
	}*/


	for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
	{
		if (w[w_cnt]->WEAPON_flag_Y == false)
		{
			w[w_cnt]->WEAPON_Y = p->PLAYER_Y;		//ウエポンのYフラグがfalseのとき、ウエポンのY座標をプレイヤーのY座標と同じにする
		}
		
		//A キーを押したとき、自動でY座標を加算するためのフラグ
		if (w[w_cnt]->WEAPON_flag_Y == true)
		{
			WEAPON_Y -= w[w_cnt]->Get_WEAPON_Speed(WEAPON_Speed);
		}
		
		if (w[w_cnt]->WEAPON_flag_X == true && w[w_cnt]->WEAPON_Y == p->PLAYER_Y)// - (WEAPON_Size_H / WEAPON_BUNKATU_Y))
		{
			//ウエポンのX座標をプレイヤーのX座標と同じ値にする
			w[w_cnt]->WEAPON_X = p->PLAYER_X;

			///ウエポンのXフラグをfalseに変更する
			w[w_cnt]->WEAPON_flag_X = false;
		}

		//ウエポン画像のY座標が画面外(0よりも低い値)に到達したとき //描画処理でずらしたY座標を調整
		if (w[w_cnt]->WEAPON_Y + (PLAYER_Size_H / PLAYER_BUNKATU_Y / 2) < GAME_MIN_HEIGHT)
		{
			//ウエポンのY座標をプレイヤーのY座標から、ウエポン画像サイズから分割し、引いた値にする
			//(ウエポンの画像をプレイヤーの頭上に配置するため)
			if (w[w_cnt]->WEAPON_flag_Y == true)
			{
				//w[w_cnt]->WEAPON_Y = p->PLAYER_Y - (WEAPON_Size_H / WEAPON_BUNKATU_Y);
				w[w_cnt]->WEAPON_Y = p->PLAYER_Y;
				w[w_cnt]->WEAPON_X = p->PLAYER_X;

				//ウエポンのYフラグをfalseに変更する
				w[w_cnt]->WEAPON_flag_Y = false;
				//w[w_cnt]->WEAPON_Next_flag = false;
			}

		}
	}


			//ウエポンのYフラグが(Aキーを押した)trueかつ、ウエポンのY座標が(0以上)画面内なら
			
			/*else
			{
				w[w_cnt]->WEAPON_Next_flag = false;
			}*/

	
	//for (int w_cnt = 0; w_cnt < WEAPON_NUM; w_cnt++)
	//{
	//	////描画処理でずらしたY座標を調整
	//	//if (w[w_cnt]->WEAPON_flag_Y == true && w[w_cnt]->WEAPON_Y + (PLAYER_Size_H / PLAYER_BUNKATU_Y / 2) >= GAME_MIN_HEIGHT) //&& w[w_cnt]->WEAPON_Next_flag == true)
	//	//{
	//	//	//windowの左端まで移動する
	//	//	w[w_cnt]->WEAPON_Y -= w[w_cnt]->Get_WEAPON_Speed(WEAPON_Speed);
	//	//}
	//}
		
	return WEAPON_Y;
}


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
					//PlaySoundMem(bgm->MUSIC_COLISION_Handle, DX_PLAYTYPE_BACK);
					//ウエポンに触れたエネミーの位置や画像の添え字をリセットする

					//プレイ画面で敵とウエポンが衝突したときの音楽を鳴らす関数
					bgm->PLAY_COLISION_BGM();

					e[e_num]->ENEMY_RESET();

					w[w_cnt]->WEAPON_flag_X = false;		//A	キーを押したとき、プレイヤーのX座標を取得するためのフラグ
					w[w_cnt]->WEAPON_flag_Y = false;		//A キーを押したとき、自動でY座標を加算するためのフラグ

					e[e_num]->ENEMY_EXPROSION_flag = true;
					
					Get_Collision_Time = Get_Time;
					
					//ウエポンのY座標をプレイヤーのY座標から、ウエポン画像サイズから分割し、引いた値にする
					//(ウエポンの画像をプレイヤーの頭上に配置するため)
					//w[w_cnt]->WEAPON_Y = p->Get_PLAYER_Y() - (WEAPON_Size_H / WEAPON_BUNKATU_Y);
					w[w_cnt]->WEAPON_Y = p->Get_PLAYER_Y();

					s->TOTAL_SCORE();		//獲得したスコアを保持し、計算する関数
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
			e[e_num]->ENEMY_RESET();
			//ENEMY_flag = false;
		}
	}

	return ENEMY_Y;
}


//タイトル画面で難易度を変更したら、各難易度に応じて残機やエネミーの数を調整する関数
void DIFFICULTY::DIFFICULTY_LEVEL_PLAY()
{
	//Easy　残機3
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1 && Lv_Select == Lv_Select_MIN)
	{
		p->PLAYER_HP = 3;			//プレイヤーの残機を変更
		screen_state = GAME_PLAY;	//シーンをゲーム画面に変更
	}

	//Normal　残機2
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1 && Lv_Select == Lv_Select_NORMAL)
	{
		p->PLAYER_HP = 2;			//プレイヤーの残機を変更
		screen_state = GAME_PLAY;	//シーンをゲーム画面に変更
	}

	//Hard　残機1
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1 && Lv_Select == Lv_Select_MAX)
	{
		p->PLAYER_HP = 1;			//プレイヤーの残機を変更
		screen_state = GAME_PLAY;	//シーンをゲーム画面に変更
	}
}

//クリア条件を変更(タイム制かスコア制か)する関数
void CLEARCONDITION::CLEAR_CONDITION_SELECT_PLAY()
{
	if (Keyboard_Get(KEY_INPUT_RETURN) == 1 && ClearCondition_Select == ClearCondition_Select_TIME)
	{
		TimeMode_Play_flag = true;		//タイム制フラグ:ON
		ScoreMode_Play_flag = false;	//スコア制フラグ:OFF
		screen_state = GAME_PLAY;		//シーンをゲーム画面に変更
	}

	if (Keyboard_Get(KEY_INPUT_RETURN) == 1 && ClearCondition_Select == ClearCondition_Select_SCORE)
	{
		TimeMode_Play_flag = false;		//タイム制フラグ:OFF
		ScoreMode_Play_flag = true;		//スコア制フラグ:ON
		screen_state = GAME_PLAY;		//シーンをゲーム画面に変更
	}
}

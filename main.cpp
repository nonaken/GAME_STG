#include "DxLib.h"
#include "Keyboard_Get.h"
#include "PLAYER.h"
#include "ENEMY.h"
#include "FPS.h"


#define GAME_BackImage_TITLE	"BackImage\\kaidou0331_800b.jpg"	//タイトル画面背景画像
#define GAME_TITLE_LOG			"BackImage\\game_title_font.png"	//タイトルロゴ
#define GAME_BackImage_PLAY		"BackImage\\pipo-battlebg001b.jpg"	//プレイ画面背景画像
#define GAME_BackImage_END		"BackImage\\end_2.jpg"	//エンド画面背景画像

#define GAME_FPS_SPEED					   60

#define GAME_TITLE_LOG_UPPERLEFT_X		GAME_WIDTH / 4		//タイトルロゴ画像の左上X座標
#define GAME_TITLE_LOG_UPPERLEFT_Y		GAME_HEIGHT / 3		//タイトルロゴ画像の左上Y座標
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
ENEMY *e[3];							//エネミークラスを３つ生成する




// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // ウィンドウモードに設定(TRUE: FALSE:フルスクリーン)
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//指定の数値で画面を表示する
	

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);	//描画を裏画面に設定
	

	PLAYER_Size = LoadGraph(GAME_PLAYER);			//キャラ画像　の縦と横のサイズを取得するためロードする(すぐに捨てる)

	GetGraphSize(PLAYER_Size, &PLAYER_Size_W, &PLAYER_Size_H);	//キャラ画像の縦と横のサイズを取得

	DeleteGraph(PLAYER_Size);//キャラ画像　の縦と横のサイズを取得したら、使い捨て

	LoadDivGraph(GAME_PLAYER, PLAYER_BUNKATU, PLAYER_BUNKATU_X, PLAYER_BUNKATU_Y, PLAYER_Size_W / PLAYER_BUNKATU_X, PLAYER_Size_H / PLAYER_BUNKATU_Y, &p->PLAYER_Handle[0]);
	


	ENEMY_Size = LoadGraph(GAME_ENEMY);			//キャラ画像　の縦と横のサイズを取得するためロードする(すぐに捨てる)

	GetGraphSize(ENEMY_Size, &ENEMY_Size_W, &ENEMY_Size_H);	//キャラ画像の縦と横のサイズを取得

	DeleteGraph(ENEMY_Size);//キャラ画像　の縦と横のサイズを取得したら、使い捨て

	for (int num = 0; num < 3; num++)
	{
		e[num] = new ENEMY();
		LoadDivGraph(GAME_ENEMY, ENEMY_BUNKATU, ENEMY_BUNKATU_X, ENEMY_BUNKATU_Y, ENEMY_Size_W / ENEMY_BUNKATU_X, ENEMY_Size_H / ENEMY_BUNKATU_Y, &e[num]->ENEMY_Handle[0]);
	}

	//タイトル画面の背景の画像を読み込む
	int imgBack_Title = LoadGraph(GAME_BackImage_TITLE);		//タイトル背景画像を読み込む(*注意：while文で読み込むとFPSが低下する[毎回読み込んでしまうため])
	//タイトルロゴの画像を読み込む
	int imgTitle_log = LoadGraph(GAME_TITLE_LOG);				//タイトルロゴ画像を読み込む(*注意：while文で読み込むとFPSが低下する[毎回読み込んでしまうため])
	
	//プレイ画面の背景画像を読み込む
	int imgBack_Play = LoadGraph(GAME_BackImage_PLAY);

	//エンド画面の背景画像を読み込む
	int	imgBack_End = LoadGraph(GAME_BackImage_END);
	
	


	while (TRUE)	//無限ループ
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了

		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了
		Keyboard_Update();   //キーボードの更新

		fps->Update();		//FPSの処理[更新]

		switch (screen_state)
		{
		case GAME_TITLE:
			
			//背景の画像を描画する
			DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, imgBack_Title, false);
			//タイトルロゴの画像を描画する
			DrawExtendGraph(GAME_TITLE_LOG_UPPERLEFT_X, GAME_TITLE_LOG_UPPERLEFT_Y, GAME_TITLE_LOG_BOTTOMLEFT_X, GAME_TITLE_LOG_BOTTOMLEFT_Y, imgTitle_log, true);
			
			GAME_TITLE_DRAW();	//タイトル画面を描画

			p->PLAYER_RESET();	//プレイヤーを初期位置へ
	
			break;

		case GAME_PLAY:

			DrawExtendGraph(0, 0, GAME_WIDTH, GAME_HEIGHT, imgBack_Play, false);
			GAME_PLAY_DRAW();	//プレイ画面を描画
			p->PLAYER_DRAW();	//プレイヤーの描画処理

			for (int num = 0; num < 3; num++)
			{
				p->PLAYER_COLLISION_ENEMY(e[num]->ENEMY_X, e[num]->ENEMY_Y);	//プレイヤーとエネミーの衝突判定

				e[num]->ENEMY_DRAW();	//エネミーの描画処理
			}
			
			
			break;

		case GAME_END:
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

	delete fps;
	delete p;

	for (int num = 0; num < 3; num++)
	{
		delete e[num];
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
	//キャラとエネミーの当たり判定
	if (((PLAYER_X > ENEMY_X && PLAYER_X < ENEMY_X + ENEMY_Size_W / ENEMY_BUNKATU_X) ||
		(ENEMY_X > PLAYER_X && ENEMY_X < PLAYER_X + PLAYER_Size_W / PLAYER_BUNKATU_X)) &&
		((PLAYER_Y > ENEMY_Y && PLAYER_Y < ENEMY_Y + ENEMY_Size_H / ENEMY_BUNKATU_Y) ||
		(ENEMY_Y > PLAYER_Y && ENEMY_Y < PLAYER_Y + PLAYER_Size_H / PLAYER_BUNKATU_Y)))
	{
		for (int num = 0; num < 3; num++)
		{
			e[num]->ENEMY_RESET();
		}
		PLAYER_HP -=1;
		//screen_state = GAME_END;		//エンド画面へ遷移する
	}

	DrawFormatString(0, 50, RGB(255, 255, 255), "PLAYER：%d", PLAYER_HP);

	if (PLAYER_HP <= 0)
	{
		for (int num = 0; num < 3; num++)
		{
			e[num]->ENEMY_RESET();
		}
		screen_state = GAME_END;		//エンド画面へ遷移する
	}
}

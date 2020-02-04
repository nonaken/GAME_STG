#pragma once

#define TITLE_MUSIC "MUSIC\\TitleBGM.mp3"					//タイトル画面用のbgmを取り込む
#define PLAY_MUSIC "MUSIC\\crying again(PlayBGM).mp3"	//プレイ画面用のbgmを取り込む
#define PLAYER_HP_DAMAGE_MUSIC "MUSIC\\PlayerDamage.mp3"	//プレイヤーのHPが減少したとき用のbgmを取り込む
#define COLISION_MUSIC "MUSIC\\colision.mp3"			//敵とウエポンが衝突したときのbgmを取り込む
#define GAMEOVER_MUSIC "MUSIC\\GameOver.mp3"			//ゲームオーバー画面用のbgmを取り込む
#define GAMECLEAR_MUSIC "MUSIC\\GameClear.mp3"			//ゲームクリア画面用のbgmを取り込む

class BGM
{
public:
	int MUSIC_TITLE_Handle = 0;			//音を鳴らすための変数(タイトル画面BGM)
	int MUSIC_PLAY_Handle = 0;			//音を鳴らすための変数(プレイ画面BGM)
	int MUSIC_PLAYER_HP_DAMAGE_Handle = 0;	//音を鳴らすための変数(プレイ画面BGM[プレイヤーと敵が衝突して、プレイヤーのHPが減少したとき])
	int MUSIC_COLISION_Handle = 0;		//音を鳴らすための変数(プレイ画面BGM[敵とウエポンが衝突したとき])
	int MUSIC_GAMEOVER_Handle = 0;		//音を鳴らすための変数(ゲームオーバー画面BGM)
	int MUSIC_GAMECLEAR_Handle = 0;		//音を鳴らすための変数(ゲームクリア画面BGM)

	void TITLE_BGM();				//タイトル画面でbgmを鳴らす関数
	void PLAY_BGM();				//プレイ画面でbgmを鳴らす関数
	void PLAYER_HP_DAMAGE_BGM();	//プレイ画面でプレイヤーと敵が衝突して、プレイヤーのHPが減少したときの音楽を鳴らす関数
	void PLAY_COLISION_BGM();		//プレイ画面で敵とウエポンが衝突したときの音楽を鳴らす関数
	void GAMEOVER_BGM();			//ゲームオーバー画面でbgmを鳴らす関数
	void GAMECLEAR_BGM();			//ゲームクリア画面でbgmを鳴らす関数
	

	void VOLUME_BGM();				//音量を調節する関数

	void STOP_TITLE_BGM();			//BGMを止める関数(タイトル画面bgm)
	void STOP_PLAY_BGM();			//BGMを止める関数(プレイ画面bgm)
	void STOP_GAMEOVER_BGM();		//BGMを止める関数(ゲームオーバー画面bgm)
	void STOP_GAMECLEAR_BGM();		//BGMを止める関数(ゲームクリア画面bgm)
};
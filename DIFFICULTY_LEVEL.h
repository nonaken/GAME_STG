#pragma once

#define Lv_Select_MIN 0			//難易度変更の最小値(EASY)
#define Lv_Select_NORMAL 1		//難易度変更の値(１：Normal)
#define Lv_Select_MAX 2			//難易度変更の最大値(HARD)

#define ClearCondition_Select_TIME  0 	//クリア条件がタイム制のときの値(０：タイム制)
#define ClearCondition_Select_SCORE 1	//クリア条件がスコア制のときの値(１：スコア制)


#define GAME_CLEAR_SCORE 2000		//ゲームクリアに必要なスコア

//難易度変更用クラス
class DIFFICULTY
{
public:
	//int Lv;			//難易度変更のレベルを描画するための変数

	//文字列を二次元配列で格納し、Lv_Selectの値で難易度変更をする
	char Difficuty_Array[3][64] = { "Easy\n(残機:3)","Normal\n(残機:2)","Hard\n(残機:1)" };
	
	int Lv_Select = 0;		//難易度変更のレベルを保持する関数(Easy：0, Normal：2, Hard：3)
	int FontHandle_LV_SELECT = 0;		//難易度変更のフォントハンドル用変数

	void DIFFICULTY_LEVEL_SELECT_DRAW();//難易度変更を描画する関数
	void DIFFICULTY_LEVEL_TITLE();		//プレイ画面でEasy,Normal,Hardに変更し、値を保持する関数
	void DIFFICULTY_LEVEL_PLAY();		//プレイ画面でEasy,Normal,Hardを変更した値を基に難易度変更を実施する関数
};

//クリア条件変更用クラス
class CLEARCONDITION
{
public:
	char ClearCondition_Array[2][32] = { "タイム制[逃げ切り]" , "スコア制[2000以上]"};
 
	int FontHandle_ClearCondition_SELECT = 0;//クリア条件変更のフォントハンドル用変数
	void CLEAR_CONDITION_SELECT_DRAW();	//クリア条件変更を描画する関数

	//char ClearCondition[50];			//クリア条件変更のレベルを描画するための配列
	int ClearCondition_Select = 0;		//クリア条件変更のレベルを保持する関数(TimeMode：0, ScoreMode：1)
	bool TimeMode_Play_flag = false;	//クリア条件がタイムモードかどうか確認するためのフラグ
	bool ScoreMode_Play_flag = false;	//クリア条件がスコアモードかどうか確認するためのフラグ
	

	void CLEAR_CONDITION_SELECT_TITLE();	//プレイ画面でタイムモードか、スコアモードに変更し、値を保持する関数
	void CLEAR_CONDITION_SELECT_PLAY();		//プレイ画面でタイムモードか、スコアモードに変更した値を基にクリア条件変更を実施する関数
	void CLEAR_CONDITION_SELECT_PLAYMODE_DRAW();		//プレイ画面でタイムモードかスコアモードが把握できるようにどちらのモードか描画する
};
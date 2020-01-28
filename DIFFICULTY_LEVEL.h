#pragma once

//難易度変更用クラス
class DIFFICULTY
{
public:
	char Lv[25];			//難易度変更のレベルを描画するための配列
	int Lv_Select = 0;		//難易度変更のレベルを保持する関数(Easy：0, Normal：2, Hard：3)
	
	void DIFFICULTY_LEVEL_TITLE();		//プレイ画面でEasy,Normal,Hardに変更し、値を保持する関数
	void DIFFICULTY_LEVEL_PLAY();		//プレイ画面でEasy,Normal,Hardを変更した値を基に難易度変更を実施する関数
};

//クリア条件変更用クラス
class CLEARCONDITION
{
public:
	char ClearCondition[50];			//クリア条件変更のレベルを描画するための配列
	int ClearCondition_Select = 0;		//クリア条件変更のレベルを保持する関数(TimeMode：0, ScoreMode：1)
	bool TimeMode_Play_flag = false;	//クリア条件がタイムモードかどうか確認するためのフラグ
	bool ScoreMode_Play_flag = false;	//クリア条件がスコアモードかどうか確認するためのフラグ
	

	void CLEAR_CONDITION_SELECT_TITLE();	//プレイ画面でタイムモードか、スコアモードに変更し、値を保持する関数
	void CLEAR_CONDITION_SELECT_PLAY();		//プレイ画面でタイムモードか、スコアモードに変更した値を基にクリア条件変更を実施する関数
};
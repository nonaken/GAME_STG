#pragma once

//難易度変更用クラス
class DIFFICULTY
{
public:
	char Lv[25];			//難易度変更のレベルを描画するための配列
	int Lv_Select = 0;		//難易度変更のレベルを保持する関数(Easy：0, Normal：2, Hard：3)
	
	void DIFFICULTY_LEVEL_TITLE();		//プレイ画面でEasy,Normal,Hardを変更し、値を保持する関数
	void DIFFICULTY_LEVEL_PLAY();		//プレイ画面でEasy,Normal,Hardを変更した値を基に難易度変更を実施する関数
};
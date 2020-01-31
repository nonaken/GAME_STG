#include "DxLib.h"
#include "DIFFICULTY_LEVEL.h"
#include "Keyboard_Get.h"



void DIFFICULTY::DIFFICULTY_LEVEL_TITLE()
{
	if (Keyboard_Get(KEY_INPUT_UP) == 1 && Lv_Select < Lv_Select_MAX)
	{
		Lv_Select++;
	}

	if (Keyboard_Get(KEY_INPUT_DOWN) == 1 && Lv_Select > Lv_Select_MIN)
	{
		Lv_Select--;
	}

	//if (Lv_Select == Lv_Select_MIN)
	//{
	//	//strcpy(Lv, "Easy\n       (残機:3)");
	//}

	//if (Lv_Select == Lv_Select_NORMAL)
	//{
	//	//strcpy(Lv, "Normal\n       (残機:2)");
	//}

	//if (Lv_Select == Lv_Select_MAX)
	//{
	//	/*strcpy(Lv, "Hard\n       (残機:1)");*/
	//}
}

void CLEARCONDITION::CLEAR_CONDITION_SELECT_TITLE()
{

	if (Keyboard_Get(KEY_INPUT_RIGHT) == 1 && ClearCondition_Select < ClearCondition_Select_SCORE)
	{
		ClearCondition_Select++;
	}

	if (Keyboard_Get(KEY_INPUT_LEFT) == 1 && ClearCondition_Select > ClearCondition_Select_TIME)
	{
		ClearCondition_Select--;
	}

	/*if (ClearCondition_Select == ClearCondition_Select_TIME)
	{
		strcpy(ClearCondition, "モード：タイム制(60秒で終了:逃げ切り)\n");
	}
	if (ClearCondition_Select == ClearCondition_Select_SCORE)
	{
		(ClearCondition, "モード：スコア制(60秒で終了)\n");
	}*/
}

//クリア条件変更を描画する関数
void CLEARCONDITION::CLEAR_CONDITION_SELECT_DRAW()
{
	DrawFormatStringToHandle(0, 100, GetColor(0, 0, 255), FontHandle_ClearCondition_SELECT, "クリア条件：%s", ClearCondition_Array[ClearCondition_Select]);
}

//難易度変更を描画する関数
void DIFFICULTY::DIFFICULTY_LEVEL_SELECT_DRAW()
{
	DrawFormatStringToHandle(100, 400, GetColor(255, 0, 255), FontHandle_LV_SELECT, "難易度：%s", Difficuty_Array[Lv_Select]);	//難易度を描画する関数
}

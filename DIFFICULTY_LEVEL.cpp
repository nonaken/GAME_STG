#include "DxLib.h"
#include "DIFFICULTY_LEVEL.h"
#include "Keyboard_Get.h"

void DIFFICULTY::DIFFICULTY_LEVEL_TITLE()
{
	if (Keyboard_Get(KEY_INPUT_UP) == 1 && Lv_Select < 2)
	{
		Lv_Select++;
	}

	if (Keyboard_Get(KEY_INPUT_DOWN) == 1 && Lv_Select > 0)
	{
		Lv_Select--;
	}


	if (Lv_Select == 0)
	{
		strcpy(Lv, "Easy\n       (残機:3)");
	}

	if (Lv_Select == 1)
	{
		strcpy(Lv, "Normal\n       (残機:2)");
	}

	if (Lv_Select == 2)
	{
		strcpy(Lv, "Hard\n       (残機:1)");
	}
	

}
void CLEARCONDITION::CLEAR_CONDITION_SELECT_TITLE()
{

	if (Keyboard_Get(KEY_INPUT_RIGHT) == 1 && ClearCondition_Select < 1)
	{
		ClearCondition_Select++;
	}

	if (Keyboard_Get(KEY_INPUT_LEFT) == 1 && ClearCondition_Select > 0)
	{
		ClearCondition_Select--;
	}


	if (ClearCondition_Select == 0)
	{
		strcpy(ClearCondition, "モード：タイム制(60秒で終了:逃げ切り)\n");
	}
	if (ClearCondition_Select == 1)
	{
		strcpy(ClearCondition, "モード：スコア制(60秒で終了)\n");
	}
}


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
	//	//strcpy(Lv, "Easy\n       (�c�@:3)");
	//}

	//if (Lv_Select == Lv_Select_NORMAL)
	//{
	//	//strcpy(Lv, "Normal\n       (�c�@:2)");
	//}

	//if (Lv_Select == Lv_Select_MAX)
	//{
	//	/*strcpy(Lv, "Hard\n       (�c�@:1)");*/
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
		strcpy(ClearCondition, "���[�h�F�^�C����(60�b�ŏI��:�����؂�)\n");
	}
	if (ClearCondition_Select == ClearCondition_Select_SCORE)
	{
		(ClearCondition, "���[�h�F�X�R�A��(60�b�ŏI��)\n");
	}*/
}

//�N���A�����ύX��`�悷��֐�
void CLEARCONDITION::CLEAR_CONDITION_SELECT_DRAW()
{
	DrawFormatStringToHandle(0, 100, GetColor(0, 0, 255), FontHandle_ClearCondition_SELECT, "�N���A�����F%s", ClearCondition_Array[ClearCondition_Select]);
}

//��Փx�ύX��`�悷��֐�
void DIFFICULTY::DIFFICULTY_LEVEL_SELECT_DRAW()
{
	DrawFormatStringToHandle(100, 400, GetColor(255, 0, 255), FontHandle_LV_SELECT, "��Փx�F%s", Difficuty_Array[Lv_Select]);	//��Փx��`�悷��֐�
}

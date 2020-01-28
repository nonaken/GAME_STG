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
		strcpy(Lv, "Easy\n       (�c�@:3)");
	}

	if (Lv_Select == 1)
	{
		strcpy(Lv, "Normal\n       (�c�@:2)");
	}

	if (Lv_Select == 2)
	{
		strcpy(Lv, "Hard\n       (�c�@:1)");
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
		strcpy(ClearCondition, "���[�h�F�^�C����(60�b�ŏI��:�����؂�)\n");
	}
	if (ClearCondition_Select == 1)
	{
		strcpy(ClearCondition, "���[�h�F�X�R�A��(60�b�ŏI��)\n");
	}
}


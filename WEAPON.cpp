#include "DxLib.h"
#include "WEAPON.h"
#include "Keyboard_Get.h"
#include "WINDOW_SIZE.h"

int WEAPON_Size;					//�E�G�|���̉摜�T�C�Y��LoadDivGrahp�Ŏ擾���邽��
int WEAPON_Size_W, WEAPON_Size_H;	//�E�G�|���摜�̉��T�C�Y�A�c�T�C�Y���擾

//�E�G�|���̃X�s�[�h���擾����֐�
int WEAPON::Get_WEAPON_Speed()
{
	//�E�G�|���̃X�s�[�h�ݒ�
	WEAPON_Speed = 10;
	return WEAPON_Speed;
};

//�E�G�|����`�悷��֐�
void WEAPON::WEAPON_DRAW(int x, int y)
{
	DrawGraph(Get_WEAPON_X() - x, Get_WEAPON_Y() - y, WEAPON_Handle[WEAPON_soeji], TRUE);
};

//�E�G�|�������Z�b�g����֐�
void WEAPON::WEAPON_RESET()
{
	WEAPON_X = GAME_WIDTH / PLAYER_X_HALF;
	WEAPON_Y =(GAME_HEIGHT / PLAYER_Y_HALF) - (WEAPON_Size_H / WEAPON_BUNKATU_Y);
	WEAPON_flag_Y = false;
};


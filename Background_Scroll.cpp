#include "DxLib.h"
#include"Background_Scroll.h"
#include "WINDOW_SIZE.h"

//�X�N���[������w�i�摜��`�悷��֐�
void BACKGROUND::Background_Scroll_Draw()
{
	//////////////////////�X�N���[������w�i��`�悷�鏈��/////////////////
	//�X�N���[������w�i�摜��`�悷��(�P����)
	DrawExtendGraph(this->img_Back_Scroll_W, this->img_Back_Scroll_H, GAME_WIDTH, GAME_HEIGHT + this->img_Back_Scroll_H, this->imgBack_Scroll, false);

	//�X�N���[������w�i�摜��`�悷��(�Q���ڃX�N���[���p)
	DrawExtendGraph(this->img_Back_Scroll_W, this->img_Back_Scroll_H - GAME_HEIGHT, GAME_WIDTH, this->img_Back_Scroll_H, this->imgBack_Scroll, false);
	///////////////////////////////////////////////////////////////////////////

}

//�X�N���[������������֐�
void BACKGROUND::Background_Scroll()
{
	//�Q���ڂ̉摜�̃X�N���[�����I���܂ŉ��Z����
	if (img_Back_Scroll_H < GAME_HEIGHT)
	{
		img_Back_Scroll_H += 5;
	}
	//�Q���ڂ̉摜�̃X�N���[�����I������烊�Z�b�g����
	else
	{
		img_Back_Scroll_H = 0;
	}
}
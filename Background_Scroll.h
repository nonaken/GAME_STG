#pragma once

#define GAME_BackImage_TITLE	"BackImage\\�w�i.png"//"BackImage\\kaidou0331_800b.jpg"	//�^�C�g����ʔw�i�摜
#define GAME_TITLE_LOG			"BackImage\\game_title_font.png"	//�^�C�g�����S
#define GAME_BackImage_PLAY		"BackImage\\�w�i.png"				//�v���C��ʔw�i�摜
#define GAME_BackImage_CLEAR	"BackImage\\GAME_CLEAR.jpg"			//�N���A��ʔw�i�摜
#define GAME_BackImage_END		"BackImage\\GAME_OVER_2.jpg"			//�G���h��ʔw�i�摜

class BACKGROUND
{
public:
	int img_Back_Scroll_W;		//�c�X�N���[���w�i ���T�C�Y��ێ�����ϐ�
	int img_Back_Scroll_H;		//�c�X�N���[���w�i �c�T�C�Y��ێ�����ϐ�
	int imgBack_Scroll = 0;		//�X�N���[������摜�����[�h���邽�߂̕ϐ�

	void Background_Scroll_Draw();		//�X�N���[������w�i�摜��`�悷��֐�
	void Background_Scroll();			//�w�i���X�N���[������֐�
};
#pragma once

class BACKGROUND
{
public:
	int img_Back_Scroll_W;		//�c�X�N���[���w�i ���T�C�Y��ێ�����ϐ�
	int img_Back_Scroll_H;		//�c�X�N���[���w�i �c�T�C�Y��ێ�����ϐ�
	int imgBack_Scroll = 0;		//�X�N���[������摜�����[�h���邽�߂̕ϐ�

	void Background_Scroll_Draw();		//�X�N���[������w�i�摜��`�悷��֐�
	void Background_Scroll();			//�w�i���X�N���[������֐�
};
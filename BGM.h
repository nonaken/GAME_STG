#pragma once

class BGM
{
public:
	int MUSIC_Handle = 0;			//����炷���߂̕ϐ�(�v���C���BGM)
	int MUSIC_COLISION_Handle = 0;	//����炷���߂̕ϐ�(�v���C���BGM[�G�ƃE�G�|�����Փ˂����Ƃ�])

	void PLAY_BGM();				//�v���C��ʂŖ炷�֐�
	void PLAY_VOLUME_BGM();
	void PLAY_COLISION_BGM();		//�v���C��ʂœG�ƃE�G�|�����Փ˂����Ƃ��̉��y��炷�֐�
};
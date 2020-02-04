#pragma once

#define TITLE_MUSIC "MUSIC\\TitleBGM.mp3"					//�^�C�g����ʗp��bgm����荞��
#define PLAY_MUSIC "MUSIC\\crying again(PlayBGM).mp3"	//�v���C��ʗp��bgm����荞��
#define PLAYER_HP_DAMAGE_MUSIC "MUSIC\\PlayerDamage.mp3"	//�v���C���[��HP�����������Ƃ��p��bgm����荞��
#define COLISION_MUSIC "MUSIC\\colision.mp3"			//�G�ƃE�G�|�����Փ˂����Ƃ���bgm����荞��
#define GAMEOVER_MUSIC "MUSIC\\GameOver.mp3"			//�Q�[���I�[�o�[��ʗp��bgm����荞��
#define GAMECLEAR_MUSIC "MUSIC\\GameClear.mp3"			//�Q�[���N���A��ʗp��bgm����荞��

class BGM
{
public:
	int MUSIC_TITLE_Handle = 0;			//����炷���߂̕ϐ�(�^�C�g�����BGM)
	int MUSIC_PLAY_Handle = 0;			//����炷���߂̕ϐ�(�v���C���BGM)
	int MUSIC_PLAYER_HP_DAMAGE_Handle = 0;	//����炷���߂̕ϐ�(�v���C���BGM[�v���C���[�ƓG���Փ˂��āA�v���C���[��HP�����������Ƃ�])
	int MUSIC_COLISION_Handle = 0;		//����炷���߂̕ϐ�(�v���C���BGM[�G�ƃE�G�|�����Փ˂����Ƃ�])
	int MUSIC_GAMEOVER_Handle = 0;		//����炷���߂̕ϐ�(�Q�[���I�[�o�[���BGM)
	int MUSIC_GAMECLEAR_Handle = 0;		//����炷���߂̕ϐ�(�Q�[���N���A���BGM)

	void TITLE_BGM();				//�^�C�g����ʂ�bgm��炷�֐�
	void PLAY_BGM();				//�v���C��ʂ�bgm��炷�֐�
	void PLAYER_HP_DAMAGE_BGM();	//�v���C��ʂŃv���C���[�ƓG���Փ˂��āA�v���C���[��HP�����������Ƃ��̉��y��炷�֐�
	void PLAY_COLISION_BGM();		//�v���C��ʂœG�ƃE�G�|�����Փ˂����Ƃ��̉��y��炷�֐�
	void GAMEOVER_BGM();			//�Q�[���I�[�o�[��ʂ�bgm��炷�֐�
	void GAMECLEAR_BGM();			//�Q�[���N���A��ʂ�bgm��炷�֐�
	

	void VOLUME_BGM();				//���ʂ𒲐߂���֐�

	void STOP_TITLE_BGM();			//BGM���~�߂�֐�(�^�C�g�����bgm)
	void STOP_PLAY_BGM();			//BGM���~�߂�֐�(�v���C���bgm)
	void STOP_GAMEOVER_BGM();		//BGM���~�߂�֐�(�Q�[���I�[�o�[���bgm)
	void STOP_GAMECLEAR_BGM();		//BGM���~�߂�֐�(�Q�[���N���A���bgm)
};
#include "DxLib.h"
#include "BGM.h"

//�^�C�g����ʂ�bgm��炷�֐�
void BGM::TITLE_BGM()
{
	//�^�C�g����ʂɑJ�ڂ����特�y�t�@�C����炷(DX_PLAYTYPE_LOOP:�Ō�܂ŉ��y�t�@�C����炵����A���߂���܂��炷)
	PlaySoundMem(MUSIC_TITLE_Handle, DX_PLAYTYPE_BACK);
}

//�v���C��ʂ�bgm��炷�֐�
void BGM::PLAY_BGM()
{
	//�v���C��ʂɑJ�ڂ����特�y�t�@�C����炷(DX_PLAYTYPE_LOOP:�Ō�܂ŉ��y�t�@�C����炵����A���߂���܂��炷)
	PlaySoundMem(MUSIC_PLAY_Handle, DX_PLAYTYPE_LOOP);
}

//�v���C��ʂŃv���C���[�ƓG���Փ˂��āA�v���C���[��HP�����������Ƃ��̉��y��炷�֐�
void BGM::PLAYER_HP_DAMAGE_BGM()
{
	//�v���C���[��HP�����������Ƃ��A���y�t�@�C����炷
	PlaySoundMem(MUSIC_PLAYER_HP_DAMAGE_Handle, DX_PLAYTYPE_BACK);
}

//�v���C��ʂœG�ƃE�G�|�����Փ˂����Ƃ��̉��y��炷�֐�
void BGM::PLAY_COLISION_BGM()
{
	//�v���C��ʂœG�ƃE�G�|�����Փ˂����Ƃ��̉��y��炷�֐�
	PlaySoundMem(MUSIC_COLISION_Handle, DX_PLAYTYPE_BACK);
}

//�Q�[���I�[�o�[��ʂ�bgm��炷�֐�
void BGM::GAMEOVER_BGM()
{
	//�Q�[���I�[�o�[��ʂɑJ�ڂ����特�y�t�@�C����炷(DX_PLAYTYPE_LOOP:�Ō�܂ŉ��y�t�@�C����炵����A���߂���܂��炷)
	PlaySoundMem(MUSIC_GAMEOVER_Handle, DX_PLAYTYPE_LOOP);
}

//�Q�[���N���A��ʂ�bgm��炷�֐�
void BGM::GAMECLEAR_BGM()
{
	//�Q�[���N���A��ʂɑJ�ڂ����特�y�t�@�C����炷(DX_PLAYTYPE_LOOP:�Ō�܂ŉ��y�t�@�C����炵����A���߂���܂��炷)
	PlaySoundMem(MUSIC_GAMECLEAR_Handle, DX_PLAYTYPE_LOOP);
}

//���ʂ𒲐߂���֐�
void BGM::VOLUME_BGM()
{
	// ���ʂ̐ݒ�
	ChangeVolumeSoundMem(255 * 30 / 100, MUSIC_TITLE_Handle);
	ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_PLAY_Handle);
	ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_PLAYER_HP_DAMAGE_Handle);
	ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_COLISION_Handle);
	ChangeVolumeSoundMem(255 * 30 / 100, MUSIC_GAMEOVER_Handle);
	ChangeVolumeSoundMem(255 * 40 / 100, MUSIC_GAMECLEAR_Handle);
	
}

//BGM���~�߂�֐�(�^�C�g�����bgm)
void BGM::STOP_TITLE_BGM()
{
	//�^�C�g����ʂ�bgm���~�߂�
	StopSoundMem(MUSIC_TITLE_Handle);
}

//BGM���~�߂�֐�(�v���C���bgm)
void BGM::STOP_PLAY_BGM()
{
	//�v���C��ʂ�bgm���~�߂�
	StopSoundMem(MUSIC_PLAY_Handle);
}

//BGM���~�߂�֐�(�Q�[���I�[�o�[���bgm)
void BGM::STOP_GAMEOVER_BGM()
{
	//�Q�[���I�[�o�[��ʂ�bgm���~�߂�
	StopSoundMem(MUSIC_GAMEOVER_Handle);
}

//BGM���~�߂�֐�(�Q�[���N���A���bgm)
void BGM::STOP_GAMECLEAR_BGM()
{
	//�Q�[���N���A��ʂ�bgm���~�߂�
	StopSoundMem(MUSIC_GAMECLEAR_Handle);
}
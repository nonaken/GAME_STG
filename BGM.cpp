#include "DxLib.h"
#include "BGM.h"

void BGM::PLAY_BGM()
{
	//�v���C��ʂɑJ�ڂ����特�y�t�@�C����炷(DX_PLAYTYPE_LOOP:�Ō�܂ŉ��y�t�@�C����炵����A���߂���܂��炷)
	PlaySoundMem(MUSIC_Handle, DX_PLAYTYPE_LOOP);
}

void BGM::PLAY_VOLUME_BGM()
{
	// ���ʂ̐ݒ�
	ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_Handle);
	ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_COLISION_Handle);
}

void BGM::PLAY_COLISION_BGM()
{
	//�v���C��ʂœG�ƃE�G�|�����Փ˂����Ƃ��̉��y��炷�֐�
	PlaySoundMem(MUSIC_COLISION_Handle, DX_PLAYTYPE_BACK);
}
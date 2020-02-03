#include "DxLib.h"
#include "BGM.h"

void BGM::PLAY_BGM()
{
	//プレイ画面に遷移したら音楽ファイルを鳴らす(DX_PLAYTYPE_LOOP:最後まで音楽ファイルを鳴らしたら、初めからまた鳴らす)
	PlaySoundMem(MUSIC_Handle, DX_PLAYTYPE_LOOP);
}

void BGM::PLAY_VOLUME_BGM()
{
	// 音量の設定
	ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_Handle);
	ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_COLISION_Handle);
}

void BGM::PLAY_COLISION_BGM()
{
	//プレイ画面で敵とウエポンが衝突したときの音楽を鳴らす関数
	PlaySoundMem(MUSIC_COLISION_Handle, DX_PLAYTYPE_BACK);
}
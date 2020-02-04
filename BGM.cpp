#include "DxLib.h"
#include "BGM.h"

//タイトル画面でbgmを鳴らす関数
void BGM::TITLE_BGM()
{
	//タイトル画面に遷移したら音楽ファイルを鳴らす(DX_PLAYTYPE_LOOP:最後まで音楽ファイルを鳴らしたら、初めからまた鳴らす)
	PlaySoundMem(MUSIC_TITLE_Handle, DX_PLAYTYPE_BACK);
}

//プレイ画面でbgmを鳴らす関数
void BGM::PLAY_BGM()
{
	//プレイ画面に遷移したら音楽ファイルを鳴らす(DX_PLAYTYPE_LOOP:最後まで音楽ファイルを鳴らしたら、初めからまた鳴らす)
	PlaySoundMem(MUSIC_PLAY_Handle, DX_PLAYTYPE_LOOP);
}

//プレイ画面でプレイヤーと敵が衝突して、プレイヤーのHPが減少したときの音楽を鳴らす関数
void BGM::PLAYER_HP_DAMAGE_BGM()
{
	//プレイヤーのHPが減少したとき、音楽ファイルを鳴らす
	PlaySoundMem(MUSIC_PLAYER_HP_DAMAGE_Handle, DX_PLAYTYPE_BACK);
}

//プレイ画面で敵とウエポンが衝突したときの音楽を鳴らす関数
void BGM::PLAY_COLISION_BGM()
{
	//プレイ画面で敵とウエポンが衝突したときの音楽を鳴らす関数
	PlaySoundMem(MUSIC_COLISION_Handle, DX_PLAYTYPE_BACK);
}

//ゲームオーバー画面でbgmを鳴らす関数
void BGM::GAMEOVER_BGM()
{
	//ゲームオーバー画面に遷移したら音楽ファイルを鳴らす(DX_PLAYTYPE_LOOP:最後まで音楽ファイルを鳴らしたら、初めからまた鳴らす)
	PlaySoundMem(MUSIC_GAMEOVER_Handle, DX_PLAYTYPE_LOOP);
}

//ゲームクリア画面でbgmを鳴らす関数
void BGM::GAMECLEAR_BGM()
{
	//ゲームクリア画面に遷移したら音楽ファイルを鳴らす(DX_PLAYTYPE_LOOP:最後まで音楽ファイルを鳴らしたら、初めからまた鳴らす)
	PlaySoundMem(MUSIC_GAMECLEAR_Handle, DX_PLAYTYPE_LOOP);
}

//音量を調節する関数
void BGM::VOLUME_BGM()
{
	// 音量の設定
	ChangeVolumeSoundMem(255 * 30 / 100, MUSIC_TITLE_Handle);
	ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_PLAY_Handle);
	ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_PLAYER_HP_DAMAGE_Handle);
	ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_COLISION_Handle);
	ChangeVolumeSoundMem(255 * 30 / 100, MUSIC_GAMEOVER_Handle);
	ChangeVolumeSoundMem(255 * 40 / 100, MUSIC_GAMECLEAR_Handle);
	
}

//BGMを止める関数(タイトル画面bgm)
void BGM::STOP_TITLE_BGM()
{
	//タイトル画面のbgmを止める
	StopSoundMem(MUSIC_TITLE_Handle);
}

//BGMを止める関数(プレイ画面bgm)
void BGM::STOP_PLAY_BGM()
{
	//プレイ画面のbgmを止める
	StopSoundMem(MUSIC_PLAY_Handle);
}

//BGMを止める関数(ゲームオーバー画面bgm)
void BGM::STOP_GAMEOVER_BGM()
{
	//ゲームオーバー画面のbgmを止める
	StopSoundMem(MUSIC_GAMEOVER_Handle);
}

//BGMを止める関数(ゲームクリア画面bgm)
void BGM::STOP_GAMECLEAR_BGM()
{
	//ゲームクリア画面のbgmを止める
	StopSoundMem(MUSIC_GAMECLEAR_Handle);
}
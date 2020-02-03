#pragma once

class BGM
{
public:
	int MUSIC_Handle = 0;			//音を鳴らすための変数(プレイ画面BGM)
	int MUSIC_COLISION_Handle = 0;	//音を鳴らすための変数(プレイ画面BGM[敵とウエポンが衝突したとき])

	void PLAY_BGM();				//プレイ画面で鳴らす関数
	void PLAY_VOLUME_BGM();
	void PLAY_COLISION_BGM();		//プレイ画面で敵とウエポンが衝突したときの音楽を鳴らす関数
};
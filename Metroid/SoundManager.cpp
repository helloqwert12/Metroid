//#include "SoundManager.h"
//
//SoundManager* SoundManager::_instance;
//
//SoundManager* SoundManager::getInstance()
//{
//	if (_instance == nullptr)
//	{
//		_instance = new SoundManager();
//	}
//	return _instance;
//}
//
//void SoundManager::loadSound(HWND hWnd)
//{
//	// Khởi tạo CSoundManager.
//	DirectSound_Init(hWnd);
//
//	CSound* sound = nullptr;
//
//	sound = LoadSound("Resources//sound//metroid03.mp3");
//	_listSound[eSoundId::BACKGROUND_MAP] = sound;
//
//	sound = LoadSound("Resources//sound//metroid10.mp3");
//	_listSound[eSoundId::BACKGROUND_BOSS] = sound;
//	
//	sound = LoadSound("Resources//sound//metroid01.mp3");
//	_listSound[eSoundId::BACKGROUND_INTRO] = sound;
//
//	sound = LoadSound("Resources//sound//metroid02.mp3");
//	_listSound[eSoundId::BACKGROUND_APPEARANCE] = sound;
//
//	sound = LoadSound("Resources//sound//butllet_hit_enemy.mp3");
//	_listSound[eSoundId::BULLET_HIT_ENEMY] = sound;
//
//	sound = LoadSound("Resources//sound//samus_hit_enemy.wav");
//	_listSound[eSoundId::SAMUS_HIT_ENEMY] = sound;
//
//	sound = LoadSound("Resources//sound//shoot.wav");
//	_listSound[eSoundId::SHOOT] = sound;
//
//	sound = LoadSound("Resources//sound//jump.wav");
//	_listSound[eSoundId::JUMP] = sound;
//}
//
//bool SoundManager::IsPlaying(eSoundId soundid)
//{
//	auto sound = _listSound[soundid];
//	if (sound != nullptr)
//	{
//		return sound->IsSoundPlaying();
//	}
//	return false;
//}
//
//void SoundManager::Play(eSoundId soundid)
//{
//	auto sound = _listSound[soundid];
//	if (sound != nullptr)
//	{
//		PlaySound(sound);
//		this->currentSound = sound;
//	}
//}
//void SoundManager::PlayLoop(eSoundId soundid)
//{
//	auto sound = _listSound[soundid];
//	if (sound != nullptr)
//	{
//		sound->Play(0, DSBPLAY_LOOPING);
//	}
//}
//void SoundManager::Stop(eSoundId soundid)
//{
//	auto sound = _listSound[soundid];
//	if (sound != nullptr)
//	{
//		StopSound(sound);
//	}
//}
//
//SoundManager::SoundManager()
//{
//	currentSound = nullptr;
//}
//
//SoundManager::~SoundManager()
//{
//}
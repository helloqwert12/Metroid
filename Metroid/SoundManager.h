//#ifndef __SOUND_MANAGER__
//#define __SOUND_MANAGER__
//#include "dxaudio.h"
//
//#include <map>
//using namespace std;
//
//enum eSoundId
//{
//	// Nhạc nền intro
//	BACKGROUND_INTRO,
//
//	//Nhạc nền Apprearance
//	BACKGROUND_APPEARANCE,
//
//	// Nhạc nền map
//	BACKGROUND_MAP,
//
//	// Nhạc nền boss
//	BACKGROUND_BOSS,
//
//	// Nhảy
//	JUMP,
//
//	// Bắn đạn
//	SHOOT,
//
//	// Đạn hit enemy
//	BULLET_HIT_ENEMY,
//
//	// Samus hit enemy
//	SAMUS_HIT_ENEMY,
//
//};
//
//class SoundManager
//{
//public:
//	~SoundManager();
//	static SoundManager* getInstance();
//	void loadSound(HWND hWnd);
//	void Play(eSoundId);
//	void Stop(eSoundId);
//	void PlayLoop(eSoundId);
//	bool IsPlaying(eSoundId);
//private:
//	SoundManager();
//	static SoundManager* _instance;
//	map<eSoundId, CSound*> _listSound;
//	CSound* currentSound;
//	float volume;
//};
//
//#endif // !__SOUND_MANAGER__

/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_CLIENT_COMPONENTS_CONTROLS_H
#define GAME_CLIENT_COMPONENTS_CONTROLS_H
#include <SDL_joystick.h>
#include <base/vmath.h>
#include <base/system.h>
#include <game/client/component.h>

class CControls : public CComponent
{
public:
	//ChillerDragon Vars
	int m_TimeTicker;
	int m_JumpDelay;
	int m_JumpDelay2;  //hiddenway jumps
	int m_DontHook; //speedstart in hiddenway
	int m_StuckTime;
	int m_abc; //iused for stuff idc
	bool m_ReleaseHook;
	//TeeTown
	int m_JumpTicker;
	int m_LifetimeTT; //lifetime on teetown
	int m_AntiAfkTicker;
	//royal
	int m_Fire_delay;
	//copy love box booster
	int m_boost_kill_delay;




	//Auto stuff
	int m_autohook_delay;


	vec2 m_MousePos[2];
	vec2 m_TargetPos[2];
	float m_OldMouseX;
	float m_OldMouseY;
	SDL_Joystick *m_Joystick;
	bool m_JoystickFirePressed;
	bool m_JoystickRunPressed;
	int64 m_JoystickTapTime;

	SDL_Joystick *m_Gamepad;
	bool m_UsingGamepad;

	int m_AmmoCount[NUM_WEAPONS];

	CNetObj_PlayerInput m_InputData[2];
	CNetObj_PlayerInput m_LastData[2];
	int m_InputDirectionLeft[2];
	int m_InputDirectionRight[2];
	int m_ShowHookColl[2];
	int m_LastDummy;
	int m_OtherFire;

	CControls();

	virtual void OnReset();
	virtual void OnRelease();
	virtual void OnRender();
	virtual void OnMessage(int MsgType, void *pRawMsg);
	virtual bool OnMouseMove(float x, float y);
	virtual void OnConsoleInit();
	virtual void OnPlayerDeath();

	int SnapInput(int *pData);
	void ClampMousePos();
	void ResetInput(int dummy);
};
#endif

#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"

#define FIREBALL_VX 0.1f
#define FIREBALL_VY 0.1f

extern CMario* mario;
extern CFireBall* fireball;
extern vector<LPGAMEOBJECT> objects;

void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_S:
		mario->SetState(MARIO_STATE_JUMP);
		break;
	case DIK_D:
		fireball = new CFireBall(mario->getX(), mario->getY(), FIREBALL_VX, FIREBALL_VY, mario->getnx());
		objects.push_back(fireball);
		break;
	}
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_S:
		mario->SetState(MARIO_STATE_RELEASE_JUMP);
		break;
	case DIK_DOWN:
		mario->SetState(MARIO_STATE_SIT_RELEASE);
		break;
	}
}

void CSampleKeyHandler::KeyState(BYTE *states)
{
	CGame* game = CGame::GetInstance();

	if (game->IsKeyDown(DIK_RIGHT))
	{
		if (game->IsKeyDown(DIK_A))
			mario->SetState(MARIO_STATE_RUNNING_RIGHT);
		else
			mario->SetState(MARIO_STATE_WALKING_RIGHT);
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
		if (game->IsKeyDown(DIK_A))
			mario->SetState(MARIO_STATE_RUNNING_LEFT);
		else
			mario->SetState(MARIO_STATE_WALKING_LEFT);
	}
	else
		mario->SetState(MARIO_STATE_IDLE);
	
	// Sitting state has higher priority 
	if (game->IsKeyDown(DIK_DOWN))
	{
		mario->SetState(MARIO_STATE_SIT);
	}

}
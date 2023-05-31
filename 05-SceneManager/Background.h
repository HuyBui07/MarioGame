#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_BRICK 10000
#define BRICK_WIDTH 16
#define BRICK_BBOX_WIDTH 16
#define BRICK_BBOX_HEIGHT 16

class CBackground : public CGameObject 
{
protected:
	float cellWidth;
	float cellHeight;
	int spriteId;
public:
	CBackground(float x, float y,
		float cell_width, float cell_height,
		int sprite_id) :CGameObject(x, y)
	{
		this->cellWidth = cell_width;
		this->cellHeight = cell_height;
		this->spriteId = sprite_id;
	}
	void Render()
	{
		CSprites* s = CSprites::GetInstance();

		s->Get(this->spriteId)->Draw(x, y);

	};
	void Update(DWORD dt) {}
	int IsBlocking() { return 0; }
	void GetBoundingBox(float& l, float& t, float& r, float& b) {};
	void RenderBoundingBox() {};
};

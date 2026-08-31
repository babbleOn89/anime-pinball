#include "plunger.hpp"

Plunger::Plunger(Rectangle bounds)
    : bounds(bounds),
      startY(bounds.y),
      pullDistance(0.0f),
      maxPullDistance(80.0f),
      pullSpeed(120.0f)
{
}
    
void Plunger::Update(float dt)
{
    if(IsKeyDown(KEY_SPACE))
    {
        pullDistance += pullSpeed * dt;
        if(pullDistance > maxPullDistance)
        {
            pullDistance = maxPullDistance;
        }

        bounds.y = startY + pullDistance;
    }
}


void Plunger::Draw() const
{
    DrawRectangleRec(bounds, GRAY);
    DrawRectangleLinesEx(bounds, 2.0f, DARKGRAY);
}

float Plunger::GetPower() const
{
    return pullDistance / maxPullDistance;
}

void Plunger::Release()
{
    pullDistance = 0.0f;
    bounds.y = startY;
}

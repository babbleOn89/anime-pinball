#pragma once
#include "raylib.h"

class Ball
{
public:
    Ball(Vector2 startposition, float radius);

    void Update(float dt, float gravity);
    void Launch();
    void CheckWallCollision(Rectangle bounds);
    void Draw() const;

    void Reset(Vector2 startPosition);
    bool IsBelow(float y) const;
    void CheckLauncherFloor(float dividerX, float bottom);

private:
    Vector2 position;
    Vector2 velocity;
    float radius;
};

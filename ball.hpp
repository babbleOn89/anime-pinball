#pragma once
#include "raylib.h"

class Ball
{
public:
    Ball(Vector2 startposition, float radius);

    void Update(float dt, float gravity);
    void CheckWallCollision(int screenWidth, int screenHeight);
    void Draw() const;

private:
    Vector2 position;
    Vector2 velocity;
    float radius;
};

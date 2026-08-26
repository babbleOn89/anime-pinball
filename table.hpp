#pragma once
#include "raylib.h"

class Table
{
public:
    Table(int screenWidth, int screenHeight);

    void Draw() const;
    Rectangle GetOuterBounds() const;
    Vector2 GetBallStartPosition(float ballRadius) const;
    float GetLauncherDividerX() const;


private:
    Rectangle outerBounds;
    float launcherDividerX;

};

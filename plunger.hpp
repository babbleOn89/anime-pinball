#ifndef PLUNGER_HPP
#define PLUNGER_HPP
#include "raylib.h"

class Plunger
{
public:
    explicit Plunger(Rectangle bounds);

    void Update(float dt);
    void Draw() const;

    float GetPower() const;
    void Release();

private:
    Rectangle bounds;
    float startY;
    float pullDistance;
    float maxPullDistance;
    float pullSpeed;
};

#endif

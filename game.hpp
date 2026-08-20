#pragma once
#include "ball.hpp"

class Game
{
public:
    Game();

    void Update(float dt);
    void Draw() const;

private:
    static constexpr int screenWidth = 800;
    static constexpr int screenHeight = 600;
    static constexpr float gravity = 500.0f;

    Ball ball;
};


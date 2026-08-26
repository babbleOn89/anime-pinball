#pragma once
#include "ball.hpp"
#include "table.hpp"

class Game
{
public:
    Game();

    void Update(float dt);
    void Draw() const;

private:
    static constexpr int screenWidth = 800;
    static constexpr int screenHeight = 900;
    static constexpr float gravity = 500.0f;
    static constexpr float ballRadius = 15.0f;

    Table table;
    Ball ball;
};


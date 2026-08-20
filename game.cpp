#include "game.hpp"
#include "raylib.h"

Game::Game()
    : ball(
        {screenWidth / 2.0f, 100.0f},
        15.0f
        )
{
}

void Game::Update(float dt)
{
    if(IsKeyPressed(KEY_SPACE))
    {
        ball.Launch();
    }

    ball.Update(dt, gravity);
    ball.CheckWallCollision(screenWidth, screenHeight);
}

void Game::Draw() const
{
    ball.Draw();

    DrawText(
            "SPACE: Launch",
            20,
            20,
            20,
            LIGHTGRAY
            );
}


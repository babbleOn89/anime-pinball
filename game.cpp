#include "game.hpp"
#include "raylib.h"

Game::Game()
    : table(screenWidth, screenHeight),  
      ball(
        table.GetBallStartPosition(ballRadius),
        ballRadius
        )
{
}

void Game::Update(float dt)
{
    //launch the ball from launch area
    if(IsKeyPressed(KEY_SPACE))
    {
        ball.Launch();
    }

    ball.Update(dt, gravity);
    ball.CheckWallCollision(table.GetOuterBounds());

    const Rectangle bounds = table.GetOuterBounds();
    const float tableBottom = bounds.y + bounds.height;

    ball.CheckLauncherFloor(
            table.GetLauncherDividerX(),
            tableBottom
            );
    if(ball.IsBelow(screenHeight + 50.0f))
    {
        ball.Reset(
                table.GetBallStartPosition(ballRadius)
                );
    }
}

void Game::Draw() const
{
    table.Draw();
    ball.Draw();

    DrawText(
            "SPACE: Launch",
            20,
            20,
            20,
            LIGHTGRAY
            );
}


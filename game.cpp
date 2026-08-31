#include "game.hpp"
#include "raylib.h"

Game::Game()
    : table(screenWidth, screenHeight),  
      plunger(table.GetPlungerStartBounds()),
      ball(
        table.GetBallStartPosition(ballRadius),
        ballRadius
        )
{
}

void Game::Update(float dt)
{

    if(ballIsReadyToLaunch)
    {
        plunger.Update(dt);

        if(IsKeyReleased(KEY_SPACE))
        {
            float power = plunger.GetPower();
            ball.Launch(power);
            plunger.Release();

            ballIsReadyToLaunch = false;
        }
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
        ballIsReadyToLaunch = true;
    }
}

void Game::Draw() const
{
    table.Draw();
    plunger.Draw();

    ball.Draw();

    DrawText(
            "SPACE: Launch",
            20,
            20,
            20,
            LIGHTGRAY
            );
}


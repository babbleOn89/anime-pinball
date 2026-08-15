#include "raylib.h"
#include "ball.hpp"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Anime Pinball");

    SetTargetFPS(60);

    Ball ball(
            {screenWidth /2.0f, 100.0f},
            15.0f
            );

    const float gravity = 500.0f;

    while(!WindowShouldClose())
    {
        float dt = GetFrameTime();

        //update
        ball.Update(dt, gravity);

        //collision check
        ball.CheckWallCollision(screenWidth, screenHeight);

        //draw
        BeginDrawing();

        ClearBackground(BLACK);

        ball.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

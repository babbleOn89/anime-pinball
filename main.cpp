#include "raylib.h"
#include "game.hpp"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Anime Pinball");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        game.Update(dt);

        BeginDrawing();

        ClearBackground(BLACK);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

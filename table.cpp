#include "table.hpp"

Table::Table(int screenWidth, int screenHeight)
    : outerBounds({
            40.0f,
            50.0f,
            static_cast<float>(screenWidth -80),
            static_cast<float>(screenHeight -80)
            }),
        launcherDividerX(screenWidth - 150.0f)
{
}

Rectangle Table::GetOuterBounds() const
{
    return outerBounds;
}

Vector2 Table::GetBallStartPosition(float ballRadius) const
{
    const float rightWall = outerBounds.x + outerBounds.width;

    const float launcherCenterX =
        launcherDividerX + (rightWall - launcherDividerX) / 2.0f;

    const float launcherBottomY =
        outerBounds.y + outerBounds.height - ballRadius - 20.0f;

    return {
        launcherCenterX,
        launcherBottomY
        };
}

void Table::Draw() const
{
    const Color tableBackground = {12, 20, 45, 255};
    const Color wallColor = {40, 210, 255, 255};

    DrawRectangleRec(outerBounds, tableBackground);

    DrawRectangleLinesEx(
            outerBounds,
            4.0f,
            wallColor
            );
    DrawLineEx(
            {launcherDividerX, outerBounds.y + 130.0f},
            {launcherDividerX, outerBounds.y + outerBounds.height},
            4.0f,
            wallColor
            );
}

float Table::GetLauncherDividerX() const
{
    return launcherDividerX;
}

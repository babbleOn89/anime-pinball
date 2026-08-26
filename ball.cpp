#include "ball.hpp"

Color cyan = {0, 255, 255, 255};

Ball::Ball(Vector2 startPosition, float radius)
    : position(startPosition),
      velocity({0.0f, 0.0f}),
      radius(radius)
{
}

void Ball::Update(float dt, float gravity)
{
    velocity.y += gravity * dt;

    position.x += velocity.x *dt;
    position.y += velocity.y *dt;
}

void Ball::Launch()
{
    velocity.y = -700;
}

void Ball::CheckWallCollision(Rectangle bounds)
{
    const float leftWall = bounds.x;
    const float rightWall = bounds.x + bounds.width;
    const float topWall = bounds.y;

    if(position.x - radius <= leftWall)
    {
        position.x = leftWall + radius;
        velocity.x *= -1;
    }

    if(position.x + radius >= rightWall)
    {
        position.x = rightWall - radius;
        velocity.x *= -1;
    }

    if(position.y - radius <= topWall)
    {
        position.y = topWall + radius;
        velocity.y *= 01;
    }
}

void Ball::Draw() const
{
    DrawCircleV(position, radius, cyan);
}

void Ball::Reset(Vector2 startPosition)
{
    position = startPosition;
    velocity = {0.0f, 0.0f};
}

bool Ball::IsBelow(float y) const
{
    return position.y - radius > y;
}

void Ball::CheckLauncherFloor(float dividerX, float bottomY)
{
    const bool isInLauncherLane = position.x > dividerX;
    const bool touchedLauncherFloor = position.y + radius >= bottomY;

    if(isInLauncherLane && touchedLauncherFloor)
    {
        position.y = bottomY - radius;
        velocity.y = 0.0f;
    }
}


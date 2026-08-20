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

void Ball::CheckWallCollision(int screenWidth, int screenHeight)
{
    if(position.x - radius <= 0)
    {
        position.x = radius;
        velocity.x *= -1;
    }

    if(position.x + radius >= screenWidth)
    {
        position.x = screenWidth - radius;
        velocity.x *= -1;
    }

    if(position.y - radius <= 0)
    {
        position.y = radius;
        velocity.y *= -1;
    }

    if(position.y + radius >= screenHeight)
    {
        position.y = screenHeight - radius;
        velocity.y *= -0.8f;
    }
}

void Ball::Draw() const
{
    DrawCircleV(position, radius, cyan);
}


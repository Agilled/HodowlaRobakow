#include "Collider.h"

using namespace std;

Collider::Collider(Sprite& sprite)
	:body(sprite)
{
}

Collider::Collider(Vector2f position, Vector2f size):body(sp)
{
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider & other, float push)
{
	Vector2f otherPosition = other.GetPosition();
	Vector2f otherHalfSize = other.GetHalfSize();
	Vector2f thisPosition = GetPosition();
	Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX <= 0.0f && intersectY <= 0.0f)
	{
		push = min(max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f, intersectY *(1.0f - push));
				other.Move(0.0f, -intersectY * push);
			}
			else
			{
				Move(0.0f, -intersectY *(1.0f - push));
				other.Move(0.0f, intersectY * push);
			}
		}
		return true;
	}
	return false;
}

void Collider::Move(float dx, float dy)
{ 
	body.move(dx, dy);
}

Vector2f Collider::GetPosition()
{
	return body.getPosition();
}
Vector2f Collider::GetHalfSize()
{
	Vector2f size(body.getGlobalBounds().width / 2, body.getGlobalBounds().height / 2);
	return size;
}
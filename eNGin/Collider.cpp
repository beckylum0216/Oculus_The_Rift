#include <pch.h>

#include "Collider.h"
#include "Actor.h"


Collider::Collider() : minPoint(0, 0, 0),
					   maxPoint(0, 0, 0)
{

}

void Collider::SetMinPoint(double tempX, double tempY, double tempZ) 
{
	minPoint = Vector3(tempX, tempY, tempZ);
}

void Collider::SetMaxPoint(double tempX, double tempY, double tempZ) 
{
	maxPoint = Vector3(tempX, tempY, tempZ);
}

Vector3 Collider::GetMinPoint() 
{
	return minPoint;
}

Vector3 Collider::GetMaxPoint() 
{
	return maxPoint;
}

bool Collider::AABBtoAABB(Collider objectOther)
{
	return (	maxPoint.GetPointX() > objectOther.minPoint.GetPointX() &&
				minPoint.GetPointX() < objectOther.maxPoint.GetPointX() &&
				maxPoint.GetPointY() > objectOther.minPoint.GetPointY() &&
				minPoint.GetPointY() < objectOther.maxPoint.GetPointY() &&
				maxPoint.GetPointZ() > objectOther.minPoint.GetPointZ() &&
				minPoint.GetPointZ() < objectOther.maxPoint.GetPointZ());
}

bool Collider::operator < (Collider &other) 
{
	return AABBtoAABB(other);
}

bool Collider::operator > (Collider &other) 
{
	return !operator<(other);
}

bool Collider::ProximityCull(Vector3 actorPosition, Vector3 &inputObject)
{
	Vector3 positionOffset;
	Vector3 minCullBox;
	Vector3 maxCullBox;

	positionOffset = Vector3(4.0, 10.0, 4.0);
	minCullBox = actorPosition - positionOffset;
	maxCullBox = actorPosition + positionOffset;

	return (maxCullBox.GetPointX() > inputObject.GetPointX() &&
			minCullBox.GetPointX() < inputObject.GetPointX() &&
			maxCullBox.GetPointY() > inputObject.GetPointY() &&
			minCullBox.GetPointY() < inputObject.GetPointY() &&
			maxCullBox.GetPointZ() > inputObject.GetPointZ() &&
			minCullBox.GetPointZ() < inputObject.GetPointZ());
		
}

void Collider::CollideWith(Actor *thisObject, Actor &otherObject)
{
	float intersectX = thisObject->GetPos().GetPointX() - otherObject.GetPos().GetPointX();
	float intersectZ = thisObject->GetPos().GetPointZ() - otherObject.GetPos().GetPointZ();

	if (abs(intersectX) > abs(intersectZ))
	{
		if (intersectX > 0)
		{
			thisObject->SetPos(otherObject.GetCollider().GetMaxPoint().GetPointX() + 0.5, thisObject->GetPos().GetPointY(), thisObject->GetPos().GetPointZ());
		}
		else
		{
			thisObject->SetPos(otherObject.GetCollider().GetMinPoint().GetPointX() - 0.5, thisObject->GetPos().GetPointY(), thisObject->GetPos().GetPointZ());
		}
	}
	else
	{
		if (intersectZ > 0)
		{
			thisObject->SetPos(thisObject->GetPos().GetPointX(), thisObject->GetPos().GetPointY(), otherObject.GetCollider().GetMaxPoint().GetPointZ() + 0.5);
		}
		else
		{
			thisObject->SetPos(thisObject->GetPos().GetPointX(), thisObject->GetPos().GetPointY(), otherObject.GetCollider().GetMinPoint().GetPointZ() - 0.5);
		}
	}
}

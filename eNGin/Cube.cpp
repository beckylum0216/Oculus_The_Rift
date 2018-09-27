#include <pch.h>

#include <algorithm>
#include <math.h>

#include "Cube.h"

Vector3 theMin;
Vector3 theMax;

Cube::Cube() {
	vertices[0] = Vector3( -1.0, -1.0, -1.0 );
	vertices[1] = Vector3( 1.0, -1.0, -1.0 );
	vertices[2] = Vector3( 1.0, 1.0, -1.0 );
	vertices[3] = Vector3( -1.0, 1.0, -1.0 );
	vertices[4] = Vector3( -1.0, -1.0, 1.0 );
	vertices[5] = Vector3( 1.0, -1.0, 1.0 );
	vertices[6] = Vector3( 1.0, 1.0, 1.0 );
	vertices[7] = Vector3( -1.0, 1.0, 1.0 );

	colours[0] = { 0, 0, 0 };
	colours[1] = { 1, 0, 0 };
	colours[2] = { 1, 1, 0 };
	colours[3] = { 0, 1, 0 };
	colours[4] = { 0, 0, 1 };
	colours[5] = { 1, 0, 1 };
	colours[6] = { 1, 1, 1 };
	colours[7] = { 0, 1, 1 };
}




void Cube::Update() {
	/*for (int i = 0; i < 8; i++) {
		vertices[i].x += 0.0001;
		vertices[i].z += 0.0001;
	}*/

}

void Cube::Draw()  
{
	Polygons(0, 3, 2, 1);
	Polygons(2, 3, 7, 6);
	Polygons(0, 4, 7, 3);
	Polygons(1, 2, 6, 5);
	Polygons(4, 5, 6, 7);
	Polygons(0, 1, 5, 4);
}

void Cube::Polygons(int a, int b, int c, int d) {
	glBegin(GL_POLYGON);
		glColor3f(colours[a].r, colours[a].g, colours[a].b);
		glVertex3f(vertices[a].GetPointX(), vertices[a].GetPointY(), vertices[a].GetPointZ());

		glColor3f(colours[b].r, colours[b].g, colours[b].b);
		glVertex3f(vertices[b].GetPointX(), vertices[b].GetPointY(), vertices[b].GetPointZ());

		glColor3f(colours[c].r, colours[c].g, colours[c].b);
		glVertex3f(vertices[c].GetPointX(), vertices[c].GetPointY(), vertices[c].GetPointZ());

		glColor3f(colours[d].r, colours[d].g, colours[d].b);
		glVertex3f(vertices[d].GetPointX(), vertices[d].GetPointY(), vertices[d].GetPointZ());
	glEnd();
}

void Cube::SetRot(Vector3 rot)
{
	rotations.SetPointX(rot.GetPointX());
	rotations.SetPointY(rot.GetPointY());
	rotations.SetPointZ(rot.GetPointZ());

	SetAABB();
}

void Cube::SetRot(GLdouble rotX, GLdouble rotY, GLdouble rotZ)
{
	rotations.SetPointX(rotX);
	rotations.SetPointY(rotY);
	rotations.SetPointZ(rotZ);

	SetAABB();
}

void Cube::CalculateFaceNormal(Vector3 *AABBVertices)
{
	//forwards & backwards
	Vector3 A = AABBVertices[0];
	Vector3 B = AABBVertices[1];
	Vector3 C = AABBVertices[2];
	Vector3 X = A.SubtractVector(B);
	Vector3 Y = C.SubtractVector(B);

	normals[0] = X.CrossProduct(Y);
	normals[1] = normals[0];

	//left & right
	A = AABBVertices[5];
	B = AABBVertices[1];
	C = AABBVertices[2];
	X = A.SubtractVector(B);
	Y = C.SubtractVector(B);

	normals[2] = X.CrossProduct(Y);
	normals[3] = normals[2];

	//top & bottom
	A = AABBVertices[3];
	B = AABBVertices[2];
	C = AABBVertices[6];
	X = A.SubtractVector(B);
	Y = C.SubtractVector(B);

	normals[4] = X.CrossProduct(Y);
	normals[5] = normals[4];
	normals[5].SetPointY(-normals[5].GetPointY());
}

void Cube::SetAABB()
{
	Vector3 * AABBVertices;

	AABBVertices = new Vector3[8];

	for (int ii = 0; ii < 8; ii++)
	{
		//this is a hack should use dot product, but scale type is point


		AABBVertices[ii].SetPointX((vertices[ii].GetPointX() * scale.GetPointX()) + GetPos().GetPointX());
		AABBVertices[ii].SetPointY((vertices[ii].GetPointY() * scale.GetPointY()) + GetPos().GetPointY());
		AABBVertices[ii].SetPointZ((vertices[ii].GetPointZ() * scale.GetPointZ()) + GetPos().GetPointZ());

		std::cout << "index: " << ii << " AABB vertex X:" << AABBVertices[ii].GetPointX() << std::endl;
		std::cout << "index: " << ii << " AABB vertex Y:" << AABBVertices[ii].GetPointY() << std::endl;
		std::cout << "index: " << ii << " AABB vertex Z:" << AABBVertices[ii].GetPointZ() << std::endl;

	}

	CalculateFaceNormal(AABBVertices);

	//Set the points for theMin and theMax so that it's values are specific to the cube
	theMin.SetPointX(AABBVertices[0].GetPointX());
	theMin.SetPointY(AABBVertices[0].GetPointY());
	theMin.SetPointZ(AABBVertices[0].GetPointZ());

	theMax.SetPointX(AABBVertices[0].GetPointX());
	theMax.SetPointY(AABBVertices[0].GetPointY());
	theMax.SetPointZ(AABBVertices[0].GetPointZ());
	
	for (int ii = 0; ii < 8; ii++)
	{
		if (AABBVertices[ii].GetPointX() < theMin.GetPointX())
		{
			theMin.SetPointX(AABBVertices[ii].GetPointX());
		}

		if (AABBVertices[ii].GetPointY() < theMin.GetPointY())
		{
			theMin.SetPointY(AABBVertices[ii].GetPointY());
		}

		if (AABBVertices[ii].GetPointZ() < theMin.GetPointZ())
		{
			theMin.SetPointZ(AABBVertices[ii].GetPointZ());
		}

		if (AABBVertices[ii].GetPointX() > theMax.GetPointX())
		{
			theMax.SetPointX(AABBVertices[ii].GetPointX());
		}

		if (AABBVertices[ii].GetPointY() > theMax.GetPointY())
		{
			theMax.SetPointY(AABBVertices[ii].GetPointY());
		}

		if (AABBVertices[ii].GetPointZ() > theMax.GetPointZ())
		{
			theMax.SetPointZ(AABBVertices[ii].GetPointZ());
		}

	}


	collisionBox.SetMaxPoint(theMax.GetPointX(), theMax.GetPointY(), theMax.GetPointZ());
	collisionBox.SetMinPoint(theMin.GetPointX(), theMin.GetPointY(), theMin.GetPointZ());
	
	
	std::cout << "minPoint x: " << collisionBox.GetMinPoint().GetPointX() << std::endl;
	std::cout << "minPoint y: " << collisionBox.GetMinPoint().GetPointY() << std::endl;
	std::cout << "minPoint Z: " << collisionBox.GetMinPoint().GetPointZ() << std::endl;

	std::cout << "maxPoint x: " << collisionBox.GetMaxPoint().GetPointX() << std::endl;
	std::cout << "maxPoint y: " << collisionBox.GetMaxPoint().GetPointY() << std::endl;
	std::cout << "maxPoint Z: " << collisionBox.GetMaxPoint().GetPointZ() << std::endl;
	
}




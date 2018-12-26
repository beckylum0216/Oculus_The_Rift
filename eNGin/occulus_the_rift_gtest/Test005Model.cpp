#include "pch.h"

#include "Texture.h"
#include "Model.h"


TEST(TestSuite005_ModelTesting, ModelTest000_TestObjectCreationandDestruction)
{
	Model* mod;

	SUCCEED();
}


TEST(TestSuite005_ModelTesting, ModelTest001_TestObjectCreationandDestruction)
{
	Model* mod;

	mod = new Model("data/portal.obj");

	delete mod;

	SUCCEED();
}


TEST(TestSuite005_ModelTesting, ModelTest002_DrawModel)
{
	Texture tex;

	tex.LoadTexture("data/portal.png", 128, 128);

	Model* mod;

	mod = new Model("data/portal.obj");

	mod->DrawModel(0, 0, 0, tex.GetTexture(), tex.GetWidth(), tex.GetHeight());

	SUCCEED();
}


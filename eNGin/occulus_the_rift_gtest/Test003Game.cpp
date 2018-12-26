#include "pch.h"

#include <Game.h>

#include "Texture.h"
#include "Model.h"
#include "Shay.h"
#include "MusicPlayer.h"

TEST(TestSuite003_GameTesting, DISABLED_GameTest001_GameCreation)
{
	Game theGame;
	theGame.Initialise();

	SUCCEED();
}

TEST(TestSuite003_GameTesting, DISABLED_GameTest002_GameInitialisation)
{
	Game theGame;

	theGame.Initialise();
	theGame.GetMenu()->Init();
	theGame.Run();


	SUCCEED();
}

TEST(TestSuite003_GameTesting, GameTest003_TestObjectInitialise)
{
	Game game;

	game.SetState(LOAD_STATE);
	game.Initialise();
	game.GetMenu()->Init();
	game.Run();

	SUCCEED();
}

TEST(TestSuite003_GameTesting, GameTest004_TestKeyPressW)
{
	Game game;
	game.Initialise();
	game.GetMenu()->Init();
	game.Run();
	game.InputDown('W', 0, 0);

	SUCCEED();
}

TEST(TestSuite003_GameTesting, GameTest005_TestKeyPressA)
{
	Game game;
	game.Initialise();
	game.GetMenu()->Init();
	game.Run();
	game.InputDown('A', 0, 0);

	SUCCEED();
}

TEST(TestSuite003_GameTesting, GameTest006_TestKeyPressS)
{
	Game game;
	game.Initialise();
	game.GetMenu()->Init();
	game.Run();
	game.InputDown('S', 0, 0);

	SUCCEED();
}

TEST(TestSuite003_GameTesting, GameTest007_TestKeyPressD)
{
	Game game;
	game.Initialise();
	game.GetMenu()->Init();
	game.Run();
	game.InputDown('D', 0, 0);

	SUCCEED();
}

TEST(TestSuite003_GameTesting, GameTest008_TestKeyReleaseW)
{
	Game game;
	game.Initialise();
	game.GetMenu()->Init();
	game.InputUp('W', 0, 0);

	SUCCEED();
}

TEST(TestSuite003_GameTesting, GameTest009_TestKeyReleaseA)
{
	Game game;
	game.Initialise();
	game.GetMenu()->Init();
	game.Run();
	game.InputUp('A', 0, 0);

	SUCCEED();
}

TEST(TestSuite003_GameTesting, GameTest010_TestKeyReleaseS)
{
	Game game;
	game.Initialise();
	game.GetMenu()->Init();
	game.Run();
	game.InputUp('S', 0, 0);

	SUCCEED();
}

TEST(TestSuite003_GameTesting, GameTest011_TestKeyReleaseD)
{
	Game game;
	game.Initialise();
	game.GetMenu()->Init();
	game.Run();
	game.InputUp('D', 0, 0);

	SUCCEED();
}

TEST(TestSuite003_GameTesting, GameTest012_TestMouseMoveUp)
{
	Game game;
	game.Initialise();
	game.GetMenu()->Init();
	game.Run();
	game.MouseLook(400, 250);

	game.MouseLook(400, 200);

	SUCCEED();
}

TEST(TestSuite003_GameTesting, GameTest013_TestMouseMoveDown)
{
	Game game;
	game.Initialise();
	game.GetMenu()->Init();
	game.Run();
	game.MouseLook(400, 250);

	game.MouseLook(400, 300);

	SUCCEED();
}

TEST(TestSuite003_GameTesting, GameTest014_TestMouseMoveLeft)
{
	Game game;
	game.Initialise();
	game.GetMenu()->Init();
	game.Run();
	game.MouseLook(400, 250);

	game.MouseLook(350, 250);

	SUCCEED();
}

TEST(TestSuite003_GameTesting, GameTest015_TestMouseMoveRight)
{
	Game game;
	game.Initialise();
	game.GetMenu()->Init();
	game.Run();
	game.MouseLook(400, 250);

	game.MouseLook(450, 250);

	SUCCEED();
}

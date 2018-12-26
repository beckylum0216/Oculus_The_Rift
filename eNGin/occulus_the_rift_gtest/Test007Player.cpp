
#include <math.h>

#include "pch.h"
#include <Player.h>
#include <Vector3.h>
#include <Quarternion.h>


TEST(TestSuite007_PlayerTesting, PlayerTest001_PlayerCreation)
{
	Player* thePlayer;

	SUCCEED();
}

TEST(TestSuite007_PlayerTesting, PlayerTest002_ChangeMovementSpeed)
{
	Player* thePlayer;

	thePlayer = Player::GetInstance();

	thePlayer->SetMoveSpeed(1);

	EXPECT_EQ(1, thePlayer->GetMoveSpeed());

}

TEST(TestSuite007_PlayerTesting, PlayerTest003_ChangeRotationSpeed)
{
	Player* thePlayer;

	thePlayer = Player::GetInstance();

	thePlayer->SetRotateSpeed(1);

	EXPECT_EQ(1, thePlayer->GetRotateSpeed());

}

TEST(TestSuite007_PlayerTesting, PlayerTest004_ChangeRotationSpeed)
{
	Player* thePlayer;

	thePlayer = Player::GetInstance();

	thePlayer->SetRotateSpeed(1);

	EXPECT_EQ(1, thePlayer->GetRotateSpeed());

}

TEST(TestSuite007_PlayerTesting, PlayerTest009_GetPosition)
{
	Player* thePlayer;

	thePlayer = Player::GetInstance();

	thePlayer->SetPos(Vector3(1,1,1));

	EXPECT_EQ(1, thePlayer->GetFB());
	EXPECT_EQ(1, thePlayer->GetLR());
	EXPECT_EQ(1, thePlayer->GetUD());

}

TEST(TestSuite007_PlayerTesting, PlayerTest009_GetScale)
{
	Player* thePlayer;

	thePlayer = Player::GetInstance();

	thePlayer->SetScale(Vector3(1,1,1));
	
	EXPECT_EQ(1, thePlayer->GetScale().GetPointX());
	EXPECT_EQ(1, thePlayer->GetScale().GetPointY());
	EXPECT_EQ(1, thePlayer->GetScale().GetPointZ());

}
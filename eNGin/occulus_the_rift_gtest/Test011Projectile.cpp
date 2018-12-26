#include "pch.h"
#include <Projectile.h>
#include <Player.h>
#include <Model.h>
#include <Texture.h>
#include <Vector3.h>


TEST(TestSuite011_ProjectileTesting, ProjectileTest001_ProjectileCreation)
{
	Player * thePlayer;
	Model* models = new  Model("data/laser.obj");;
	Texture *textures = new Texture();

	textures->LoadTexture("data/player_laser.png", 32, 32);

	thePlayer = Player::GetInstance();

	Projectile* theProjectile = new Projectile(thePlayer, models, textures, 1.0, Vector3(1,1,1), Vector3(2,2,2), false );


	SUCCEED();
}
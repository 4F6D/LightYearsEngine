#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
	{
		// Here happens the Game Programming Magic


		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		actorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		counter = 0;
	}
	void GameApplication::Tick(float deltaTime)
	{

		// TESTING
		counter += deltaTime;
		if (counter > 2.f)
		{
			if (!actorToDestroy.expired())
			{
				actorToDestroy.lock()->Destroy();
			}
		}
	}
}
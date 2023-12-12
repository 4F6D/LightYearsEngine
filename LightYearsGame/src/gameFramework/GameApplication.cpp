#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication() :
		Application{600, 980, "Light Years Demo Game", sf::Style::Close}
	{
		// YOUR CODE GOES HERE


		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		actorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		actorToDestroy.lock()->SetTexture("C:/Users/rener/Desktop/Spaceship_DEMO.png");
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
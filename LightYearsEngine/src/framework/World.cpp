#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace ly
{
	World::World(Application* owningApp) :
		mOwningApp{ owningApp },
		mBeganPlay(false),
		mActors{},
		mPendingActors{}
	{

	}

	void World::BeginPlayInternal()
	{
		if (!mBeganPlay)
		{
			mBeganPlay = true;
			BeginPlay();
		}
	}

	void World::TickInternal(float deltaTime)
	{
		for (shared<Actor> actor : mPendingActors)
		{
			mActors.push_back(actor);
			actor->BeginPlayInternal();
		}

		mPendingActors.clear();

		for (shared<Actor> actor : mActors)
		{
			actor->Tick(deltaTime);
		}

		Tick(deltaTime);
	}

	// Destructor
	World::~World()
	{

	}

	void World::BeginPlay()
	{
		LOG("Began play");
	}

	void World::Tick(float deltaTime)
	{
		LOG("Ticking at %f", 1.f / deltaTime, "frames");
	}
}



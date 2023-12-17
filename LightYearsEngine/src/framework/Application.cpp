#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "framework/AssetManager.h"

namespace ly {
	Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 windowStyle) : 
		mWindow{ sf::VideoMode(windowWidth,windowHeight), title, windowStyle },
		mTargetFrameRate{ 60.f },		// 60 for PC, 30 for Console
		mTickClock{},
		currentWorld{ nullptr },
		mCleanCycleClock{},
		mCleanCycleInterval{2.f}
	{

	}

	void Application::Run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / mTargetFrameRate;		// DeltaTime

		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					mWindow.close();
				}
			}

			accumulatedTime += mTickClock.restart().asSeconds();
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
		}
	}

	// Tick template function
	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
	
		if (currentWorld)
		{
			currentWorld->BeginPlayInternal();
			currentWorld->TickInternal(deltaTime);
		}

		if (mCleanCycleClock.getElapsedTime().asSeconds() >= mCleanCycleInterval)
		{
			mCleanCycleClock.restart();
			AssetManager::Get().CleanCycle();
		}
	}

	// Render template function
	void Application::RenderInternal()
	{
		/* Running once per frame */

		mWindow.clear();		// Clear the window

		Render();				// Calling Render

		mWindow.display();		// Display change
	}

	// Render function
	void Application::Render()
	{
		/* CAN BE OVERWRITTEN */
		
		if (currentWorld)
		{
			currentWorld->Render(mWindow);
		}
	}

	// Tick function
	void Application::Tick(float deltaTime)
	{
		/* CAN BE OVERWRITTEN */

		// Logging the framerate
		LOG("Ticking at framerate: %f", 1.f / deltaTime);
	}
}
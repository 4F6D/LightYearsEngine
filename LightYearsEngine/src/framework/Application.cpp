#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"

namespace ly {
	Application::Application() :
		mWindow{ sf::VideoMode(1080,720), "Light Years" },
		mTargetFrameRate{60.f},		// 60 for PC, 30 for Console
		mTickClock{},
		currentWorld{nullptr}
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

		// Test rect
		sf::RectangleShape rect{ sf::Vector2f{100,100} };
		rect.setFillColor(sf::Color::Blue);
		rect.setOrigin(50, 50);		// Set Origin in the center

		// Drawing the Rect in the center
		rect.setPosition(sf::Vector2f{ mWindow.getSize().x / 2.f , mWindow.getSize().y / 2.f });

		mWindow.draw(rect);		// Drawing the Rectangle
	}

	// Tick function
	void Application::Tick(float deltaTime)
	{
		/* CAN BE OVERWRITTEN */

		// Logging the framerate
		LOG("Ticking at framerate: %f", 1.f / deltaTime);
	}
}
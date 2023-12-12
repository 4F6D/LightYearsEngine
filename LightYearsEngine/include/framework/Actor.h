#pragma once
#include "framework/Object.h"
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace ly
{
	class World;
	class Actor : public Object 
	{
	public:
		Actor(World* owningWorld, const std::string& texturePath = "");
		virtual ~Actor();
		
		void TickInternal(float deltaTime);
		void BeginPlayInternal();
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		void SetTexture(const std::string& texturePath);
		void Render(sf::RenderWindow& window);

	private:
		World* mOwningWorld;
		bool mHasBeganPlay;

		sf::Sprite mSprite;		// Sprite of the Actor
		sf::Texture mTexture;	// Texture of the Actor

	};
}
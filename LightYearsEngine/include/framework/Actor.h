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

		void SetActorLocation(const sf::Vector2f& newLoc);
		void SetActorRotation(float newRot);
		void AddActorLocationOffset(const sf::Vector2f& offsetAmt);
		void AddActorRotationOffset(float offsetAmt);

		sf::Vector2f GetActorLocation() const;
		float GetActorRotation() const;
		sf::Vector2f GetActorForwardDirection() const;
		sf::Vector2f GetActorRightDirection() const;

	private:
		void CenterPivot();
		World* mOwningWorld;
		bool mHasBeganPlay;

		sf::Sprite mSprite;		// Sprite of the Actor
		shared<sf::Texture> mTexture;	// Texture of the Actor

	};
}
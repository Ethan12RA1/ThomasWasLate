#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"

using namespace sf;

class Engine
{
private:
	//Texture Holder 
	TextureHolder th;
	//Thomas and his friend Bob 
	Thomas m_Thomas;
	Bob m_Bob;
	const int TILE_SIZE = 50;
	const int VERT_IN_QUAD = 4;

	//The force pushing the characters down 
	const int GRAVITY = 300;

	//A regular RenderWindow
	sf::RenderWindow m_Window;

	//The main views
	sf::View m_MainView;
	sf::View m_LeftView;
	sf::View m_RightView;

	//Three views for the background
	sf::View m_BGMainView;
	sf::View m_BGLeftView;
	sf::View m_BGRightView;
	sf::View m_HUDView;

	//Declare a sprite and a texture
	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	//Is the game currently playing
	bool m_IsPlaying = false;

	//Is character 1 or 2 the current focus
	bool m_Character1 = true;

	//Start in full screen mode
	bool m_IsSplitScreen = false;

	//Is it time for a new level 
	bool m_NewLevelRequired = true;

	//Time left in the current level (seconds)
	float m_TimeRemaining = 10;
	sf::Time m_GameTimeTotal;

	//Private functions for internal use only 
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	//Engine constructor 
	Engine();
	//Run will call all the private functions 
	void run();
};

#endif ENGINE_H


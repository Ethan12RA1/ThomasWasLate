#include "Engine.h"

void Engine::draw()
{
	//Rub out the last frame 
	m_Window.clear(sf::Color::White);

	if (!m_IsSplitScreen)
	{
		//Switch to background view
		m_Window.setView(m_BGMainView);
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		//Switch to the main view
		m_Window.setView(m_MainView);
	}
	else
	{
		//Split-screen view is active 
		//First draw Thomas's side of the screen 
		//Switch to background view 
		m_Window.setView(m_BGLeftView);
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		//Switch to m_LeftView
		m_Window.setView(m_LeftView);

		//Now draw Bob's side of the screen 
		//Switch to background view
		m_Window.setView(m_BGRightView);
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		//Switch to m_RightView
		m_Window.setView(m_RightView);
	}

	//Draw the HUD
	//Switch to m_HUDView
	m_Window.setView(m_HUDView);

	//Show everything we have just drawn
	m_Window.display();
}

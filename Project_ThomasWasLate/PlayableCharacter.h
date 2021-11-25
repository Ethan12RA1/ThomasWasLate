#ifndef PLAYABLE_CHARACTER_H
#define PLAYERABLE_CHARACTER_H
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter
{
protected:
	//We will need a sprite 
	Sprite m_sprite;
	//How long does the jump last 
	float m_JumpDuration;
	//Is the character currently jumping or falling 
	bool m_IsJumping;
	bool m_IsFalling;
	//Which direction is the character currently moving in 
	bool m_LeftPressed;
	bool m_RightPressed;
	//How long has the jump lasted so far 
	float m_TimeThisJump;
	//Has the player just initiated a jump 
	bool m_JustJumped = false;

private:
	//What is the gravity 
	float m_Gravity;
	//How fast is the character 
	float m_speed = 400;
	//Where is the player 
	Vector2f m_Position;
	//Where are the charaters various body parts?
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;
	//Add a texture
	Texture m_texture;

public:
	void spawn(Vector2f startPosition, float gravity);
	//This is a pure virtual function 
	bool virtual handleInput() = 0;
	//This class is now abstract and cannot be instantiated 
	//Where is the player 
	FloatRect getPosition();
	//A rectangle representing the position 
	//of a different parts of the sprite 
	FloatRect getFeet();
	FloatRect getHeed();
	FloatRect getRight();
	FloatRect getLeft();
	//Send a copy of the sprite to main 
	Sprite getSprite();
	//Make the character stand firm 
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();
	//Where is the center of the character 
	Vector2f getCenter();
	//We will call this function once every frame 
	void update(float elapsedTime);

};//End of the class


#endif PLAYABLE_CHARACTER_H


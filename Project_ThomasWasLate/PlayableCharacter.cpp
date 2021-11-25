#include "PlayableCharacter.h"

void PlayableCharacter::spawn(Vector2f startPosition, float gravity)
{
	//Place the player at the starting the point 
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;
	//Initialize the gravity 
	m_Gravity = gravity;
	//Move the sprite in to position 
	m_sprite.setPosition(m_Position);
}

void PlayableCharacter::update(float elapsedTime)
{
	if (m_RightPressed)
	{
		m_Position.x += m_speed * elapsedTime;
	}
	if (m_LeftPressed)
	{
		m_Position.x -= m_speed * elapsedTime;
	}
	//Handle the jumping 
	if (m_IsJumping)
	{
		//Update how long the jump has been going 
		m_TimeThisJump += elapsedTime;
		//Is the jump going upwards 
		if (m_TimeThisJump < m_JumpDuration)
		{
			//Move up at twice gravity 
			m_Position.y -= m_Gravity * 2 * elapsedTime;
		}
		else
		{
			m_IsJumping = false;
			m_IsFalling = true;
		}
	}
	//Apply gravity 
	if (m_IsFalling)
	{
		m_Position.y += m_Gravity * elapsedTime;
	}
	//Update the rect for all body parts 
	FloatRect r = getPosition();

	//Feet 
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height - 1;
	m_Feet.width = r.width - 6;
	m_Feet.height = 1;
	//Head 
	m_Head.left = r.left;
	m_Head.top = r.top + (r.height * .3);
	m_Head.width = r.width;
	m_Head.height = 1;
	//Right 
	m_Right.left = r.left + r.width - 2;
	m_Right.top = r.top + r.height * .35;
	m_Right.width = 1;
	m_Right.height = r.height * .3;
	//Left 
	m_Left.left = r.left;
	m_Left.top = r.top + r.height * .5;
	m_Left.width = 1;
	m_Left.height = r.height * .3;
}

FloatRect PlayableCharacter::getPosition()
{
	return m_sprite.getGlobalBounds();
}

Vector2f PlayableCharacter::getCenter()
{
	return Vector2f(
		m_Position.x + m_sprite.getGlobalBounds().width / 2,
		m_Position.y + m_sprite.getGlobalBounds().height / 2);
}

FloatRect PlayableCharacter::getFeet()
{
	return m_Feet;
}

FloatRect PlayableCharacter::getHeed()
{
	return m_Head;
}
FloatRect PlayableCharacter::getLeft()
{
	return m_Left;
}

FloatRect PlayableCharacter::getRight()
{
	return m_Right;
}

Sprite PlayableCharacter::getSprite()
{
	return m_sprite;
}

void PlayableCharacter::stopFalling(float position)
{
	m_Position.y = position - getPosition().height;
	m_sprite.setPosition(m_Position);
	m_IsFalling = false;
}

void PlayableCharacter::stopRight(float position)
{
	m_Position.x = position - m_sprite.getGlobalBounds().width;
	m_sprite.setPosition(m_Position);
}

void PlayableCharacter::stopLeft(float position)
{
	m_Position.x = position + m_sprite.getGlobalBounds().width;
	m_sprite.setPosition(m_Position);
}

void PlayableCharacter::stopJump()
{
	//Stop a jump early 
	m_IsFalling = false;
	m_IsFalling = true;
}


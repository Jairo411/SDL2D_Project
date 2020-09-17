#include "Input.h"
#include <SDL.h>

Collider* Input::mouseClick = new Collider();
int Input::mouseX = 0, Input::mouseY = 0;

Input::~Input()
{
}

bool Input::keyPressed(int is_pressed,int keycode)
{
	if (SDL_PRESSED == is_pressed)
	{
		if (SDL_KEYDOWN)
		{
			/* You should add this to your player class then send the keycode to another function
		 Function within a function*/
			InputKeyBoardHolder.insert(std::pair<int, bool>(keycode, true));	
			return true;
		}
		return false;
	}
	else if (SDL_RELEASED)
	{
		if (SDL_KEYUP)
		{
			keycode = NULL;
			InputKeyBoardHolder.insert(std::pair<int, bool>(keycode, false));
			return true;
		}
	}
	return false;
}

bool Input::MousePressed(int is_Pressed, int keycode)
{
	InputMouseHolder.clear();
	if (SDL_PRESSED== is_Pressed)
	{
		if (SDL_MOUSEBUTTONDOWN)
		{
			SDL_GetMouseState(&mouseX, &mouseY);
			InputMouseHolder.insert(std::pair<int, bool>(keycode, true));
			std::cout << "X: " << mouseX << "Y: " << mouseY << std::endl;
			return true;
		}
	}
	else if (SDL_RELEASED== is_Pressed)
	{
		if (SDL_MOUSEBUTTONUP)
		{
			InputMouseHolder.insert(std::pair<int, bool>(keycode, false));
			return true;
		}
	}
	return false;
}

bool Input::createCollider(bool state_)
{
	if (state_==true)
	{
		mouseClick = new Collider(mouseX, mouseY, 10);
	}
	else if (state_==false)
	{
		mouseClick = NULL;
	}
	return false;
}



#include "Input.h"
#include <SDL.h>
Input::~Input()
{
}

bool Input::keyPressed(int is_pressed,int keycode)
{
	if (SDL_PRESSED == is_pressed)
	{
<<<<<<< HEAD
		if (SDL_KEYDOWN)
		{
			/* You should add this to your player class then send the keycode to another function
		 Function within a function*/
			InputKeyBoardHolder.insert(std::pair<int, bool>(keycode, true));	
			return true;
		}
<<<<<<< HEAD
=======
		InputHolder->insert(std::pair<int,bool>(keycode,true));
		return true;
>>>>>>> parent of e7eaafc... 2020-08-26 9:35 PM
||||||| 50f9777
=======
		InputHolder->insert(std::pair<int,bool>(keycode,true));
		return true;
>>>>>>> 48d7615b797d99609e19fadd6cf40cd1ccacf523
	}
	else if (SDL_RELEASED)
	{
<<<<<<< HEAD
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
<<<<<<< HEAD
<<<<<<< HEAD

bool Input::createCollider(bool state_)
{
	if (state_==true)
	{
		mouseClick = new Collider(mouseX, mouseY, 10);
	}
	else if (state_==false)
	{
		mouseClick = NULL;
=======
		keycode = NULL;
		InputHolder->insert(std::pair<int, bool>(keycode, false));
		return true;
>>>>>>> parent of e7eaafc... 2020-08-26 9:35 PM
	}
	return false;
}
||||||| 50f9777
=======

bool Input::createCollider(bool state_)
{
	if (state_==true)
	{
		mouseClick = new Collider(mouseX, mouseY, 10);
	}
	else if (state_==false)
	{
		mouseClick = NULL;
		keycode = NULL;
		InputHolder->insert(std::pair<int, bool>(keycode, false));
		return true;
	}
	return false;
}
>>>>>>> 48d7615b797d99609e19fadd6cf40cd1ccacf523
||||||| c9d9634... 2020-09-03

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
=======
>>>>>>> parent of c9d9634... 2020-09-03

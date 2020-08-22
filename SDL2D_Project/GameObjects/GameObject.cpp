#include "GameObject.h"
#include "../TextureManager/TextureManager.h"
GameObject::GameObject()
{
	posX = 0;
	posY = 0;
	disableObject = false;
	nameID = "";
//	Going to use the Gameobject base class to check if inhereted object has name or not
}

bool GameObject::intiAnimation(const char* AnimTxtFile)
{
	/*
	This checks to see if Animations or textures are in the 2D Vector object.
	if Gameobject has no Animation textures then function returns false.
	*/
	if (animationSet.size()==0)
	{
			string textReader;
			string fileElements;
			ifstream input;
			input.open(AnimTxtFile);
			
		
			/*Reads txt and checks if has A:
			A's will in the next line will have a const char locations that will read and input those values inside a a map/vector.
			the filestream will check a line in the file, if there is a N which will mean new animation set, and place it inside a new col/row  of a 2D map/vector.
			 */
			if (input.is_open())
			{
				int index=0;
				vector<SDL_Texture*> newSet;
				animationSet.push_back(newSet);
				do
				{
					input >> textReader;
					if (textReader.at(0) == 'a')
					{
						string tempRelativeDir;
						fileElements = textReader;
						tempRelativeDir = "./Assets/Character/Sprites/" + fileElements;
						animationSet.at(index).push_back(TextureManager::LoadTexture(tempRelativeDir.c_str()));
					}
					else if (textReader.at(0) == 'N')
					{
						index++;
						vector<SDL_Texture*> newSet;
						animationSet.push_back(newSet);
					}

				} while (textReader.at(0)!='E');
			}
		
		return true;
	}
	return false;
}

int GameObject::ReadAmountOfAnimations()
{
	return 0;
}

bool GameObject::setDisable(bool temp)
{
	return temp;
}

bool GameObject::getDisable()
{
	if (disableObject==true)
	{
		return true;
	}
	return false;	
}

int GameObject::getX()
{
	return posX;
}

int GameObject::getY()
{
	return posY;
}

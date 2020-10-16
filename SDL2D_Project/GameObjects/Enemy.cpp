#include "Enemy.h"
#include "../Game/Game.h"
Enemy::~Enemy()
{
}



void Enemy::Disable()
{

}



void Enemy::ChangeSrcSize(int src_w, int src_h)
{
	src_w = srcRect.h;
	src_h = srcRect.w;
	
}

Skeleton::Skeleton()
{

}

Skeleton::Skeleton(int x, int y)
{
	setPosition(x, y);
	speed = 40;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect0.x = 0;
	destRect0.y = 0;
	srcRect0.w = 55;
	srcRect0.h = 55;

	objTexture = nullptr;
	srcRect.w = 40;
	srcRect.h = 40;

	destRect.x = srcRect.x;
	destRect.y = srcRect.y;

	ptr = this;
	col = Collider(55);
	GameObject::ObjHolder.push_back(ptr);
	Inti();
}

Skeleton::~Skeleton()
{
}

void Skeleton::Inti()
{
	SDL_Texture* tempIMG;
	SDL_Texture* actualIMG;


	intiAnimation("C:/Users/jalbm/source/repos/SDL2D_Project/SDL2D_Project/Assets/EnemySprites/Skeleton/Sprite Sheets/SkeletonAnimations.txt", "./Assets/EnemySprites/Skeleton/Sprite Sheets/", 'S');

	int sourceX = 0;
	int sourceY = 0;
	int tempH, tempW;
	int lengthOfSprite;


	destRect.h = srcRect.h;
	destRect.w = srcRect.w;



	int totalSize = 0;
	int lastWidthVar = 0;

	for (int i = 0; i < animationSet.size(); i++)
	{
		//This works because I only place one texture in each 
		// 2 dimeson or slot. 
		actualIMG = animationSet.at(i).at(0);
		SDL_QueryTexture(actualIMG, NULL, NULL, &tempW, &tempH);
		switch (i)
		{
		case 0:
			destRect.w = 43;
			srcRect.w = destRect.w;
			break;
		case 1:
			destRect.w = 30;
			srcRect.w = destRect.w;
			break;
		case 2:
			destRect.w = 30;
			srcRect.w = destRect.w;
			break;
		case 3:
			destRect.w = 24;
			srcRect.w = destRect.w;
			break;
		case 4:
			destRect.w = 22;
			srcRect.w = destRect.w;
			break;
		case 5:
			destRect.w = 22;
			srcRect.w = destRect.w;
			break;
		default:
			break;
		}
		lengthOfSprite = tempW / destRect.w;
		for (int j = 0; j < lengthOfSprite; j++)
		{
			switch (i)
			{
			case 0:
				sourceX = 43 * j;
				sourceY = 0;
				break;
			case 1:
				sourceX = 33 * j;
				sourceY = 0;
				break;
			case 2:
				sourceX = 30 * j;
				sourceY = 0;
				break;
			case 3:
				sourceX = 24 * j;
				sourceY = 0;
				break;
			case 4:
				sourceX = 22 * j;
				sourceY = 0;
				break;
			case 5:
				sourceX = 22 * j;
				sourceY = 0;
				break;
			default:
				break;
			}

			srcRect.x = sourceX;
			srcRect.y = sourceY;

			tempIMG = TextureManager::LoadTexture(srcRect, actualIMG);
			animationSet.at(i).push_back(tempIMG);
			totalSize++;
		}
		sourceX = 0;
		Pop_Front(animationSet.at(i));
		totalSize++;
	} //you have to move this over somewhere it's more readable 
}

void Skeleton::Update(float DeltaTime_)
{
	if (getDisable() == false)
	{
		destRect0.x = position.x;
		destRect0.y = position.y;
		destRect0.w = srcRect0.w;
		destRect0.h = srcRect0.h;
	}
	else if (getDisable() == true)
	{
		Disable();
	}
	col.CollisonUpdate(position.x, position.y);
	UpdatePostion();
	UpdateAI();
}

void Skeleton::Render()
{
	PlayAnimations(Animations::WALK);

	if (getDisable() == false)
	{
		SDL_RenderCopy(Game::renderer, objTexture, &srcRect0, &destRect0);
		col.CollisonRender();
	}
	else if (getDisable() == true)
	{
		SDL_RenderCopy(Game::renderer, nullObjTexture, &srcRect0, &destRect0);
	}
}

void Skeleton::handleCollison()
{

}

void Skeleton::UpdateAI()
{
	if (position!=getTarget())
	{
		float arrive = 3;
		int32_t ticks = SDL_GetTicks();
		velocity = getTarget() * speed;
		position = position + velocity * Game::timer->GetDeltaTime();// this should be an equation of motion but you need to have a decent timer class for this 
	}
}


Vec2 Skeleton::getTarget()
{
	Vec2 dir = targetObj->getPosition() - position;
	targetPos = dir.Normalize();
	return targetPos;
}

void Skeleton::PlayAnimations(int state_) // These in both the player and the enemy classes need to be over an animations class
{
	/* This needs to be fixed*/
	Uint32 ticks = SDL_GetTicks();
	Uint32 seconds = ticks / 100;
	Uint32 sprite;

	switch (state_)
	{
	case Skeleton::ATTACK:

		sprite = seconds % 18;
		objTexture = animationSet.at(0).at(sprite);
		break;
	case Skeleton::DEAD:

		sprite = seconds % 15;
		objTexture = animationSet.at(1).at(sprite);
		break;
	case Skeleton::HIT:
		sprite = seconds % 8;
		objTexture = animationSet.at(2).at(sprite);
		break;
	case Skeleton::IDLE:
		sprite = seconds % 11;
		objTexture = animationSet.at(3).at(sprite);
		break;
	case Skeleton::REACT:
		sprite = seconds % 4;
		objTexture = animationSet.at(4).at(sprite);
		break;
	case Skeleton::WALK:
		sprite = seconds % 13;
		objTexture = animationSet.at(5).at(sprite);
		break;
	default:
		break;
	}

}

#ifndef PLAYER_H
#define PLAYER_H


#include "GameObject.h"
#include "../Animator/Animator.h"
#include "../Input/Input.h"
#include "../Physics/Collider.h"

class TextureManager;
class Player : public GameObject , public Input , public Animator
{
public:
	 Player();
	 Player(const char * textureSheet, int x, int y);
	 ~Player();
	 /*Texture Display functions*/
	 virtual void Update(float DeltaTime_) override;
	 virtual void Render() override;

	 void Disable() override;
	 /* Collison Handler*/
	 void handleCollison(); 
	 /* Keyboard Handler */
	 bool KeyBoardInput(int key);
	 bool MouseInput(int key);
	 bool controllerInput(int key);
	 enum class AnimationStates
	 {
		 ATTACK0 = 0,
		 ATTACK1,
		 ATTACK2,
		 CLIMB,
		 CORNERGRAB,
		 CORNERJUMP,
		 CROUCH,
		 DEATH,
		 FALL,
		 HURT,
		 IDLE0,
		 IDLE1,
		 JUMP,
		 RUN,
		 SLIDE,
	 };
private:  

	/*Members*/
	int amountOfAnimations;
	float delta;
	bool disableObject;
	/*Objects/Classes*/
	Collider collider;
	Uint32 FrameTicks;
	SDL_Rect endRect;
	GameObject* playerPtr;
	AnimationStates animState;
	/*Functions*/
	virtual void PlayAnimations(AnimationStates temp_);
	Uint32 WaitAnimationsTicks(Uint32 wait_);
	

};

struct playerStats 
{

};


#endif // !PLAYER_HEADER


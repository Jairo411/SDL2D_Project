#ifndef COMPONENTCOLLIDIER_H 
#define COMPONENTCOLLIDIER_H
#include "Component.hpp"
#include <SDL.h>
class Vec2;
class GameObject;
class C_RectangleCollider : public Component
{
public:
	C_RectangleCollider(Object* owner);
	~C_RectangleCollider();
	virtual void Start();
	virtual void Update(float deltatime);
	virtual void Render();
	void ChangeSize(int width_, int height_);
 private:
	int width, height;
	int area;
	Vec2 position;
	Vec2 middlepoint;
	SDL_Rect srcRect;
};
#endif // !COMPONENTCOLLIDIER_H 

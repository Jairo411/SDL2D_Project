#ifndef  GUI_H
#define  GUI_H
#include "DearGUI/imgui.h"
#include "DearGUI/imgui_sdl.h"
#include <SDL_events.h>
class Game;
class Renderer;
class GUI
{
public:
	GUI();
	~GUI();
	void Inti(Renderer* renderer);
	void HandleEvents(SDL_Event* e_);
	void Update();
	void Render();
private:
	Renderer* renderContext;
	ImGuiIO io;
	int mouseX, mouseY;
};

#endif // ! GUI_H
/*
#ifndef KEYINPUT_H
#define KEYINPUT_H
#include <map>
class SDL;
class Input
{
public:
	virtual ~Input();
	virtual bool keyBoardInput(int key) = 0;
	virtual bool mouseInput(int key) = 0;
	virtual bool controllerInput(int key) = 0;

	bool keyPressed(int is_Pressed,int keycode);
	bool MousePressed(int is_Pressed, int keycode);
	std::map<int, bool> InputKeyBoardHolder;
	std::map<int, bool> InputMouseHolder;

private:
<<<<<<< HEAD
<<<<<<< HEAD
	static int mouseX, mouseY;
	static bool createCollider(bool state_);
||||||| 50f9777
	int mouseX, mouseY;
	Collider* mouseClick;
=======
	static int mouseX, mouseY;
	static bool createCollider(bool state_);
	 bool keyPressed(int is_Pressed,int keycode);
	 std::map<int, bool>*InputHolder;
>>>>>>> 48d7615b797d99609e19fadd6cf40cd1ccacf523
||||||| c9d9634... 2020-09-03
	static int mouseX, mouseY;
	static bool createCollider(bool state_);
=======
	int mouseX, mouseY;
	Collider* mouseClick;
>>>>>>> parent of c9d9634... 2020-09-03
};
#endif // !KEYINPUT_H*/

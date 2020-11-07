#ifndef CONVERTER_H
#define CONVERTER_H
#include "../GameObjects/Map/TileSet/Tiles.h"
#include "../Math/Vec2.h"
#include <SDL_rect.h>
class Converter
{
public:
	static Vec2 GetMiddleOfSquare(Vec2 ScreenCoordinatesPos_);
	static Vec2 ConvertedScreenCoordinates(); // fill this in when you need it 
};

#endif // !COORDINATEHANDLER
#include "Map.h"
#include <fstream>

Map::Map()
{
	width = 0;
	height = 0;
}

Map & Map::GetInstace()
{
	static Map instance;
	return instance;
}

Map::~Map()
{
}

void Map::loadMap()
{
	width = *optionsVar[0];
	height = *optionsVar[1];
	tileMap.resize(height);

	for (int i = 0; i < height; i++)
	{
		tileMap[i].resize(width);
	}

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			tileMap[y][x] = getTile();

		}

	}

}

unsigned short Map::getWidth()
{
	return width;
}

unsigned short Map::getHeight()
{
	return height;
}

Collider Map::getCollider(Sprite &sprite)
{
	return Collider(sprite);
}

Map::Tile Map::getTile()
{
	Tile tile;
	tile.type = TileType(0);
	tile.interactable = true;
	return tile;
}
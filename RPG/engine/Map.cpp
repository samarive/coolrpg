#include "Map.hpp"

Map::Map():objIO("")
{}
Map::Map(std::string const& filePath):objIO (filePath)
{

	for(int i(0);i<objIO.getWrittenObjectNbr();i++)
	{
		objects.push_back(objIO.loadObject(i,txtrIO));
	}
}

Map::~Map()
{}

void Map::update()
{
	allObjectsDo(&Object::update);
}
void Map::paint()
{
	allObjectsDo(&Object::paint);
}
void Map::setPanel(sf::RenderWindow & win)
{
	for(int i (0);i<objects.size();i++)
	{
		objects.at(i)->setPanel(win);
	}
}

void Map::allObjectsDo(void (Object::*func) ())
{
	for(int i (0);i<objects.size();i++)
	{
		(objects.at(i)->*func) ();

	}
}
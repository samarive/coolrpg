#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include "Object.hpp"
#include "TextureIO.hpp"
#include "ObjectIO.hpp"
#include <string>
#include <vector>

class Map
{
public:
	Map();
	Map(std::string const& filePath);

	~Map();

	void update();
	void paint();

	void setPanel(sf::RenderWindow & win);

private:

	void allObjectsDo(void (Object::*func) ());

	TextureIO txtrIO;
	ObjectIO objIO;

	std::vector<Object*> objects;
};

#endif
#ifndef GROUND_HPP_INCLUDED
#define GROUND_HPP_INCLUDED

#include "TextureIO.hpp"
#include <string>

#include "Object.hpp"

class Ground: public Object
{
private:
	sf::Texture *sprite;

public:

	Ground(int x,int y,int w,int h,std::string const& type,TextureIO & io);
	Ground();
	Ground(TextureIO & io);
	~Ground();

	virtual void update();
	virtual void paint();

	void setSprite(sf::Texture *t);

};


#endif
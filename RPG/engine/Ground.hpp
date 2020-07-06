#ifndef GROUND_HPP_INCLUDED
#define GROUND_HPP_INCLUDED

#include "TextureIO.hpp"
#include <string>

#include "Object.hpp"

class Ground: public Object
{
private:
	sf::Texture *sprite;

	std::string spriteFile;

public:

	Ground(int x,int y,int w,int h,std::string const& type,TextureIO & io);
	Ground();
	Ground(TextureIO & io);
	~Ground();

	virtual void update();
	virtual void paint();

	virtual std::string toString() const;

	std::string getSpriteFile() const;

};


#endif
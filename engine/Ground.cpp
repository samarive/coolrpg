#include "Ground.hpp"

Ground::Ground(int x,int y,int w,int h,std::string const& type,TextureIO & io):Object::Object(x,y,w,h)
{	
	sprite = io.getTexture(type);

	sprite->setRepeated(true);
}
Ground::Ground():Object::Object()
{
	sprite = 0;

}
Ground::Ground(TextureIO & io):Object::Object()
{
	sprite = io.getTexture("img/grounds/grass.png");

	sprite->setRepeated(true);
}


Ground::~Ground()
{}

void Ground::update()
{}
void Ground::paint()
{
	sf::Sprite s;
	s.setTexture(*sprite);
	s.setPosition(sf::Vector2f(getX(),getY()));
	s.setTextureRect(sf::IntRect(0,0,getWidth(),getHeight()));

	if(sprite!=0)getPanel()->draw(s);
}

void Ground::setSprite(sf::Texture *t)
{
	sprite = t;
}
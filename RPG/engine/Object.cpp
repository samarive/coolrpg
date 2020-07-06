#include "Object.hpp"

Object::Object():x(0),y(0),w(0),h(0),panel(0)
{}
Object::Object(int abs,int ord,int width,int height):x(abs),y(ord),w(width),h(height),panel(0)
{}
Object::~Object()
{}


int Object::getX() const
{
	return x;
}
int Object::getY() const
{
	return y;
}
int Object::getWidth() const
{
	return w;
}
int Object::getHeight() const
{
	return h;
}
sf::RenderWindow* Object::getPanel() const
{
	return panel;
}

void Object::setX(int newX)
{
	x = newX;
}
void Object::setY(int newY)
{
	y = newY;
}

void Object::setPanel(sf::RenderWindow & newPanel)
{
	panel = &newPanel;
}
std::string Object::toString() const
{
	return "object";
}
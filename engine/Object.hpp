#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Object
{
private:
	int x;
	int y;
	int w;
	int h;

	sf::RenderWindow *panel; 
public:
	Object();
	Object(int abs,int ord,int width,int height);
	~Object();

	virtual void paint()=0;
	virtual void update()=0;

	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	sf::RenderWindow* getPanel() const;

	//I don't like setters >:(

	void setX(int newX);
	void setY(int newY);
	void setPanel(sf::RenderWindow & newPanel);
};

#endif
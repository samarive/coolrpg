#include <Ground.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>

using namespace sf;

int main()
{
	//list of levels

	system("dir /b lvl >> lvllisttemp.txt");

	//READ LEVEL LIST HERE

	system("del lvllisttemp.txt");


	std::vector<Object*> objects;

	RenderWindow window (VideoMode(800,450),"Level editor",Style::Fullscreen);
	window.setFramerateLimit(30);

	View camera (Vector2f(800,450),Vector2f(400,225));
	camera.setViewport(FloatRect(0.f,0.f,1.f,1.f));

	window.setView(camera);
	

	bool click (false);
	int lastX (0);
	int lastY (0);

	TextureIO tio;

	while(window.isOpen())
	{
		Event event;

		while(window.pollEvent(event))
		{
			switch(event.type)
			{
				case Event::Closed:
					window.close();
				break;
				case Event::MouseButtonPressed:
				{

					int x (window.mapPixelToCoords(Vector2i(event.mouseButton.x,event.mouseButton.y)).x);
					int y (window.mapPixelToCoords(Vector2i(event.mouseButton.x,event.mouseButton.y)).y);

					if(click)
					{
						objects.push_back(new Ground(lastX,lastY,abs(lastX-x),abs(lastY-y),"img/grounds/grass.png",tio));
						objects.at(objects.size()-1)->setPanel(window);

						click = false;
					}else{
						click = true;

						lastX = x;
						lastY = y;
					}
				}
				break;
			}
		}

		window.clear();

		for(int i (0);i<objects.size();i++)
		{
			objects.at(i)->paint();
		}		

		window.display();
	}

	for(int i (0);i<objects.size();i++)
	{
		delete objects.at(i);
	}

	return 0;
}
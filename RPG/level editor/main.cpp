#include <Ground.hpp>
#include <ObjectIO.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace sf;

std::string listDialog(std::string const& arg);

int main()
{
	//list of levels

	system("dir /b lvl >> lvllisttemp.txt");

	//READ LEVEL LIST HERE

	std::string lvlList ("");

	{
		std::ifstream input ("lvllisttemp.txt");

		std::string lvlLine ("");

		while(getline(input,lvlLine))
		{
			lvlList+=lvlLine+"\n";
		}

		input.close();
	}

	system("del lvllisttemp.txt");

	ObjectIO objIO ("lvl/"+listDialog(lvlList));

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

	for(int i (0);i<objIO.getWrittenObjectNbr();i++)
	{
		objects.push_back(objIO.loadObject(i,tio));
		objects.at(i)->setPanel(window);
	}

	bool ctrlPressed (false);

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
				case Event::KeyPressed:
					if(event.key.code==Keyboard::LControl)ctrlPressed = true;
					else if(event.key.code==Keyboard::S && ctrlPressed)
					{
						objIO.eraseFile();

						for(int i (0);i<objects.size();i++)
						{
							objIO.saveObject(objects.at(i));
						}
					}
				break;
				case Event::KeyReleased:
					if(event.key.code==Keyboard::LControl)ctrlPressed = false;
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

std::string listDialog(std::string const& arg)
{

	RenderWindow dialog (VideoMode(300,500),"Choose",Style::Titlebar | Style::Close);
	dialog.setFramerateLimit(30);

	View cam (Vector2f(150,250),Vector2f(300,500));

	dialog.setView(cam);

	cam.setViewport(FloatRect(0.f,0.f,1.f,1.f));

	std::vector<RectangleShape*> buttons;
	std::vector<Text*> fileNames;

	Font font;
	font.loadFromFile("arial.ttf");

	std::string temp ("");

	for(int i (0);i<arg.size();i++)
	{
		if(arg.at(i)!='\n')
		{
			temp+=arg.at(i);
		}else{

			buttons.push_back(new RectangleShape(Vector2f(100,75)));
			buttons.at(buttons.size()-1)->setPosition(Vector2f(100,80*buttons.size()));
			buttons.at(buttons.size()-1)->setFillColor(Color::Green);
			fileNames.push_back(new Text);
			fileNames.at(fileNames.size()-1)->setPosition(Vector2f(110,80*buttons.size()+10));
			fileNames.at(fileNames.size()-1)->setFont(font);
			fileNames.at(fileNames.size()-1)->setFillColor(Color::Blue);
			fileNames.at(fileNames.size()-1)->setString(temp);

			temp = "";
		}
	}


	std::string toReturn ("");


	while(dialog.isOpen() && toReturn=="")
	{
		Event event;

		while(dialog.pollEvent(event))
		{
			switch(event.type)
			{
				case Event::Closed:
					dialog.close();
				break;
				case Event::MouseWheelScrolled:

					cam.move(Vector2f(0,-event.mouseWheelScroll.delta*5));

					dialog.setView(cam);
				break;
				case Event::MouseButtonPressed:

					int x (dialog.mapPixelToCoords(Vector2i(event.mouseButton.x,event.mouseButton.y)).x);
					int y (dialog.mapPixelToCoords(Vector2i(event.mouseButton.x,event.mouseButton.y)).y);

					toReturn = fileNames.at(y/80-1)->getString();

				break;

			}
		}

		dialog.clear(Color::White);


		for(int i (0);i<buttons.size();i++)
		{
			dialog.draw(*(buttons.at(i)));
			dialog.draw(*(fileNames.at(i)));
		}

		dialog.display();
	}


	for(int i (0);i<buttons.size();i++)
	{
		delete buttons.at(i);
	}

	return toReturn;

}
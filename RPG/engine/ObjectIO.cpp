#include "ObjectIO.hpp"

#include <iostream>
#include <fstream>
#include "TextureIO.hpp"
#include "Ground.hpp"

ObjectIO::ObjectIO(std::string const& arg):filepath(arg)
{}
ObjectIO::~ObjectIO()
{
	for(int i(0);i<allocated.size();i++)
	{
		delete allocated.at(i);
	}
}

Object* ObjectIO::loadObject(int nbr,TextureIO & txtrio)
{

	int prev (allocated.size());

	//Getting the line
	std::string chaine ("");

	std::ifstream input (filepath);

	for(int i (0);i<nbr;i++)
	{
		getline(input,chaine);
	}

	getline(input,chaine);

	//Retrieving object type

	int objectType (std::stoi(getStringFromTo(';',';',chaine,0)));

	switch(objectType)
	{
		case ObjectCode::GroundCode:
		{
			//x
			int x = std::stoi(getStringFromTo(';',';',chaine,1));
			//y
			int y = std::stoi(getStringFromTo(';',';',chaine,2));
			//width
			int width = std::stoi(getStringFromTo(';',';',chaine,3));
			//height
			int height = std::stoi(getStringFromTo(';',';',chaine,4));
			//fiename
			std::string filename = getStringFromTo(';',';',chaine,5);

			allocated.push_back(new Ground(x,y,width,height,filename,txtrio));

		}
		break;
	}

	if(allocated.size()>prev)
	{
		return allocated.at(allocated.size()-1);
	}else
	{
		return 0;
	}

}

int ObjectIO::getWrittenObjectNbr()
{
	std::ifstream input (filepath);

	int nbr (0);

	std::string temp ("");

	if(input)
	{
		while(getline(input,temp))
		{
			nbr++;
		}
	}

	return nbr;
}

void ObjectIO::eraseFile()
{
	#ifdef __WIN32__
		system(("del "+filepath).c_str());
		system(("type nul > "+filepath).c_str());
	#else
		system(("rm "+filepath).c_str());
		system(("touch "+filepath).c_str());
	#endif
}

bool ObjectIO::saveObject(Object *arg)
{
	std::ofstream output (filepath,std::ios::app); 

	if(arg->toString()=="ground" && output)
	{
		Ground* g (0);
		g = (Ground*) arg;

		output << ";" << ObjectCode::GroundCode << ";" << arg->getX() << ";" << arg->getY() << ";" << arg->getWidth() << ";" << arg->getHeight() << ";" << g->getSpriteFile() << ";" << std::endl;

		output.close();

		return true;
	}else
	{
		output.close();
		return false;
	}
}




std::string getStringFromTo(char beg,char end,std::string const& arg,int startAt)

{

	std::string toReturn ("");



	int occurenceNbr (0);



	bool saving (false);



	for(int i = 0;i<arg.size();i++)

	{

		if(arg.at(i)==beg && !saving)

		{

			if(occurenceNbr==startAt)

			{

				saving = true;

				continue;

			}else

			{

				occurenceNbr++;

			}

		}

		if(saving && arg.at(i)==end)

		{

			break;

		}



		if(saving)toReturn+=arg.at(i);

	}



	return toReturn;

}
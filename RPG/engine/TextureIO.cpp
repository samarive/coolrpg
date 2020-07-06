#include "TextureIO.hpp"


TextureIO::TextureIO()
{}
TextureIO::~TextureIO()
{
	for(int i(0);i<textures.size();i++)
	{
		delete textures.at(i);
	}
}

sf::Texture* TextureIO::getTexture(std::string const& arg)
{
	for(int i (0);i<loaded.size();i++)
	{
		if(arg==loaded.at(i))
		{
			return textures.at(i);
		}
	}

	textures.push_back(new sf::Texture);

	if(textures.at(textures.size()-1)->loadFromFile(arg))
	{
		loaded.push_back(arg);

		return textures.at(textures.size()-1);
	}else
	{
		delete textures.at(textures.size()-1);
		textures.pop_back();
	
		return 0;
	}

}
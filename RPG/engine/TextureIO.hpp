#ifndef TEXTUREIO_HPP_INCLUDED
#define TEXTUREIO_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class TextureIO
{
private:
	std::vector<std::string> loaded;
	std::vector<sf::Texture*> textures;

public:
	TextureIO();
	~TextureIO();

	sf::Texture* getTexture(std::string const& arg);

};

#endif
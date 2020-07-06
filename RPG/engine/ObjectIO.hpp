#ifndef OBJECTIO_HPP_INCLUDED
#define OBJECTIO_HPP_INCLUDED

#include "TextureIO.hpp"
#include "Object.hpp"
#include <vector>

enum ObjectCode
{
	GroundCode = 1
};
typedef enum ObjectCode ObjectCode;

class ObjectIO
{
private:
	const std::string filepath;
	std::vector<Object*> allocated;

public:
	ObjectIO(std::string const& arg);
	~ObjectIO();

	Object* loadObject(int nbr,TextureIO & txtrio);
	bool saveObject(Object *arg);
};

std::string getStringFromTo(char beg,char end,std::string const& arg,int startAt);


#endif
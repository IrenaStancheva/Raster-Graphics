#include "PictureTypes.h"
//implementation for all our new funcrions
PictureTypes::PictureTypes(const MyString& fileName)
{
	const char* beg = fileName.c_str();
	const char* end = fileName.c_str() + fileName.getSize();
	const char* iter = end;

	while (iter != beg && *iter != '.') {
		iter--;
	}

	this->name = fileName.substr(0, iter - beg);
	this->extension = fileName.substr(iter - beg, end - iter);
}

const MyString& PictureTypes::getName() const
{
	return name;
}

const MyString& PictureTypes::getExtension() const
{
	return extension;
}
void PictureTypes::putExtention(const MyString& ext)
{
	extension = ext;
}
void PictureTypes::changeToColourful()
{
	grayscale = false;
	monochrome = false;
	colourful = true;
}

void PictureTypes::changeToGrayscale()
{
	grayscale = true;
	monochrome = false;
	colourful = false;
}

void PictureTypes::changeToMonochrome()
{
	grayscale = false;
	monochrome = true;
	colourful = false;
}

bool PictureTypes::isColourful() const
{
	return colourful == true;
}

bool PictureTypes::isGrayscale() const
{
	return grayscale == true;
}


bool PictureTypes::isMonochrome() const
{
	return monochrome == true;
}

void PictureTypes::changeToRotated(const MyString& dir)
{
	int temp = width;
	width = height;
	height = temp;
}

unsigned int PictureTypes::getSize() const
{
	return size;
}

unsigned int PictureTypes::getWidth() const
{
	return width;
}

unsigned int PictureTypes::getHeight() const
{
	return height;
}

PictureTypes::PictureTypes(const MyString& name, bool colourful, bool grayscale,
	bool monochrome, unsigned int width, unsigned int height, unsigned int size)
{
	this->name = name;
	this->colourful = colourful;
	this->grayscale = grayscale;
	this->monochrome = monochrome;
	this->width = width;
	this->height = height;
	this->size = size;
}

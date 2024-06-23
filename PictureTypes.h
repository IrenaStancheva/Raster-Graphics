#pragma once
#include "MyString.h"
class PictureTypes
{
public:
	PictureTypes(const MyString& fileName);

	const MyString& getName() const;
	const MyString& getExtension() const;

	void putExtention(const MyString& ext);

	//we have added new functions for the colours of our picture
	void changeToColourful();
	void changeToGrayscale();
	void changeToMonochrome();

	bool isColourful() const;
	bool isGrayscale()const;
	bool isMonochrome()const;

	void changeToRotated(const MyString& dir);

	unsigned int getSize()const;
	unsigned int getWidth()const;
	unsigned int getHeight()const;

	virtual PictureTypes* clone() const = 0;//returns the type of the picture
	virtual ~PictureTypes() = default;

	PictureTypes(const MyString& name, bool colourful, bool grayscale, bool monochrome,
		unsigned int width, unsigned int height, unsigned int size);

private:
	MyString name;
	MyString extension;

	bool colourful = true;//check is the picture is colourful
	bool grayscale = false;// check is the picture is gtayscale
	bool monochrome = false;//check is the picture is monochrome

	unsigned int width = 0;//we use this for the rotation
	unsigned int height = 0;//we use this for the rotation

	unsigned int size = 0;//for collage
};
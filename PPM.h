#pragma once
#include "PictureTypes.h"
class PPM :
	public PictureTypes
{
public:
	PictureTypes* clone()const override;

	PPM(const MyString& name, bool colourful, bool grayscale, bool monochrome,
		unsigned int width, unsigned int height, unsigned int size);
};


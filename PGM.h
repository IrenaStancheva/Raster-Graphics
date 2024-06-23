#pragma once
#include "PictureTypes.h"
class PGM :
	public PictureTypes
{
public:
	PictureTypes* clone()const override;

	PGM(const MyString& name,
		bool colourful,
		bool grayscale,
		bool monochrome,
		unsigned int width,
		unsigned int height,
		unsigned int size);
};
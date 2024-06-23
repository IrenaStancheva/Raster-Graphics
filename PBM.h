#pragma once
#include "PictureTypes.h"
class PBM : public PictureTypes
{
public:
	PictureTypes* clone()const override;

	PBM(const MyString& name, bool colourful, bool grayscale, bool monochrome,
		unsigned int width, unsigned int height, unsigned int size);
};


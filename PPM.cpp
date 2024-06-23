#include "PPM.h"

PictureTypes* PPM::clone() const
{
    return new PPM(*this);
}

PPM::PPM(const MyString& name, bool colourful, bool grayscale, bool monochrome,
    unsigned int width, unsigned int height, unsigned int size) : PictureTypes(name, colourful, grayscale, monochrome, width, height, size)
{
    PictureTypes::putExtention("ppm");
}
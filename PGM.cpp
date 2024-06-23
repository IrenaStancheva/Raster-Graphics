#include "PGM.h"
PictureTypes* PGM::clone() const
{
    return new PGM(*this);
}

PGM::PGM(const MyString& name, bool colourful, bool grayscale, bool monochrome,
    unsigned int width, unsigned int height, unsigned int size) : PictureTypes(name, colourful, grayscale, monochrome, width, height, size)
{
    PictureTypes::putExtention("pgm");
}
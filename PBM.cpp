#include "PBM.h"

PictureTypes* PBM::clone() const
{
    return new PBM(*this);
}
PBM::PBM(const MyString& name, bool colourful, bool grayscale,
    bool monochrome, unsigned int width, unsigned int height, unsigned int size) : PictureTypes(name, colourful, grayscale, monochrome, width, height, size)
{
    PictureTypes::putExtention("pbm");
}

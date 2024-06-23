#pragma once
#include <iostream>
#include"Stack.hpp"
#include"Commands.h"
#include"PBM.h"
#include"PGM.h"
#include"PPM.h"
#include"PictureTypes.h"

PictureTypes* findPicture(UserSession& session, const MyString& picture)
{
	for (size_t i = 0; i < session.getPicturesCnt(); i++)
	{
		if (session[i].getName() == picture)
			return &session[i];
	}
	return nullptr;
}

void addOutcome(UserSession& session, const MyString& name, unsigned int width, unsigned int height, unsigned int size)
{
	if (name.substr(name.getSize() - 3, 3) == "pbm")
	{
		PBM picture(name, false, false, true, width, height, size);
		session.addPicture(picture);
	}
	else if (name.substr(name.getSize() - 3, 3) == "pgm")
	{
		PGM picture(name, false, true, false, width, height, size);
		session.addPicture(picture);
	}
	else if (name.substr(name.getSize() - 3, 3) == "ppm")
	{
		bool colourful;
		std::cin >> colourful;
		std::cout << "Grayscale: ";
		bool grayscale;
		std::cin >> grayscale;
		std::cout << "Or monochrome: ";
		bool monochrome;
		std::cin >> monochrome;

		PPM picture(name, colourful, grayscale, monochrome, width, height, size);
		session.addPicture(picture);
	}
	else
		throw std::out_of_range("Unvalid picture type!");
}

void makeCollage(UserSession& session, const PictureTypes*& p1, const PictureTypes*& p2)
{
	MyString name_p1 = p1->getExtension();
	MyString name_p2 = p1->getExtension();
	if (name_p1 != name_p2 || p1->getSize() != p2->getSize())
		throw std::logic_error("Pictures of different kind!");

	MyString direction;
	std::cout << "direction(horizontal/vertical): "; std::cin >> direction;

	unsigned int height = p1->getHeight();
	unsigned int width = p1->getWidth();

	if (direction == "horizontal")
		width += p2->getWidth();
	else if (direction == "vertical")
		height += p2->getHeight();
	else
		throw std::out_of_range("Directions has to be horizontal/vertical!");

	std::cout << "Enter the name for our collage: ";
	MyString name;
	std::cin >> name;
	if (name.substr(name.getSize() - 3, 3) != name_p1)
		throw std::logic_error("Pictures of different kinds!");

	addOutcome(session, name, width, height, p1->getSize());
}
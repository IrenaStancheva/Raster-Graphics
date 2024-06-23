#pragma once
#include "PPM.h"
#include "PGM.h"
#include "PBM.h"

void loadPPM(PictureTypes**& pictures, size_t pictures_count, UserSession& session, const MyString& name)
{
	std::cout << "Width: ";
	size_t width;
	std::cin >> width;
	std::cout << "Heigth: ";
	size_t heigth;
	std::cin >> heigth;
	std::cout << "Size: ";
	size_t size;
	std::cin >> size;
	std::cout << "Colourful: ";
	bool colourful;
	std::cin >> colourful;
	std::cout << "Grayscale: ";
	bool grayscale;
	std::cin >> grayscale;
	std::cout << "Or monochrome: ";
	bool monochrome;
	std::cin >> monochrome;

	PPM picture(name, colourful, grayscale, monochrome, width, heigth, size);
	session.addPicture(picture);
}
void loadPGM(PictureTypes**& pictures, size_t pictures_count, UserSession& session, const MyString& name)
{
	std::cout << "Width: ";
	size_t width;
	std::cin >> width;
	std::cout << "Heigth: ";
	size_t heigth;
	std::cin >> heigth;
	std::cout << "Size: ";
	size_t size;
	std::cin >> size;

	PGM picture(name, false, true, false, width, heigth, size);
	session.addPicture(picture);
}
void loadPBM(PictureTypes**& pictures, size_t pictures_count, UserSession& session, const MyString& name)
{
	std::cout << "Width: ";
	size_t width;
	std::cin >> width;
	std::cout << "Heigth: ";
	size_t heigth;
	std::cin >> heigth;
	std::cout << "Size: ";
	size_t size;
	std::cin >> size;

	PBM picture(name, false, false, true, width, heigth, size);
	session.addPicture(picture);
}

void loadPictures(UserSession& session)
{
	std::cout << "How many pictures would you like to add in your session?\n";
	size_t pictures_count;
	std::cin >> pictures_count;
	PictureTypes** pictures = new PictureTypes * [pictures_count];

	std::cout << "Adding picture! Please enter the following data:\n";

	for (size_t i = 0; i < pictures_count; i++)
	{
		std::cout << "Name: ";
		MyString name;
		std::cin >> name;

		if (std::strcmp(name.substr(name.getSize() - 3, 3).c_str(), "ppm") == 0)
		{
			loadPPM(pictures, pictures_count, session, name);
		}
		else if (std::strcmp(name.substr(name.getSize() - 3, 3).c_str(), "pgm") == 0)
		{
			loadPGM(pictures, pictures_count, session, name);
		}
		else if (std::strcmp(name.substr(name.getSize() - 3, 3).c_str(), "pbm") == 0)
		{
			loadPBM(pictures, pictures_count, session, name);
		}
		else
			throw std::invalid_argument("Invalid argument input has to be ppm/pgm/pbm!");
	}
}

void load(UserSession& program_sessions, int id)
{
	loadPictures(program_sessions);

	std::cout << "Session with ID " << id << " started!\n";
	for (size_t i = 0; i < program_sessions.getPicturesCnt(); i++)
	{
		std::cout << "Image ";
		std::cout << program_sessions[i].getName();
		std::cout << " added!\n";
	}
}
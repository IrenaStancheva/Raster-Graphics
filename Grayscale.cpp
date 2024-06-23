#include "Grayscale.h"

//added implementation to all functions we have added in our class
Grayscale::Grayscale(UserSession& other) : Commands(other)
{
}

Grayscale::Grayscale(UserSession&& other) : Commands(std::move(other))
{
}

void Grayscale::execute()
{
	for (size_t i = 0; i < session.getPicturesCnt(); i++)
	{
		if (session[i].isGrayscale())
			continue;
		session[i].changeToGrayscale();
	}
}

void Grayscale::executeOnePic()
{
	if (!session[0].isGrayscale());
	session[0].changeToGrayscale();
}

Commands* Grayscale::clone() const
{
	return new Grayscale(*this);
}

const MyString& Grayscale::command_name() const
{
	static const MyString grayscale = "grayscale";
	return grayscale;
}

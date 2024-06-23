#include "Monochrome.h"

Monochrome::Monochrome(UserSession& other) : Commands(other)
{
}

Monochrome::Monochrome(UserSession&& other) : Commands(std::move(other))
{
}

void Monochrome::execute()
{
	for (size_t i = 0; i < session.getPicturesCnt(); i++)
	{
		if (session[i].isMonochrome())//here we have created a function that gets from the class PictureTypes if our picture is monochromed
			continue;
		session[i].changeToMonochrome();//if it is not we changed it to monochrome with another function we have created in the class
	}
}

void Monochrome::executeOnePic()
{
	if (!session[0].isMonochrome())
		session[0].changeToMonochrome();
}

Commands* Monochrome::clone() const
{
	return new Monochrome(*this);
}

const MyString& Monochrome::command_name() const
{
	static const MyString monochrome = "monochrome";
	return monochrome;
}

#include "Negative.h"

Negative::Negative(UserSession& other) : Commands(other)
{
}

Negative::Negative(UserSession&& other) : Commands(std::move(other))
{
}

void Negative::execute()
{
	for (size_t i = 0; i < session.getPicturesCnt(); i++)
	{
		if (session[i].isGrayscale() || session[i].isMonochrome())//here we check if our picture is gray or monochromed
			session[i].changeToColourful();
		session[i].changeToMonochrome();
	}
}

void Negative::executeOnePic()
{
	if (session[0].isGrayscale() || session[0].isMonochrome())
		session[0].changeToColourful();
	else
		session[0].changeToGrayscale();
}

Commands* Negative::clone() const
{
	return new Negative(*this);
}

const MyString& Negative::command_name() const
{
	static const MyString negative = "negative";
	return negative;
}

#include "Rotate.h"
#pragma warning ( disable:4996)
Rotate::Rotate(UserSession& other, const MyString& dir) : Commands(other)
{
	if (dir != "left" && dir != "rigth")
		throw std::logic_error("Wrong argument enterted (should be left or rigth)!");

	direction = dir;

}

Rotate::Rotate(UserSession&& other, MyString&& dir) : Commands(std::move(other))
{
	if (dir != "left" && dir != "rigth")
		throw std::logic_error("Wrong argument enterted (should be left or rigth)!");

	direction = std::move(dir);
	dir = nullptr;
}

void Rotate::execute()
{
	for (size_t i = 0; i < session.getPicturesCnt(); i++)
	{
		session[i].changeToRotated(direction);
	}
}

void Rotate::executeOnePic()
{
	session[0].changeToRotated(direction);
}

Commands* Rotate::clone() const
{
	return new Rotate(*this);
}

const MyString& Rotate::command_name() const
{
	return direction;
}

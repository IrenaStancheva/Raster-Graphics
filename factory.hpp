#pragma once
#include "Commands.h"
#include "UserSession.h"
#include "Grayscale.h"
#include "Monochrome.h"
#include "Negative.h"
#include "Rotate.h"

constexpr size_t MAX_BUFF = 1024;

Commands* factory(const char* commands_buff, int id, UserSession& program_session, MyStack<Commands*, MAX_STACK> saved_data_in_stack, MyStack<Commands*, MAX_STACK> commands_stack)
{
	if (std::strcmp(commands_buff, "grayscale") == 0)
		return new Grayscale(program_session);

	else if (std::strcmp(commands_buff, "monochrome") == 0)
		return new Monochrome(program_session);

	else if (std::strcmp(commands_buff, "rotate") == 0)
	{
		std::cout << "Enter direction of rotation!\n";
		MyString direction_buff;
		std::cin >> direction_buff;
		return new Rotate(program_session, direction_buff);
	}

	else if (std::strcmp(commands_buff, "negative") == 0)
	{
		return new Negative(program_session);
	}

	else
		throw std::invalid_argument("Invalid input! Must be a command!");
}
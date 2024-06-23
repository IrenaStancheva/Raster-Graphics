// oopProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stack.hpp"
#include "Commands.h"
#include "Load.hpp"
#include "CommandsContainer.h"
#include "PPM.h"
#include "factory.hpp"
#include "CommandsInput.hpp"

int main()
{
	try
	{
		size_t size_stack = 1;
		size_t size_sessions = 1;

		//this is where we keep the commands until we enter the save/saveas command in each session
		MyStack<Commands*, MAX_STACK>* commands_stack = new MyStack<Commands*, MAX_STACK>[size_stack];//delete allocated memory :)

		std::cout << "Please load pictures first!\n";
		char commands_buff[1024];//this is where we enter the command
		std::cin >> commands_buff;

		//array of sessions we need to save all sessions within the program
		UserSession* program_sessions = new UserSession[size_sessions];//delete allocated memory :)
		int id = 0;//the unique id each session has 

		if (std::strcmp(commands_buff, "load") == 0)
		{
			load(program_sessions[id], id);
		}
		else
			throw std::invalid_argument("To start a session we have to load pictures first!");

		std::cout << "Please when you'd like to end the program write: end\n";
		input(commands_buff, commands_stack, id, program_sessions, size_sessions, size_stack);

		delete[] commands_stack;
		delete[] program_sessions;
	}
	catch (const std::invalid_argument& i)
	{
		std::cout << i.what();
	}
	catch (const std::logic_error& l)
	{
		std::cout << l.what();
	}
	catch (const std::out_of_range& o)
	{
		std::cout << o.what();
	}
	catch (const std::exception&)
	{
		std::cout << "Error of unknown kind!";
	}
	catch (...)
	{
		std::cout << "Error of unknown kind!";
	}
	return 0;
}
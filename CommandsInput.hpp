#include <iostream>
#include "Commands.h"
#include"factory.hpp"
#include"UserSession.h"
#include "Stack.hpp"
#include"Load.hpp"
#include "Save.hpp"
#include "Collage.hpp"

void picturesInfo(const UserSession& program_sessions)
{
	for (size_t i = 0; i < program_sessions.getPicturesCnt(); i++)
	{
		std::cout << program_sessions[i].getName() << ' ';
	}
}
void pendingCommandsInfo(MyStack<Commands*, MAX_STACK>*& commands_stack, int id)
{
	MyStack<Commands*, MAX_STACK> temp = commands_stack[id];
	for (size_t i = 0; i < commands_stack[id].getSize(); i++)
	{
		std::cout << temp.peek()->command_name() << " ";
		temp.pop();
	}std::cout << std::endl;
}
void madeCommandsInfo(MyStack<Commands*, MAX_STACK>*& saved_data_in_stack, int id)
{
	MyStack<Commands*, MAX_STACK> temp = saved_data_in_stack[id];
	for (size_t i = 0; i < saved_data_in_stack[id].getSize(); i++)
	{
		std::cout << temp.peek()->command_name() << " ";
		temp.pop();
	}std::cout << std::endl;
}

template <class T>
void resizeArr(T*& arr, size_t size)
{
	T* newArr = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	arr = newArr;
	newArr = nullptr;
}

void input(char* commands_buff, MyStack<Commands*, MAX_STACK>*& commands_stack, int& id, UserSession*& program_sessions, size_t& size_sessions, size_t& size_stack)
{
	size_t size_saved = size_stack;
	MyStack<Commands*, MAX_STACK>* saved_data_in_stack = new MyStack<Commands*, MAX_STACK>[size_saved];//delete allocated memory :)

	while (true)
	{
		std::cout << "Enter a commmand!\n";
		std::cin >> commands_buff;
		if (std::strcmp(commands_buff, "end") == 0)
			break;

		else if (std::strcmp(commands_buff, "save") == 0)
		{
			if (saved_data_in_stack[id].isFull())
			{
				resizeArr< MyStack<Commands*, MAX_STACK>>(saved_data_in_stack, size_saved++);
			}

			MyStack<Commands*, MAX_STACK> temp = commands_stack[id];
			for (size_t i = 0; i < commands_stack[id].getSize(); i++)
			{
				saved_data_in_stack[id].push(temp.peek());
				temp.pop();
			}
			saveStack(commands_stack[id]);
		}

		else if (std::strcmp(commands_buff, "saveas") == 0)
		{
			if (saved_data_in_stack[id].isFull())
			{
				resizeArr< MyStack<Commands*, MAX_STACK>>(saved_data_in_stack, size_saved++);
			}

			MyStack<Commands*, MAX_STACK> temp = commands_stack[id];
			for (size_t i = 0; i < commands_stack[id].getSize(); i++)
			{
				saved_data_in_stack[id].push(temp.peek());
				temp.pop();
			}

			std::cout << "Saving all commands on the first added picture!\n";
			while (!commands_stack[id].isEmpty())
			{
				commands_stack[id].peek()->executeOnePic();
				commands_stack[id].pop();
			}std::cout << std::endl;
		}

		else if (std::strcmp(commands_buff, "undo") == 0)
		{
			if (commands_stack[id].isEmpty())
				continue;
			commands_stack[id].pop();
		}

		else if (std::strcmp(commands_buff, "load") == 0)
		{
			++id;
			if (id == size_sessions)
			{
				resizeArr<UserSession>(program_sessions, size_sessions);
				++size_sessions;
			}
			if (id == size_stack)
			{
				resizeArr<MyStack<Commands*, MAX_STACK>>(commands_stack, size_stack);
				++size_stack;

			}
			if (id == size_saved)
			{
				resizeArr<MyStack<Commands*, MAX_STACK>>(saved_data_in_stack, size_saved);
				++size_saved;
			}
			load(program_sessions[id], id);
		}

		else if (std::strcmp(commands_buff, "add") == 0)
		{
			loadPictures(program_sessions[id]);
		}

		else if (std::strcmp(commands_buff, "sessionInfo") == 0)
		{
			if (program_sessions[id].getPicturesCnt() == 0)
				continue;
			std::cout << "Pictures in session: ";
			picturesInfo(program_sessions[id]);
			std::cout << std::endl;

			if (!commands_stack[id].isEmpty())
			{
				std::cout << "Pending commands: ";
				pendingCommandsInfo(commands_stack, id);
			}
			if (!saved_data_in_stack[id].isEmpty())
			{
				std::cout << "Made commands: ";
				madeCommandsInfo(saved_data_in_stack, id);
			}
			if (saved_data_in_stack[id].isEmpty() && commands_stack[id].isEmpty())
			{
				std::cout << "No commands made!\n";
			}
		}

		else if (std::strcmp(commands_buff, "switch") == 0)
		{
			std::cin >> id;
			if (id >= size_stack || commands_stack[id].isEmpty() && saved_data_in_stack[id].isEmpty())
				throw std::out_of_range("No such session existing!");
			std::cout << "Switched to session with ID: " << id << std::endl;
		}

		else if (std::strcmp(commands_buff, "collage") == 0)
		{
			std::cout << "Please enter two different pictures from the current session!\n";
			MyString p1;
			MyString p2;
			std::cin >> p1 >> p2;
			const PictureTypes* pic1 = findPicture(program_sessions[id], p1);
			const PictureTypes* pic2 = findPicture(program_sessions[id], p2);

			if (!pic1 || !pic2)
				throw std::logic_error("Such picture does not exist in this session!");

			UserSession& temp = program_sessions[id];//ref to save the changes
			makeCollage(temp, pic1, pic2);

			delete pic1;
			delete pic2;
		}

		else
		{
			commands_stack[id].push(factory(commands_buff, id, program_sessions[id], saved_data_in_stack[id], commands_stack[id]));//return commands*
		}
	}

	delete[] saved_data_in_stack;
}
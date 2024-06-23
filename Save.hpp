#include <iostream>
#include "Stack.hpp"
#include "Commands.h"
void saveStack(MyStack<Commands*, MAX_STACK>& commands_stack)
{
	if (commands_stack.isEmpty())
		return;

	while (!commands_stack.isEmpty())
	{
		commands_stack.peek()->execute();
		commands_stack.pop();
	}
}

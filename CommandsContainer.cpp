#include "CommandsContainer.h"

CommandsContainer::CommandsContainer()
{
	capacity = 4;
	commands_cnt = 0;
	commands_arr = new Commands * [capacity] {nullptr};
}

CommandsContainer::CommandsContainer(const CommandsContainer& other)
{
	copyFrom(other);
}

CommandsContainer::CommandsContainer(CommandsContainer&& other) noexcept
{
	moveFrom(std::move(other));
}

CommandsContainer& CommandsContainer::operator=(CommandsContainer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

CommandsContainer& CommandsContainer::operator=(const CommandsContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

CommandsContainer::~CommandsContainer()
{
	free();
}

void CommandsContainer::addCommand(Commands* command)
{
	if (commands_cnt == capacity)
		resize(capacity * 2);
	commands_arr[commands_cnt++] = command;
	command = nullptr;
}

void CommandsContainer::addCommand(const Commands& command)
{
	Commands* cloned = command.clone();
	addCommand(cloned);
}

size_t CommandsContainer::getCnt() const
{
	return commands_cnt;
}

const Commands* CommandsContainer::operator[](size_t idx) const
{
	return commands_arr[idx];
}

Commands* CommandsContainer::operator[](size_t idx)
{
	return commands_arr[idx];
}

void CommandsContainer::copyFrom(const CommandsContainer& other)
{
	commands_arr = new Commands * [other.capacity];

	for (size_t i = 0; i < other.commands_cnt; i++)
	{
		commands_arr[i] = other.commands_arr[i]->clone();
	}
	capacity = other.capacity;
	commands_cnt = other.commands_cnt;
}

void CommandsContainer::moveFrom(CommandsContainer&& other)
{
	commands_arr = other.commands_arr;
	other.commands_arr = nullptr;
	commands_cnt = other.commands_cnt;
	other.commands_cnt = 0;
	capacity = other.capacity;
	other.capacity = 0;
}

void CommandsContainer::free()
{
	for (size_t i = 0; i < commands_cnt; i++)
	{
		delete commands_arr[i];
	}
	delete[]commands_arr;
	capacity = 0;
	commands_cnt = 0;
}

void CommandsContainer::resize(size_t new_cap)
{
	Commands** newDat = new Commands * [new_cap];
	for (size_t i = 0; i < commands_cnt; i++)
	{
		newDat[i] = commands_arr[i];
	}
	delete[]commands_arr;
	capacity = new_cap;
	commands_arr = newDat;
	newDat = nullptr;
}
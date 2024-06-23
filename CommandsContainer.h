#pragma once
#include "Commands.h"
class CommandsContainer
{
public:
	CommandsContainer();
	CommandsContainer(const CommandsContainer& other);
	CommandsContainer(CommandsContainer&& other) noexcept;
	CommandsContainer& operator=(CommandsContainer&& other) noexcept;
	CommandsContainer& operator=(const CommandsContainer& other);
	~CommandsContainer() noexcept;

	void addCommand(Commands* command);//takes the ownership of the object
	void addCommand(const Commands& command);

	size_t getCnt()const;
	const Commands* operator[](size_t idx) const;
	Commands* operator[](size_t idx);

private:
	Commands** commands_arr = nullptr;
	size_t commands_cnt = 0;
	size_t capacity = 0;

	void copyFrom(const CommandsContainer& other);
	void moveFrom(CommandsContainer&& other);
	void free();

	void resize(size_t new_cap);
};
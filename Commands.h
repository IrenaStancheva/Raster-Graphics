#pragma once
#include <iostream>
#include "UserSession.h"
//pure virtual virtual base class for all our commands
class Commands
{
public:
	Commands(const UserSession& other);//for emptying the stack
	Commands(UserSession&& other);

	//Added a getters for the current session (const and non-const)
	const UserSession& getSession()const;
	UserSession& getSession();

	//changed our execute to a universial one for all commands
	virtual void execute() = 0;
	virtual void executeOnePic() = 0;
	virtual Commands* clone() const = 0;
	virtual const MyString& command_name()const = 0;
	virtual ~Commands() = default;

protected:
	UserSession session;
};
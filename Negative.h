#pragma once
#include "Commands.h"
//we have created a new class for another command
class Negative :
    public Commands
{
public:
    Negative(UserSession& other);
    Negative(UserSession&& other);

    void execute() override;
    void executeOnePic() override;
    Commands* clone() const override;
    const MyString& command_name()const override;
};
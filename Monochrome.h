#pragma once
#include "Commands.h"
//we have created a whole new class for another command
class Monochrome :
    public Commands
{
public:
    Monochrome(UserSession& other);
    Monochrome(UserSession&& other);

    void execute() override;
    void executeOnePic() override;
    Commands* clone() const override;
    const MyString& command_name()const override;
};

#pragma once
#include "Commands.h"
//new class for our rotation command
class Rotate :
    public Commands
{
public:
    Rotate(UserSession& other, const MyString& dir);
    Rotate(UserSession&& other, MyString&& dir);

    void execute() override;
    void executeOnePic() override;
    Commands* clone() const override;
    const MyString& command_name()const override;

private:
    MyString direction;
};
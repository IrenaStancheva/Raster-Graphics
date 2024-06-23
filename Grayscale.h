#pragma once
#include "Commands.h"
class Grayscale :
    public Commands
{
public:
    Grayscale(UserSession& other);
    Grayscale(UserSession&& other);

    //changed the execute function from the base class
    void execute() override;
    void executeOnePic() override;
    Commands* clone() const override;
    const MyString& command_name()const override;
};
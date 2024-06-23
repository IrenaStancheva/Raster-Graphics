#include "Commands.h"

Commands::Commands(const UserSession& other) : session(other) {}
Commands::Commands(UserSession&& other) : session(std::move(other)) {}

//added how the getters work for our class
const UserSession& Commands::getSession() const
{
    return session;
}

UserSession& Commands::getSession()
{
    return session;
}
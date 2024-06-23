#include "UserSession.h"

UserSession::UserSession(const UserSession& other)
{
    copyFrom(other);
}

UserSession& UserSession::operator=(const UserSession& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

UserSession& UserSession::operator=(UserSession&& other)
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

UserSession::UserSession(UserSession&& other)
{
    moveFrom(std::move(other));
}

UserSession::UserSession()
{
    capacity = 4;
    pictures = new PictureTypes * [capacity] {nullptr};
    pictures_cnt = 0;
    id = 0;
}

UserSession::UserSession(int id)
{
    id = id;

    capacity = 4;
    pictures = new PictureTypes * [capacity] {nullptr};
    pictures_cnt = 0;
}

UserSession::UserSession(int id, const PictureTypes**& pics, size_t picture_cnt)
{
    this->id = id;
    pictures = new PictureTypes * [picture_cnt];
    for (size_t i = 0; i < picture_cnt; i++)
    {
        pictures[i] = pics[i]->clone();
    }
    pictures_cnt = picture_cnt;
}

UserSession::UserSession(int new_id, PictureTypes**&& pics, size_t picture_cnt)
{
    pictures = pics;
    pics = nullptr;
    pictures_cnt = picture_cnt;
    picture_cnt = 0;
    this->id = new_id;
    new_id = 0;
}

UserSession::~UserSession()
{
    if (!pictures)
        return;
    for (size_t i = 0; i < pictures_cnt; i++)
    {
        delete pictures[i];
    }
    delete[]pictures;
    pictures = nullptr;
    pictures_cnt = 0;
    id = 0;
}

const PictureTypes& UserSession::operator[](size_t idx) const
{
    return *pictures[idx];
}

PictureTypes& UserSession::operator[](size_t idx)
{
    return *pictures[idx];
}

size_t UserSession::getPicturesCnt() const
{
    return pictures_cnt;
}

size_t UserSession::getCapacity() const
{
    return capacity;
}

void UserSession::addPicture(PictureTypes* pic)
{
    if (pictures_cnt == capacity)
        resize(capacity * 2);
    pictures[pictures_cnt++] = pic;
    pic = nullptr;
}

void UserSession::addPicture(const PictureTypes& pic)
{
    PictureTypes* cloned = pic.clone();
    addPicture(cloned);
}

void UserSession::resize(size_t new_cap)
{
    PictureTypes** newData = new PictureTypes * [new_cap];
    for (size_t i = 0; i < pictures_cnt; i++)
    {
        newData[i] = pictures[i];
    }
    delete[]pictures;
    pictures = newData;
    capacity = new_cap;
}

void UserSession::free()
{
    for (size_t i = 0; i < pictures_cnt; i++)
    {
        delete pictures[i];
    }
    delete[]pictures;
    pictures_cnt = 0;
    id = 0;
    capacity = 0;
}

void UserSession::copyFrom(const UserSession& other)
{
    pictures = new PictureTypes * [other.capacity];
    for (size_t i = 0; i < other.pictures_cnt; i++)
    {
        pictures[i] = other.pictures[i];
    }
    capacity = other.capacity;
    pictures_cnt = other.pictures_cnt;
    id = other.id;
}

void UserSession::moveFrom(UserSession&& other)
{
    pictures = other.pictures;
    other.pictures = nullptr;
    pictures_cnt = other.pictures_cnt;
    other.pictures_cnt = 0;
    capacity = other.capacity;
    other.capacity = 0;
    id = other.id;
    other.id = 0;
}
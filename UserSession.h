#pragma once
#include "PictureTypes.h"
class UserSession
{
public:
	UserSession(const UserSession& other);
	UserSession& operator=(const UserSession& other);
	UserSession& operator=(UserSession&& other);
	UserSession(UserSession&& other);
	UserSession();
	~UserSession();

	UserSession(int id);
	UserSession(int id, const PictureTypes**& pics, size_t picture_cnt);
	UserSession(int id, PictureTypes**&& pics, size_t picture_cnt);

	const PictureTypes& operator[](size_t idx) const;//getter for a picture bu index
	PictureTypes& operator[](size_t idx);
	size_t getPicturesCnt()const;//getter for the pictures count
	size_t getCapacity()const;
	void addPicture(PictureTypes* pic);
	void addPicture(const PictureTypes& pic);

protected:
	int id = 1;
	PictureTypes** pictures = nullptr;
	size_t pictures_cnt = 0;//saving the pictures' count

private:
	size_t capacity = 0;

	void resize(size_t new_cap);

	void free();
	void copyFrom(const UserSession& other);
	void moveFrom(UserSession&& other);
};


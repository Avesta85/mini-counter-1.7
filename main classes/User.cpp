#include "User.h"
#include <iomanip>
#include <openssl/sha.h>
#include <sstream>
 
User::User(std::string _username, std::string _nickname, std::string _password)
	:username(_username), nickname(_nickname), password(_password), win_count(0), lose_count(0)
{
	password = User::Hash_SHA_password(_password);
	
}

std::string User::get_username()
{
	return this->username;
}

std::string User::get_nickname()
{
	return this->nickname;
}

std::string User::get_hashed_password()
{
	return this->password;
}

int User::get_winCount()
{
	return this->win_count;
}

int User::get_loseCount()
{
	return this->lose_count;
}

void User::player_win()
{
	this->win_count++;
}

void User::player_lose()
{
	this->lose_count++;
}

std::string User::Hash_SHA_password(std::string password)
{
	unsigned char hashed[SHA256_DIGEST_LENGTH];

	SHA256((const unsigned char*)password.c_str(), password.size(), hashed);

	std::stringstream ss;

	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
		ss << std::hex << std::setw(2) << std::setfill('0') << (int)hashed[i];

	return ss.str();

}

#include "User.h"
#include <iomanip>
#include <openssl/sha.h>
#include <sstream>
#include <stdexcept>

User::User(std::string _username, std::string _nickname, std::string _password)
	:username(_username), nickname(_nickname), password(_password), win_count(0), lose_count(0)
{
	password = User::Hash_SHA_password(_password);
}

User::User(std::string _username, std::string _nickname, std::string _password, int win_count, int lose_count, std::vector<Gameround>& Game_r)
	:username(_username), nickname(_nickname), password(_password), win_count(win_count), lose_count(lose_count), game_record(Game_r)
{
	if (win_count < 0 || lose_count < 0) throw std::invalid_argument("negative count passed");
}

std::string User::get_username() const
{
	return this->username;
}

std::string User::get_nickname() const
{
	return this->nickname;
}

std::string User::get_hashed_password() const
{
	return this->password;
}

int User::get_winCount() const
{
	return this->win_count;
}

int User::get_loseCount() const
{
	return this->lose_count;
}

std::vector<Gameround> User::get_gameRecord() const
{
	return game_record;
}

void User::add_gameRecord(const Gameround& gr)
{
	game_record.push_back(gr);
}

void User::player_win()
{
	this->win_count++;
}

void User::player_lose()
{
	this->lose_count++;
}

json User::to_json() const
{
	json j_r = json::array();

	for (const auto& r : game_record)
		j_r.push_back(r.to_json());

	return json{
		{"Username", username},
		{"nickname", nickname},
		{"password", password},
		{"wincount", win_count},
		{"losecount", lose_count},
		{"game", j_r}
	};
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

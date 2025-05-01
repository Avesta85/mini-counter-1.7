#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include <sstream>
#include <vector>

using json = nlohmann::json;
using string = std::string;

struct Gameround {
	
	bool is_CT;
	bool won;

	json to_json() const {
		return json{ {"team",is_CT},{"won",won} };
	}
	static Gameround from_json(const json& j){
		return Gameround{ j.at("team"),j.at("won") };
	}

	string to_string() const{
		std::stringstream ss;
		ss << "Team : " << ((is_CT) ? ("CT") : ("Terrorist"))<<"-->";
		ss << ((won) ? ("You Won") : "You lose");

		return ss.str();

	}

};

class User {
public:
	User(std::string _username, std::string _nickname, std::string _password);
	User(std::string _username, std::string _nickname, std::string _password, int win_count, int lose_count,std::vector<Gameround>& Game_r);// for load 
	
	//getter
	std::string get_username() const;
	std::string get_nickname() const;
	std::string get_hashed_password() const;
	int get_winCount() const;
	int get_loseCount() const;
	std::vector<Gameround> get_gameRecord() const;
	//setter

	void add_gameRecord(const Gameround& gr);
	void player_win();
	void player_lose();

	//json support

	json to_json() const;

	static std::string Hash_SHA_password(std::string password);

private:
	std::string username;
	std::string nickname;
	std::string password;
	int win_count;
	int lose_count;
	std::vector<Gameround> game_record;

};

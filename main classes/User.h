#pragma once
#include <string>
#include <nlohmann/json.hpp>


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

};

class User {
public:
	User(std::string _username, std::string _nickname, std::string _password);
	User(std::string _username, std::string _nickname, std::string _password, int win_count, int lose_count,std::vector<Gameround>& Game_r);// for load 
	
	//getter
	std::string get_username();
	std::string get_nickname();
	std::string get_hashed_password();
	int get_winCount();
	int get_loseCount();
	std::vector<Gameround> get_gameRecord();
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

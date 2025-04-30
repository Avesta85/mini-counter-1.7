#pragma once
#include <memory>
#include <string>
#include <stdexcept>


using std::string;

class Node_Guid {

public:

	Node_Guid(string Guid);



	//get
	string get_data();
	std::shared_ptr<Node_Guid> get_next();
	std::weak_ptr<Node_Guid> get_prev();

	//set

	void set_data(string);
	void set_next(std::shared_ptr<Node_Guid>);
	void set_prev(std::weak_ptr<Node_Guid>);





private:

	string data;

	std::shared_ptr<Node_Guid> next;
	std::weak_ptr<Node_Guid> prev;
};

// Doubly and Rotating Linked _ list Guid khodam intory gozashtam
class DRL_list_Guid {

public:

	DRL_list_Guid();

	~DRL_list_Guid();

	string get_cur();
	string go_next();
	string go_prev();
	int get_size();
	string get_head();
	string get_tail();

	void drop(string);

	void pick(string);

	bool is_in_list(string guid);


private:
	

	std::shared_ptr<Node_Guid> begin;
	
	std::weak_ptr<Node_Guid> current;

	int size;

};




#pragma once
#include <memory>


class Node_int {
public:

	Node_int(int val);

	int get_data();

	//get
	std::shared_ptr<Node_int> get_next();
	std::weak_ptr<Node_int> get_prev();

	//set
	void set_data(int);
	void set_next(std::shared_ptr<Node_int>);
	void set_prev(std::weak_ptr<Node_int>);





private:

	int data;

	std::shared_ptr<Node_int> next;
	std::weak_ptr<Node_int> prev;
};

// Doubly and Rotating Linked _ list int khodam intory gozashtam
class DRL_list_int {

public:

	DRL_list_int();

	~DRL_list_int();

	int get_cur();
	int get_next();
	int get_prev();
	int get_size();
	int get_head();
	int get_tail();

	void drop(int);

	void pick(int);




private:
	

	std::shared_ptr<Node_int> begin;
	
	std::weak_ptr<Node_int> current;

	int size;

};




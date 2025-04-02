#include "linked_list_D&R.h"


Node_int::Node_int(int val=0)
	:data(val)
{
	;
}


int Node_int::get_data()
{
	return this->data;
}

std::shared_ptr<Node_int> Node_int::get_next()
{
	return this->next;
}

std::weak_ptr<Node_int> Node_int::get_prev()
{
	return this->prev;
}

void Node_int::set_data(int val)
{
	this->data = val;
}

void Node_int::set_next(std::shared_ptr<Node_int> next)
{
	this->next = next;
}

void Node_int::set_prev(std::weak_ptr<Node_int> prev)
{
	this->prev = prev;
}



DRL_list_int::DRL_list_int()
	:size(0), begin(nullptr), current(begin)
{
}

DRL_list_int::~DRL_list_int()
{
	;
}

int DRL_list_int::get_cur()
{
	return current.lock()->get_data() ;
}

int DRL_list_int::get_next()
{
	current = current.lock()->get_next();
	return current.lock()->get_data();
}

int DRL_list_int::get_prev()
{
	current = current.lock()->get_prev();
	return current.lock()->get_data();
}

int DRL_list_int::get_size()
{
	return size;
}

int DRL_list_int::get_head()
{
	if (begin)
		return begin->get_data();

	return INT_MIN;

}

int DRL_list_int::get_tail()
{
	if(begin)
		return begin->get_prev().lock()->get_data();

	return INT_MIN;
}

void DRL_list_int::drop(int val)
{
	if (begin) {
		if (current.lock()->get_data() == val) {
			current = current.lock()->get_prev();
		}
		if (begin->get_data() == val) {
			if (size == 1)
			{
				begin->set_next(nullptr);
				begin = nullptr;
				size--;
			}
			else
			{
				auto&& last = begin->get_prev().lock();
				begin = begin->get_next();
				begin->set_prev(last);
				last->set_next(begin);
				size--;

			}
		}
		else {
			auto counter = begin->get_next();
			while (counter != begin) {
				if (counter->get_data() == val)
					break;

				counter = counter->get_next();
			}
			if (counter != begin) {
				
				auto nex = counter->get_next();
				auto pre = counter->get_prev().lock();

				nex->set_prev(pre);
				pre->set_next(nex);
				size--;

			}
		}
	}
}

void DRL_list_int::pick(int value)
{
	auto newnode = std::make_shared<Node_int>(value);
	
	if (!begin) {
		begin = newnode;
		begin->set_next(begin);
		begin->set_prev(begin);
		current = begin;
	}
	else {
		auto last = begin->get_prev().lock();

		begin->set_prev(newnode);
		last->set_next(newnode);
		newnode->set_next(begin);
		newnode->set_prev(last);
	}
	size++;
}


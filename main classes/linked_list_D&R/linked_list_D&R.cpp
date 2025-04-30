#include "linked_list_D&R.h"

Node_Guid::Node_Guid(string guid)
	:data(guid)
{
	;

}

string Node_Guid::get_data()
{
	return this->data;
}

std::shared_ptr<Node_Guid> Node_Guid::get_next()
{
	return this->next;
}

std::weak_ptr<Node_Guid> Node_Guid::get_prev()
{
	return this->prev;
}

void Node_Guid::set_data(string Guid)
{
	this->data = Guid;
}
void Node_Guid::set_next(std::shared_ptr<Node_Guid> next_ptr)
{
	this->next = next_ptr;
}
void Node_Guid::set_prev(std::weak_ptr<Node_Guid> prev_ptr)
{
	this->prev = prev_ptr;
}

//DRL_list_int::DRL_list_int()
//	:size(0), begin(nullptr), current(begin)
//{
//}
//
//DRL_list_int::~DRL_list_int()
//{
//	;
//}
//
//int DRL_list_int::get_cur()
//{
//	return current.lock()->get_data() ;
//}
//
//int DRL_list_int::get_next()
//{
//	current = current.lock()->get_next();
//	return current.lock()->get_data();
//}
//
//int DRL_list_int::get_prev()
//{
//	current = current.lock()->get_prev();
//	return current.lock()->get_data();
//}
//
//int DRL_list_int::get_size()
//{
//	return size;
//}
//
//int DRL_list_int::get_head()
//{
//	if (begin)
//		return begin->get_data();
//
//	return INT_MIN;
//
//}
//
//int DRL_list_int::get_tail()
//{
//	if(begin)
//		return begin->get_prev().lock()->get_data();
//
//	return INT_MIN;
//}
//
//void DRL_list_int::drop(int val)
//{
//	if (begin) {
//		if (current.lock()->get_data() == val) {
//			current = current.lock()->get_prev();
//		}
//		if (begin->get_data() == val) {
//			if (size == 1)
//			{
//				begin->set_next(nullptr);
//				begin = nullptr;
//				size--;
//			}
//			else
//			{
//				auto&& last = begin->get_prev().lock();
//				begin = begin->get_next();
//				begin->set_prev(last);
//				last->set_next(begin);
//				size--;
//
//			}
//		}
//		else {
//			auto counter = begin->get_next();
//			while (counter != begin) {
//				if (counter->get_data() == val)
//					break;
//
//				counter = counter->get_next();
//			}
//			if (counter != begin) {
//				
//				auto nex = counter->get_next();
//				auto pre = counter->get_prev().lock();
//
//				nex->set_prev(pre);
//				pre->set_next(nex);
//				size--;
//
//			}
//		}
//	}
//}
//
//void DRL_list_int::pick(int value)
//{
//	auto newnode = std::make_shared<Node_int>(value);
//	
//	if (!begin) {
//		begin = newnode;
//		begin->set_next(begin);
//		begin->set_prev(begin);
//		current = begin;
//	}
//	else {
//		auto last = begin->get_prev().lock();
//
//		begin->set_prev(newnode);
//		last->set_next(newnode);
//		newnode->set_next(begin);
//		newnode->set_prev(last);
//	}
//	size++;
//}

DRL_list_Guid::DRL_list_Guid() :size(0), begin(nullptr), current(begin)
{
	;
}

DRL_list_Guid::~DRL_list_Guid()
{
	;
}

string DRL_list_Guid::get_cur()
{
	if(begin)
		return current.lock()->get_data();

	return "empty";
}

string DRL_list_Guid::go_next()
{
	if (begin) {
		current = current.lock()->get_next();
		return current.lock()->get_data();
	}
	return "empty";
}

string DRL_list_Guid::go_prev()
{
	if (begin) {
		current = current.lock()->get_prev();

		return current.lock()->get_data();
	}
	return "empty";
}

int DRL_list_Guid::get_size()
{
	return this->size;
}

string DRL_list_Guid::get_head()
{
	if(begin)
		return begin->get_data();

	return "empty";
}

string DRL_list_Guid::get_tail()
{
	if (begin)
		return begin->get_prev().lock()->get_data();

	return "empty";
}

void DRL_list_Guid::drop(string guid)
{
	if (!is_in_list(guid)) throw std::invalid_argument("GUN id isnt in list");
	if (begin) {
		if (current.lock()->get_data() == guid) {
			current = current.lock()->get_prev();
		}
		if (begin->get_data() == guid) {
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
				if (counter->get_data() == guid)
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

void DRL_list_Guid::pick(string guid)
{
	auto newnode = std::make_shared<Node_Guid>(guid);
	
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

bool DRL_list_Guid::is_in_list(string guid)
{
	if (begin) {
		auto&& cur = begin->get_next();
		if (begin->get_data() == guid)
			return true;

		while (cur != begin) {
			if (cur->get_data() == guid)
				return true;

			cur = cur->get_next();
		}
		return false;
	}
	return false;
}


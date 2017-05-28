#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include<iostream>
template<typename T>
class Priority_Queue
{
private:
	struct Node
	{
		int m_occurence;
		T m_data;
		Node* m_link;
	};
	Node* m_first;
public:
	Priority_Queue() : m_first(nullptr) {}
	~Priority_Queue();
	void insert(const T data, const int occurence);
	void pop();
	void peek();
	bool isEmpty();
	void print();
	int& getFirstOccurence()
	{
		if (!isEmpty())
		{
			return m_first->m_occurence;
		}
	}
	T& getFirstData()
	{
		if (!isEmpty())
		{
			return m_first->m_data;
		}
	}
private:
	void deleteAll();
};
template<typename T>
Priority_Queue<T>::~Priority_Queue()
{
	deleteAll();
}
template<typename T>
void Priority_Queue<T>::insert(const T data, const int occurence)
{
	Node* tmp = new Node();
	tmp->m_occurence = occurence;
	tmp->m_data = data;
	if (isEmpty() || occurence < m_first->m_occurence)
	{
		tmp->m_link = m_first;
		m_first = tmp;
	}
	else
	{
		Node* tmp1 = new Node();
		tmp1 = m_first;
		while (tmp1->m_link != nullptr && tmp1->m_link->m_occurence <= occurence)
		{
			tmp1 = tmp1->m_link;
		}
		tmp->m_link = tmp1->m_link;
		tmp1->m_link = tmp;
	}

}
template<typename T>
void Priority_Queue<T>::peek()
{
	if (!isEmpty())
	{
		std::cout << "First element is " << m_first->m_data << "  " << m_first->m_occurence << std::endl;
	}
}
template<typename T>
bool Priority_Queue<T>::isEmpty()
{
	if (m_first == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template<typename T>
void Priority_Queue<T>::pop()
{
	if (isEmpty())
	{
		throw "Queue is empty!";
	}
	else
	{
		Node* tmp = m_first;
		m_first = m_first->m_link;
		delete tmp;
	}
}
template<typename T>
void Priority_Queue<T>::print()
{
	Node* ptr = m_first;
	if (isEmpty())
	{
		throw "Queue is empty!";
	}
	else
	{
		std::cout << "____PRIORITY QUEUE____" << std::endl;
		while (ptr != nullptr)
		{

			std::cout << "Number of occurence: " << ptr->m_occurence << "   Number: " << ptr->m_data << std::endl;
			ptr = ptr->m_link;
		}
	}
}
template<typename T>
void Priority_Queue<T>::deleteAll()
{
	while (!isEmpty())
	{
		pop();
	}
	delete m_first;
}
#endif PRIORITY_QUEUE_H

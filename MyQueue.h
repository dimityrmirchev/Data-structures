#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue
{
private:
	struct Node
	{
		T m_value;
		Node* m_previous;
		Node* m_next;
	};
	Node m_pivot;
public:
	Queue();
	~Queue();

	bool isEmpty();
	void push(const T& element);
	void pop();
	T& front();
	T& back();
};

template<typename T>
inline bool Queue<T>::isEmpty()
{
	if (m_pivot.m_previous == &m_pivot && m_pivot.m_next == &m_pivot) return true;
	else return false;
}
template<typename T>
inline Queue<T>::Queue()
{
	m_pivot.m_previous = &m_pivot;
	m_pivot.m_next = &m_pivot;
}
template<typename T>
inline void Queue<T>::push(const T & element)
{
	Node* newElement = new Node;
	newElement->m_value = element;
	m_pivot.m_next->m_previous = newElement;
	newElement->m_next = m_pivot.m_next;
	newElement->m_previous = &m_pivot;
	m_pivot.m_next = newElement;
}

template<typename T>
inline void Queue<T>::pop()
{
	if (!isEmpty())
	{
		Node* tmp = m_pivot.m_previous;
		m_pivot.m_previous = tmp->m_previous;
		tmp->m_previous->m_next = &m_pivot;
		delete tmp;
	}
	else throw "Empty!";
}

template<typename T>
inline T & Queue<T>::front()
{
	if (!isEmpty())
		return m_pivot.m_previous->m_value;
	else throw "Empty!";
}
template<typename T>
inline T& Queue<T>::back()
{
	if (!isEmpty())
		return m_pivot.m_next->m_value;
	else throw "Empty!";
}
template<typename T>
inline Queue<T>::~Queue()
{
	while (!isEmpty())
	{
		pop();
	}
}
#endif QUEUE_H
#ifndef STACK_H
#define STACK_H
template<typename T>
class Stack
{
private:
	struct Node
	{
		T m_data;
		Node* m_next;
	};
	Node* m_top;

public:
	Stack() : m_top(nullptr) {};
	// TODO: Stack& operator=(const Stack&);
	~Stack();

	bool isEmpty();
	void push(const T& value);
	void pop();
	T& peek();
};


template<typename T>
inline Stack<T>::~Stack()
{
	while (!isEmpty())
	{
		pop();
	}
	delete m_top;
}
template<typename T>
inline void Stack<T>::push(const T& value)
{
	Node* ptr = new Node;
	ptr->m_data = value;
	ptr->m_next = nullptr;
	if (!isEmpty())
	{
		ptr->m_next = m_top;
	}
	m_top = ptr;
}
template<typename T>
inline void Stack<T>::pop()
{
	if (!isEmpty())
	{
		Node* tmpPtr = new Node;
		tmpPtr = m_top;
		m_top = m_top->m_next;
		delete tmpPtr;
	}
	else
	{
		throw "Stack is empty!";
	}
}
template<typename T>
inline bool Stack<T>::isEmpty()
{
	if (m_top == nullptr) return true;
	else return false;
}
template<typename T>
inline T& Stack<T>::peek()
{
	if (!isEmpty()) return m_top->m_data;
	else
	{
		throw "Stack is empty!";
	}
}
#endif STACK_H
#ifndef BST_H
#define BST_H

template <typename key>
class BinarySearchTree
{
private:
	struct Node
	{
		char* m_data;
		key m_key;
		Node* m_left;
		Node* m_right;
		Node(): m_left(nullptr), m_right(nullptr) {}
		Node(const key key, const char* data)
		{
			int size = strlen(data) + 1;
			m_data = new (std::nothrow) char[size];
			strcpy(m_data, data);
			m_key = key;
			m_left = nullptr;
			m_right = nullptr;
		}
	};
	int m_removed_elements;
	Node* m_root;
public:
	BinarySearchTree() :m_root(nullptr), m_removed_elements(0) {}
	~BinarySearchTree() { deleteTree(m_root);}
	bool find(const key& key, const char* data)
	{
		return findP(m_root, key, data);
	}
	void insert(const key& key, const char* data)
	{
		insertP(m_root, key, data);
	}
	void remove(const key& key, const char* data)
	{
		removeP(m_root, key, data);
	}
	void removeAll(const key& key)
	{
		removeAllP(m_root, key);
	}
	void print()
	{
		printP(m_root);
	}
private:
	void insertP(Node*& root, const key& key, const char* data);
	bool findP(Node*& root, const key& key, const char* data);
	void removeP(Node*& root, const key& key, const char* data);
	void removeAllP(Node*& root, const key& key);
	void printP(Node*& root);
	void deleteTree(Node*& root);
	Node* getMax(Node*& root);
};
template <typename key>
inline bool BinarySearchTree<key>::findP(Node*& root, const key& key, const char* data)
{
	if (!root) return false;
	else if (root->m_key == key && (!strcmp(root->m_data, data))) return true;
	else if (key < root->m_key || (root->m_key == key && strcmp(root->m_data, data) < 0)) findP(root->m_left, key, data);
	else if (key > root->m_key || (root->m_key == key && strcmp(root->m_data, data) > 0)) findP(root->m_right, key, data);
}
template <typename key>
inline void BinarySearchTree<key>::insertP(Node*& root, const key& key, const char* data)
{
	if (!root) root = new Node(key, data);
	else if (key == root->m_key && (!strcmp(root->m_data, data)))
	{
		
	}
	else if (key < root->m_key || (root->m_key == key && strcmp(root->m_data, data) < 0)) insertP(root->m_left, key, data);
	else if (key > root->m_key || (root->m_key == key && strcmp(root->m_data, data) > 0)) insertP(root->m_right, key, data);
}
template <typename key>
inline void BinarySearchTree<key>::removeP(Node*& root, const key& key, const char* data)
{
	if (!root) return;
	if (root->m_key == key && (!strcmp(root->m_data, data)))
	{
		Node* del = root;
		if (!root->m_left)
		{
			root = root->m_right;
		}
		else if (!root->m_right)
		{
			root = root->m_left;
		}
		else
		{
			Node* max = getMax(root->m_left);
			max->m_left = root->m_left;
			max->m_right = root->m_right;
			root = max;
		}
		delete del;
	}
	else if(key < root->m_key || (key == root->m_key && strcmp(root->m_data, data) < 0))
	{
		removeP(root->m_left, key, data);
	}
	else removeP(root->m_right, key, data);
}
template <typename key>
inline void BinarySearchTree<key>::removeAllP(Node*& root,const key& key)
{
	if (!root)
	{
		std::cout << m_removed_elements << std::endl;
		m_removed_elements = 0;
		return;
	}
	if (root->m_key == key)
	{
		++m_removed_elements;
		Node* del = root;
		if (!root->m_left)
		{
			root = root->m_right;
		}
		else if (!root->m_right)
		{
			root = root->m_left;
		}
		else
		{
			Node* max = getMax(root->m_left);
			max->m_left = root->m_left;
			max->m_right = root->m_right;
			root = max;
		}
		delete del;
		removeAllP(root, key);
	}
	else if (key < root->m_key)
	{
		removeAllP(root->m_left, key);
	}
	else removeAllP(root->m_right, key);
}
template <typename key>
inline void BinarySearchTree<key>::printP(Node*& root)
{
	if (root)
	{
		printP(root->m_left);
		std::cout << "Key:" << root->m_key << " " << "Data:" << root->m_data << " " << std::endl;
		printP(root->m_right);
	}
}
template <typename key>
inline typename BinarySearchTree<key>::Node* BinarySearchTree<key>::getMax(Node*& root)
{
	if (root->m_right) return getMax(root->m_right);
	Node* max = root;
	root = root->m_left;
	return max;
}
template<typename key>
inline void BinarySearchTree<key>::deleteTree(Node*& root)
{
	if (root)
	{
		deleteTree(root->m_left);
		deleteTree(root->m_right);
		delete root;
	}
}
#endif BST_H
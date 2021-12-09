// CPSC-298-6 "Programming in C++"
// In-class Programming Project: Linked List

/// @file LinkedList.cpp
/// @brief Implements a one-directional (or "one-way" or "unidirectional") linked
/// list. Defines a Node class with public member functions. The Node class
/// includes a class-level or static member function that displays the
/// list of Nodes (it does not act on a single Node).

#include <iostream>

template<typename T>
class Node {
public:
	Node(T iData) : m_iData(iData), mp_nodeNext(nullptr) { }
	~Node() { }
public:
	// These are declared public so that they can be accessed
	// without using member accessor functions.
	T m_iData;
	Node<T>* mp_nodeNext;

public:
	/// Display a list of Node objects to standard output given
	/// the head of the list of Nodes. (This is a static
	/// member function; it behaves differently from ordinary
	/// member functions. You cannot use this->m_iData within
	/// this fuction, for example.)
	/// @param [in] p_nodeHead pointer to Node object that is the
	/// head node of a list of Node objects.
	/// @return void
	static void displayList(Node<T>* p_nodeHead)
	{
		Node<T>* p_node = p_nodeHead;
		// Iterate over the list of Nodes beginning from the
		// head of the list. Print the data out for each node.
		// Then, set p_node to point to the next node in the list.
		// Continue until mp_nodeNext is set to nullptr, indicating
		// the end of the list.
		//
		// TODO: Insert a while loop that continues to iterate
		//       so long as the p_node pointer is not the null
		//       pointer, nullptr.
		//

		while(p_node != nullptr)
		{
			// TODO: Insert cout statement to display the data.

			std::cout << p_node->m_iData << std::endl;

			// TODO: Update p_node to point to the next node in
			//       the liked list.

			p_node = p_node->mp_nodeNext;

		}
		return;
	}
};

int main()
{
	{
		// Allocate three node objects within heap memory.
		Node<int>* p_node1 = new Node<int>(10);
		Node<int>* p_node2 = new Node<int>(20);
		Node<int>* p_node3 = new Node<int>(30);

		// Set p_nodeHead to point to the head or leading node
		// in the list of nodes, in this case p_node1.
		Node<int>* p_nodeHead = p_node1;
		p_node1->mp_nodeNext = p_node2; // append p_node2 to the list of Node objects after p_node1.
		p_node2->mp_nodeNext = p_node3; // append p_node3 to the list of Node objects after p_node2.
		p_node3->mp_nodeNext = nullptr; // The end of the list is indicated by a mp_nodeNext value of nullptr.

		Node<int>::displayList(p_nodeHead);  // display the list of nodes to standard output.
	}

	{
		// Allocate three node objects within heap memory.
		Node<double>* p_node1 = new Node<double>(10.1);
		Node<double>* p_node2 = new Node<double>(20.2);
		Node<double>* p_node3 = new Node<double>(30.3);

		// Set p_nodeHead to point to the head or leading node
		// in the list of nodes, in this case p_node1.
		Node<double>* p_nodeHead = p_node1;
		p_node1->mp_nodeNext = p_node2; // append p_node2 to the list of Node objects after p_node1.
		p_node2->mp_nodeNext = p_node3; // append p_node3 to the list of Node objects after p_node2.
		p_node3->mp_nodeNext = nullptr; // The end of the list is indicated by a mp_nodeNext value of nullptr.

		Node<double>::displayList(p_nodeHead);  // display the list of nodes to standard output.
	}
}

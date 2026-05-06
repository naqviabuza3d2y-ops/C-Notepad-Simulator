#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node* next;
	Node* previous;

	Node() : data(0), next(NULL), previous(NULL)
	{
	}

	Node(const T data)
	{
		this->data = data;
		next = NULL;
		previous = NULL;
	}

	~Node()
	{
	}
};

template <typename T>
class Stack //Works on the principle of last in, first out (LIFO)
{
	Node<T>* head; //Will work as top
	Node<T>* tail;
public:

	Stack()
	{
		head = NULL;
		tail = NULL;
	}

	void insertAtHead(T data) //Can only be inserted from the head. If we had to insert 4,3,5 then we have  5 -> 3 -> 4 (with top being 5 as it is the latest entry)
	{
		Node<T>* newNode = new Node<T>(data);

		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

	void removeAtHead() //Can only be removed from the head (If we had  5 -> 4 -> 3 then it would become 4 -> 3 and then 3 and then NULL)
	{
		if (head == NULL)
		{
			cout << "Nothing to remove." << endl;
			return;
		}

		Node<T>* temp = head->next;
		head->next = NULL;
		delete head;
		head = temp;
	}

	T top()
	{
	
		if (!empty() && head)
			return head->data;
	}

	bool empty()
	{
		if (head == NULL)
			return true;
		return false;
	}

};

template <typename T>
class DoublyList
{
	Node<T>* head;
	Node<T>* tail;
	Node <T>* cursor;
	int cursor_index;
	Stack<char> s1;
public:

	DoublyList()
	{
		cursor = new Node<T>('|');
		head = cursor;
		tail = cursor;
		cursor_index = 0;
	}

	void insert(T data) //push-back in STL
	{
		Node<T>* newNode = new Node<T>(data);
		
		newNode->previous = cursor->previous;
		if (cursor->previous)
		{
			cursor->previous->next = newNode;
		}
		cursor->previous = newNode;
		newNode->next = cursor;

		if (head->data == '|')
		{
			head = newNode;
		}

		cursor_index++;
		if (data == 27)
		{
			cursor_index--; //Ending the program through escape key was changing the index so this was necessary
		}
	}

	void remove()
	{
		if (head->data == '|')
		{
			cout << "No entry to be deleted" << endl;
			return;
		}
		if (head->next->data == '|')
		{
			head = head->next;
		}

		Node<T>* temp = cursor->previous;

		if (temp->previous)
			temp->previous->next = cursor;
		cursor->previous = temp->previous;
		temp->next = NULL;
		temp->previous = NULL;

		s1.insertAtHead(temp->data); //Adding in stack
		cursor_index--;

		delete temp;
	}

	void moveLeft()
	{
		Node<T>* temp = cursor->previous;
		
		if (temp)
		{
			cursor->previous = temp->previous;
			if (temp->previous)
				temp->previous->next = cursor;
			temp->next = cursor->next;
			if (cursor->next)
			{
				cursor->next->previous = temp;
			}
			temp->previous = cursor;
			cursor->next = temp;

			if (cursor->previous == NULL)
			{
				head = cursor; //Updating head
			}
		}

		if (cursor_index != 0)
		{
			cursor_index--;
		}
	}

	void moveRight()
	{
		Node<T>* temp = cursor->next;
		bool wasHead = false;

		if (cursor->previous == NULL)
		{
			wasHead = true; //Checking at the start whether it was at head or not
		}

		if (temp)
		{
			temp->previous = cursor->previous;
			cursor->next = temp->next;
			if (temp->next)
			{
				temp->next->previous = cursor;
			}
			if (cursor->previous)
			{
				cursor->previous->next = temp;
			}
			temp->next = cursor;
			cursor->previous = temp;

			if (wasHead)
				head = temp; //Updating head otherwise I was unable to move right when I was on the leftmost position as head wasn't updated in the correct manner
		}

		
		//Index correction
		static int correct = 0;
		if (cursor->next == NULL)
			cursor_index = correct + 1;
		else
			correct = ++cursor_index;
	
	}

	void enter()
	{
		insert('\n');
	}

	void redo()
	{
		if (!s1.empty()) //Keeps cursor_index in control
		{
			insert(s1.top());
			s1.removeAtHead();
		}
	}

	void print()
	{
		Node<T>* current = head;

		while (current != NULL)
		{
			cout << current->data;
			current = current->next;
		}
		cout << endl << endl << endl << endl;
		cout << "Cursor Index: " << cursor_index << endl;

	}


	~DoublyList()
	{
	}
};
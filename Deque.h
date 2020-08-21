#pragma once
#include<iostream>
using std::except;

using std::cout;
using std::endl;


class Node {
private:
	int data;
	Node* next;
	Node* prev;
public:
	~Node();
	Node();
	Node(Node& nd);
	Node(int val, Node *next, Node *prev);
	int getData();
	Node getPrev();
	void setData(int data);
	void setNext(Node* next);
	void setPrev(Node* prev);
	Node getNext();
	Node& operator=(Node& nd) 
	{
		if (this == &nd)
			return *this;
		this->~Node();
		this->data = nd.data;
		this->next = nd.next;
		this->prev = nd.prev;
		return *this;
	}
	bool operator!=(Node& nd) 
	{
		if (this == &nd)
			return false;
		else
			return true;
	}
	bool operator==(Node& nd) 
	{
		if (this == &nd)
			return true;
		else
			return false;
	}
	void print()
	{
		cout << this->getData() << endl;
	}
};
Node::~Node()
{
	delete prev;
	delete next;
}
int Node::getData()
{
	return this->data;
}
Node Node::getNext()
{
	return *next;
}
Node Node::getPrev()
{
	return *prev;
}
void Node::setData(int data)
{
	this->data = data;
}
void Node::setPrev(Node* prev)
{
	this->prev = prev;
}
void Node::setNext(Node* next) 
{
	this->next = next;
}
Node::Node()
{
	this->data = 0;
	this->next = nullptr;
	this->prev = nullptr;
}
Node::Node(Node& nd)
{
	this->data = nd.data;
	this->next = nd.next;
	this->prev = nd.prev;
}
Node::Node(int val, Node *next, Node *prev)
{
	this->data = val;
	this->next = next;
	this->prev = prev;
}
//template<class T>
class Deque:public Node {
private:
	Node* head;
public:
	Deque(Node &nd) {
		head = &nd;
	}
	Deque(const Deque& dq) {
		
	}
	Deque& operator=(Deque& dq)
	{
		if (&dq != this)
		{
			this->~Deque();
			Node* p = dq.head;
			while (p->getNext() != nullptr)
			{
				this->InsertBack(p);
			}
		}
		return *this;
	}
	~Deque() 
	{
	}
	void InsertFront(Node* nd)
	{
		Node* temp = nd;
		head->setPrev(nd);
		nd->setNext(head);
		nd->setPrev(nullptr);
		head = nd;
	}
	void InsertBack(Node* nd)
	{
		Node* p=new Node(head);
		while (p->getNext() && p->getNext()->getNext()!= nullptr)
		{
			p = p.getNext();
		}
		p->getNext()->setData(nd->getData());
		p->next->next = nullptr;
		p->next->prev = p;
	}
	void RemoveFront()
	{
		Node* temp = head;
		head->setNext(temp->getNext());
		delete temp;
	}
	void RemoveBack()
	{

	}
	void print();
};
void Deque::print()
{
	Node* p = new Node(head);
	while (p->getNext() != nullptr)
	{
		cout << p->getData() << endl;
		p->setNext(p->getNext());
	}
	delete p;
}

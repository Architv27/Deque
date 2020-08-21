#include"Deque.h"

int main()
{
	Node* nd=new Node(5,nullptr,nullptr);
	Node* nd2 = new Node();
	nd2 = nd;
	(*nd2).print();
	delete nd;
	delete nd2;
	system("pause");
	return 0;
}
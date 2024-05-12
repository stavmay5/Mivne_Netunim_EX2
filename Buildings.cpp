/*
		Stav Macri 324084722 - סתיו מכרי
		Nadav Swartz 208296400 - נדב שוורץ
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class Stack
{
private:
	struct Node
	{
		int data;
		Node* next;

		Node(int d, Node* n = nullptr) : data(d), next(n) {}
	};

	Node* top;

public:
	Stack() : top(nullptr) {}

	void push(int data)
	{
		top = new Node(data, top);
	}

	void pop()
	{
		if (!isEmpty())
		{
			Node* temp = top;
			top = top->next;
			delete temp;
		}
	}

	int Top()
	{
		if (!isEmpty())
		{
			return top->data;
		}
		return -1;
	}

	bool isEmpty()
	{
		return top == nullptr;
	}

	~Stack()
	{
		while (!isEmpty())
		{
			pop();
		}
	}
};

int main()
{
	int i;
	
	int A[] = { 101, 87, 122, 208, 74, 107, 152, 130, 200, 53, 89, 133, 47, 13, 98, 100, 345, 233, 45, 67, 89, 433, 98, 65, 32, 11, 2555, 67, 34, 222 };
	const int len = 30;
	int B[len + 1];

	Stack S;
	/*
	cout << "Enter " << len << " Numbers " << endl;
	for (i = 0; i < len; i++)
	{
		cout << "Enter Number " << i + 1 << endl;
		cin >> A[i];
	}
	*/
	S.push(-1);
	S.push(0);
	B[0] = 0;
	B[1] = 0;

	i = 1;

	while (!S.isEmpty() && S.Top() != -1 && i < len)
	{
		if ((A[i] <= A[S.Top()]))
		{
			B[i + 1] = S.Top() + 1;
			S.push(i);
			i++;
		}
		else
		{
			S.pop();
		}
		if (S.Top() == -1)
		{
			B[i + 1] = 0;
			S.push(i);
			i++;
		}
	}

	cout << " " << "The Array is: " << endl;
	for (i = 0; i < len; i++)
	{
		cout << " " << A[i];
	}

	cout << endl;
	cout << endl;

	for (i = 1; i <= len; i++)
	{
		cout << " " << "Building " << i << " is seeing building: " << B[i] << endl;
	}

	return 0;
}
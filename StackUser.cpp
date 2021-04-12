#include "Stack.h"

#include <iostream>
using namespace std;


// A function to print stack contents
//as the function shoud operate on a class template, the function itself should be a function template as well
template <typename T>
void PrintStack(Stack<T> S)
{
	cout << endl << "Printing stack contents: ";

	T x;
	while (S.pop(x))
		cout << x << " ";

	cout << endl;
}

//A function that takes a Stack<T> S and returns its reverse (without affecting the orignal stack)
template <typename T>
Stack<T> Reverse(Stack<T> S)
{
	Stack<T> Rev(S.getSize());	//First creat a stack with same size as S
	T Item;
	while (S.pop(Item))	//pop from S
		Rev.push(Item); //push into Rev

	return Rev;
}

template <typename T>
void ReverseMe(Stack<T>& a)
{
	Stack<T> temp1(a.getSize());	
	T Item;
	while (a.pop(Item))	
		temp1.push(Item); 
	Stack<T> temp2(a.getSize());
	while (temp1.pop(Item))	
		temp2.push(Item); 
	while (temp2.pop(Item))	
		a.push(Item); 
}


void collapse(Stack<int> a)
{
	Stack<int> temp1(a.getSize());
	int item1, item2, item;
	while (a.pop(item1) && a.pop(item2))
	{
		item = item1 + item2;
		temp1.push(item);
	}
	while (temp1.pop(item))
		a.push(item);
}


int main()

{
	Stack<int> stack1(20);

	int i, x;

	//Test the 1st stack by pushing 1, 2, 3, 4 and 5 then popping them.
	cout << "Testing stack 1:" << endl;
	cout << "Pushing 5 values into stack 1:" << endl;

	//Reading From the user 5 integer values
	cout << "Please Enter the 5 values to push in stack1 :";
	for (i = 0; i < 5; i++)
	{
		cin >> x;
		stack1.push(x); //pushing x to stack1
	}

	cout << "\nstack1 contents\n";
	PrintStack(stack1);
	//ReverseMe(stack1);

	collapse(stack1);
	PrintStack(stack1);

	/*Stack<int> stack2(20);
	stack2 = Reverse(stack1);

	cout << "\nstack2 contents\n";
	PrintStack(stack2);

	cout << endl;*/
	return 0;


}



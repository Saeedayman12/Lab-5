/*
This is a program that implements the stack abstract data type using an array.
*/


// Define a template class that contains an array of 100 element named "array"
// and an integer named "top".
template <class T>
class Stack
{
	int STACK_SIZE;
	T* elements;	//pointer to hold array of elements
	int top;
public:
	Stack(int MaxSize);
	bool push(T x);
	bool pop(T& x);
	bool getTopItem(T& x) const;
	bool isFull();
	bool isEmpty() const;
	int getSize() const;
	~Stack();
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: Stack()
The constructor of the Stack class.

*/

template <class T>
Stack<T>::Stack(int MaxSize)
{
	top = -1;
	STACK_SIZE = MaxSize;
	elements = new T[STACK_SIZE];
}


///////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: Destructor

Free reserved memory
*/
template <class T>
Stack<T>:: ~Stack()
{
	//delete []elements;

	//Note: If you want the destuctor to work properly, you should:
	// 1- Make both Copy Constructor and assignment operator for class Stack<T>
	// 2- uncomment the desturtor body
}

///////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: isEmpty

Checks whether a stack is empty
*/
template <class T>
bool Stack<T>::isEmpty() const
{
	if (top == -1) return true;
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: isFull
Checks whether a stack is full
*/
template <class T>
bool Stack<T>::isFull()
{
	if (top == STACK_SIZE - 1) return true;
	return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////

//function push
/*
Function: push
Pushes an element onto a stack.

Parameters:
	x - The element to be pushed.

*/
template <class T>
bool Stack<T>::push(T x)
{
	if (isFull()) return false; // check if the stack is full, then we can't push the element x

	top++;
	elements[top] = x;
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: pop
Removes the top item of this stack.

Returns:
	The popped element.
*/

template <class T>
bool Stack<T>::pop(T& popedItem)
{
	if (!isEmpty())
	{
		popedItem = elements[top];
		top--;
		return true;
	}
	return false;
}


///////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: getTopItem
get the top item of the stack without removing it from the stack

Returns:
	The top item of the stack.
*/

template <class T>
bool Stack<T>::getTopItem(T& popedItem) const
{
	if (!isEmpty())
	{
		popedItem = elements[top];
		return true;
	}
	return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: igetSize

Returns the size of the stack
*/
template <class T>
int Stack<T>::getSize() const
{
	return STACK_SIZE;
}









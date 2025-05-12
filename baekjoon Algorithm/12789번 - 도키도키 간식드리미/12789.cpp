#include <iostream>

#define MaxSize 1001

class stack
{
private:
	int* stack_, top, size_;
public:
	stack(int num);
	~stack();

	bool isFull();
	bool isEmpty();
	bool push(int item);
	int pop();
	int size();
	int peek();
};

stack::stack(int num) {
	stack_ = new int[num];
	top = -1;
	size_ = 0;
}

stack::~stack() {
	delete[] stack_;
}
bool stack::isFull() {
	return (top == MaxSize - 1);
}

bool stack::isEmpty() {
	return (top == -1);
}

bool stack::push(int item)
{
	if (isFull())
	{
		std::cout << "stack overflow" << "\n";
		return false;
	}
	stack_[++top] = item; size_++;
	return true;
}

int stack::pop()
{
	if (isEmpty())
	{
		return -1;
	}
	int value = stack_[top--];
	size_--;
	return value;
}

int stack::size()
{
	return size_;
}

int stack::peek()
{
	if (!isEmpty())
		return stack_[top];
	else return -1;
}

int main()
{
	int N, M;
	int order = 1;
	stack st(MaxSize);
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> M;
		st.push(M);

		if (M == order)
		{
			while (order == st.peek())
			{
				st.pop();
				order++;
			}
		}
	}

	if (st.isEmpty())
	{
		std::cout << "Nice" << "\n";
	}
	else std::cout << "Sad" << "\n";
}
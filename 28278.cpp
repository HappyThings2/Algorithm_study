#include <iostream>
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
	return (top == 1000000 - 1);
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
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N, M;
	stack st(1000000);
	std::cin >> N;

	while (N--)
	{
		std::cin >> M;

		if (M == 1)
		{
			int value = 0;
			std::cin >> value;
			st.push(value);
		}

		if (M == 2)
		{
			std::cout << st.pop() << "\n";
		}

		if (M == 3)
		{
			std::cout << st.size() << "\n";
		}

		if (M == 4)
		{
			std::cout << st.isEmpty() << "\n";
		}

		if (M == 5)
		{
			std::cout << st.peek() << "\n";
		}

	}
}

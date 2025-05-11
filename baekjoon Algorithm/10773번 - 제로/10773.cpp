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
	stack_[++top] = item; 
	size_++;
	return true;
}

int stack::pop()
{
	if (isEmpty())
	{
		return -1;
	}
	size_--;
	return stack_[top--];
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
	int sum = 0;
	stack st(1000000);
	std::cin >> N;

	while (N--)
	{
		std::cin >> M;

		if (M != 0)
		{
			st.push(M);
		}
		else st.pop();
	}

	while(!st.isEmpty())
	{
		sum += st.pop();
	}
	std::cout << sum << "\n";
}


/* 
for (int i = 0; i < st.size(); i++)
{
	sum += st.pop();
}

st.size() 함수를 통해서 스택의 크기만큼 반복하겠다는 의도이지만,
st.pop()을 할 때마다 스택의 크기가 줄어들어 의도한대로 작동하지 않는다.

*/

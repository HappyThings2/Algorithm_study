#include <iostream>
#include <string>
#include <cstring>

#define Max_size 51

class stack
{
private:
	char s2[50];
	int top;
	int size_;
public:
	stack();

	bool isFull();
	bool isEmpty();
	bool push(char item);
	char pop();
	int size();
	int peek();
};

stack::stack()
{
	top = -1;
	size_ = 0;
}

bool stack::isFull() {
	return (top == Max_size - 1);
}

bool stack::isEmpty() {
	return (top == -1);
}

bool stack::push(char item)
{
	if (isFull())
	{
		std::cout << "stack overflow" << "\n";
		return false;
	}
	s2[++top] = item; size_++;
	return true;
}

char stack::pop()
{
	if (isEmpty())
	{
		return -1;
	}
	size_--;
	return s2[top--];
}

int stack::size()
{
	return size_;
}

int stack::peek()
{
	if (!isEmpty())
		return s2[top];
	else return -1;
}

int main()
{
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		char s1[Max_size];
		bool check = false;
		stack st;
		std::cin >> s1;
		size_t len = strlen(s1);
		

		for (size_t i = 0; i < len; i++)
		{
			if (s1[i] == '(')
			{
				st.push(s1[i]);
			}
			else if (s1[i] == ')')
			{
				if (st.isEmpty())
				{
					check = true;
					break;
				}
				else
				{
					char s3 = st.pop();
					if (s3 != '(')
					{
						check = true;
					}
				}
			}
		}

		if (!check && st.isEmpty())
		{
			std::cout << "YES" << "\n";
		}
		else
		{
			std::cout << "NO" << "\n";
		}
	}
}
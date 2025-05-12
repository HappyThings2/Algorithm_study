#include <iostream>
#include <string>
#include <cstring>

#define Max_size 101

class stack
{
private:
	char s2[Max_size];
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
	while (true)
	{
		bool check = true;
		stack st;
		char s1[101];
		std::cin.getline(s1, 101);
		int len = strlen(s1);

		if (strcmp(s1, ".") == 0) break;

		for (int i = 0; i <= len; i++)
		{
			if (s1[i] == '(' || s1[i] == '[')
			{
				st.push(s1[i]);
			}
			else if (s1[i] == ')' || s1[i] == ']')
			{
				if (st.isEmpty())
				{
					check = false;
					break;
				}
				else if (s1[i] == ')')
				{
					char s3 = st.pop();
					if (s3 != '(')
					{
						check = false;
					}
				}
				else if (s1[i] == ']')
				{
					char s3 = st.pop();
					if (s3 != '[')
					{
						check = false;
					}
				}
			}
		}

		if (check && st.isEmpty())
		{
			std::cout << "yes" << "\n";
		}
		else
		{
			std::cout << "no" << "\n";
		}
	}
}
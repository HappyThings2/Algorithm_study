#include <iostream>
#include <cstring>

#define Max_size 2000001

class Queue
{
private:
	int* queue;
	int front, rear, size;
public:
	Queue(int capacity);
	~Queue();
	bool isFull();
	bool isEmpty();
	void enQueue(int item);
	int deQueue();
	int peek();
	int size_();
	int front_();
};

Queue::Queue(int capacity)
{
	queue = new int[capacity];
	front = -1;
	rear = -1;
	size = 0;

}

Queue::~Queue()
{
	delete[]queue;
}

bool Queue::isFull()
{
	return rear == Max_size - 1;
}

bool Queue::isEmpty()
{
	return front == rear;
}

void Queue::enQueue(int item)
{
	if (isFull())
	{
		std::cout << "Queue overflow";
	}

	queue[++rear] = item;
	size++;
}

int Queue::deQueue()
{
	if (isEmpty())
	{
		return -1;
	}

	size--;
	return queue[++front];
	
}

int Queue::peek()
{
	if (isEmpty())
	{
		return -1;
	}
	return queue[rear];
}

int Queue::size_()
{
	return this->size;
}

int Queue::front_()
{
	if (isEmpty())
	{
		return -1;
	}
	return queue[front + 1];
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	Queue queue(Max_size);
	char ss[50];

	std::cin >> N;

	while (N--)
	{
		std::cin >> ss;

		if (strcmp(ss, "push")==0)
		{
			int value;
			std::cin >> value;
			queue.enQueue(value);
		}

		else if (strcmp(ss, "front") == 0)
		{
			std::cout << queue.front_() << "\n";
		}

		else if (strcmp(ss, "back") == 0)
		{
			std::cout << queue.peek() << "\n";
		}

		else if (strcmp(ss, "size") == 0)
		{
			std::cout << queue.size_() << "\n";
		}

		else if (strcmp(ss, "empty") == 0)
		{
			std::cout << queue.isEmpty() << "\n";
		}

		else if (strcmp(ss, "pop") == 0)
		{
			std::cout << queue.deQueue() << "\n";
		}

	}
}
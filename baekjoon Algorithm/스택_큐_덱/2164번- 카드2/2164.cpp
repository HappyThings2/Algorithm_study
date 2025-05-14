#include <iostream>

#define Max_size 500001

class Queue
{
private:
	int* queue;
	int front, rear, size;
	int capacity;
public:
	Queue(int capacity);
	~Queue();
	bool isFull();
	bool isEmpty();
	void enQueue(int item);
	int deQueue();
	int size_();
};

Queue::Queue(int capacity)
{
	this->capacity = capacity;
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
	return size == capacity;
}

bool Queue::isEmpty()
{
	return size == 0;
}

void Queue::enQueue(int item)
{
	if (isFull())
	{
		std::cout << "Queue overflow";
		return;
	}

	rear = (rear + 1) % capacity;
	queue[rear] = item;
	size++;
}

int Queue::deQueue()
{
	if (isEmpty())
	{
		return -1;
	}

	front = (front + 1) % capacity;
	size--;
	return queue[front];

}

int Queue::size_()
{
	return this->size;
}

int main()
{
	int N;
	Queue queue(Max_size);
	std::cin >> N;
	int order = 0;

	for (int i = 1; i <= N; i++)
	{
		queue.enQueue(i);
	}

	while (queue.size_() != 1)
	{

		if ((order % 2) == 0)
		{
			queue.deQueue();
			order++;

		}
		else
		{
			int retry = queue.deQueue();
			queue.enQueue(retry);
			order++;
		}
	}
	std::cout << queue.deQueue();
}
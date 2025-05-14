#include <iostream>

#define Max_size 1000

class Queue
{
private:
	int* queue;
	int front, rear;
	int capacity;
	int size_;
public:
	Queue(int capacity);
	~Queue();
	bool isFull();
	bool isEmpty();
	void enQueue(int item);
	int deQueue();
	int size();

};

Queue::Queue(int capacity)
{
	queue = new int[capacity];
	this->capacity = capacity;
	front = -1;
	rear = -1;
	size_ = 0;
}

Queue::~Queue()
{
	delete[]queue;
}

bool Queue::isFull()
{
	return size_ == capacity;
}

bool Queue::isEmpty()
{
	return size_ == 0;
}

void Queue::enQueue(int item)
{
	if (isFull())
	{
		std::cout << "Queue overflow" << "\n";
		return;
	}

	rear = (rear + 1) % capacity;
	queue[rear] = item;
	size_++;
}

int Queue::deQueue()
{
	if (isEmpty())
	{
		std::cout << "Queue underflow" << "\n";
		return -1;
	}

	size_--;
	front = (front + 1) % capacity;
	return queue[front];
}

int Queue::size()
{
	return size_;
}

int main()
{
	int N, K;
	Queue queue(Max_size);

	std::cin >> N >> K;

	int order = -1;
	int count = 0;
	int selected = 0;

	int* p = new int[N];
	int* check = new int[N]();
	for (int i = 0; i < N; i++)
	{
		p[i] = i + 1;
	}

	while (selected < N)
	{
		order = (order + 1) % N;

		if (check[order] == 1)
			continue;

		count++;

		if (count == K)
		{
			queue.enQueue(p[order]);
			check[order] = 1;
			count = 0;
			selected++;
		}
	}

	std::cout << "<";
	int qsize = queue.size();
	for (int i = 0; i < qsize; i++)
	{
		std::cout << queue.deQueue();
		if (i != qsize - 1)
			std::cout << ", ";
	}
	std::cout << ">";

	delete[] p;
	delete[] check;
}
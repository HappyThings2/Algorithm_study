#include <iostream>

#define MaxSize 1000001

class Deque
{
private:
    int* deque;
    int size, capacity;
    int front, rear;

public:
    Deque(int capacity);
    ~Deque();
    void frontDeque(int item);
    void rearDeque(int item);
    int getSize();
    int isEmpty();
    int getFrontDeque();
    int getFrontDequeShow();
    int getrearDeque();
    int getrearDequeShow();
};

Deque::Deque(int capacity)
{
    this->capacity = capacity;
    deque = new int[capacity];
    front = 0;
    rear = 0;
    size = 0;
}

Deque::~Deque()
{
    delete[] deque;
}

void Deque::frontDeque(int item)
{
    if (size < capacity)
    {
        front = (front - 1 + capacity) % capacity;
        deque[front] = item;
        size++;
    }
}

void Deque::rearDeque(int item)
{
    if (size < capacity)
    {
        deque[rear] = item;
        rear = (rear + 1) % capacity;
        size++;
    }
}

int Deque::getSize()
{
    return size;
}

int Deque::isEmpty()
{
    return size == 0 ? 1 : 0;
}

int Deque::getFrontDeque()
{
    if (size == 0) return -1;
    int value = deque[front];
    front = (front + 1) % capacity;
    size--;
    return value;
}

int Deque::getrearDeque()
{
    if (size == 0) return -1;
    rear = (rear - 1 + capacity) % capacity;
    int value = deque[rear];
    size--;
    return value;
}

int Deque::getFrontDequeShow()
{
    if (size == 0) return -1;
    return deque[front];
}

int Deque::getrearDequeShow()
{
    if (size == 0) return -1;
    return deque[(rear - 1 + capacity) % capacity];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, command;
    Deque deque(MaxSize);

    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> command;
        switch (command)
        {
        case 1:
        {
            int value;
            std::cin >> value;
            deque.frontDeque(value);
            break;
        }
        case 2:
        {
            int value;
            std::cin >> value;
            deque.rearDeque(value);
            break;
        }
        case 3:
            std::cout << deque.getFrontDeque() << "\n";
            break;

        case 4:
            std::cout << deque.getrearDeque() << "\n";
            break;

        case 5:
            std::cout << deque.getSize() << "\n";
            break;

        case 6:
            std::cout << deque.isEmpty() << "\n";
            break;

        case 7:
            std::cout << deque.getFrontDequeShow() << "\n";
            break;

        case 8:
            std::cout << deque.getrearDequeShow() << "\n";
            break;

        default:
            break;
        }
    }
}

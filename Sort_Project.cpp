#include <iostream>

class Save
{
	friend class Sort;
private:
	int* ary;
	int size;
public:
	void init()
	{
		int num;
		std::cout << "배열의 크기를 입력해주세요: ";
		std::cin >> size;
		ary = new int[size];

		std::cout << "배열에 저장할 값을 입력해주세요: ";

		for (int i = 0; i < size; i++)
		{
			std::cin >> num;
			ary[i] = num;
		}
	}
	int getSize()
	{
		return size;
	}
	void show()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << ary[i] << " ";
		}
		std::cout << "\n";
	}


	~Save()
	{
		delete[]ary;
	}
};
class Sort
{
private:

public:
	static void Selection_Sort(Save& A)
	{
		for (int i = 0; i < A.getSize() - 1; i++)
		{
			int least = i;
			for (int j = i + 1; j < A.getSize(); j++)
			{
				if (A.ary[least] > A.ary[j])
				{
					least = j;
				}
			}
			std::swap(A.ary[i], A.ary[least]);
		}
	}

	/*
	Selection
	1. for i = 0 to size - 2
	2.    least <- i
	3.    for j = i + 1 to size - 1
	4.       if Array[least] > Array[j]
	5.            least = j; 
	6.       swap Array[i] Array[least]
	*/

	static void Insertion_Sort(Save& A)
	{
		for (int j = 1; j < A.getSize(); j++)
		{
			int key = A.ary[j];
			int i = j - 1;
			while ((i >= 0) && (A.ary[i] > key))
			{
				A.ary[i + 1] = A.ary[i];
				i--;
			}
			A.ary[i + 1] = key;
		}
	}

	/*
	1. for j = 1 to length - 1
	2.     key <- A[j]
	3.     i <- j - 1
	4.     while i >= 0 and A[i] > key
	5.           A[i + 1] <- A[i]
	6.           i <- i - 1
	7.     A[i + 1] <- key
	*/

	static void print(Save& A)
	{
		for (int i = 0; i < A.getSize(); i++)
		{
			std::cout << A.ary[i] << " ";
		}
		std::cout << "\n";
	}
};
int main()
{
	Save AAA;
	AAA.init();
	Sort::Selection_Sort(AAA);
	Sort::print(AAA);
	Sort::Insertion_Sort(AAA);
	Sort::print(AAA);

	return 0;
}
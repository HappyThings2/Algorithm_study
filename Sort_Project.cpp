#include <iostream>

class Save
{
	friend class Selection;
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
class Selection
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

	static void print(Save& A)
	{
		for (int i = 0; i < A.getSize(); i++)
		{
			std::cout << A.ary[i] << " ";
		}
	}
};
int main()
{
	Save AAA;
	AAA.init();
	AAA.show();
	Selection::Selection_Sort(AAA);
	Selection::print(AAA);

	return 0;
}
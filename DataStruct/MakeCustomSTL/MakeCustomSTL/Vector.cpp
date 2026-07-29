#include <iostream>
#include <string>
template <typename T>

class Vector
{
	typedef T value_type;
	private:
		T* mData;
		int mSize;
		int mCapacity;

	public:
		Vector(int n = 1) : mData(new T[n]), mCapacity[n], mSize[0] {};
		
		void resize(int capacity)
		{

		}

		void push_back(T data);

		T operator[](int i) { return mData[i]; }

		T find(T data);
		void insert(T data);
		void erase(T data);
		void reverse();
		void clear();
};

int main()
{

}
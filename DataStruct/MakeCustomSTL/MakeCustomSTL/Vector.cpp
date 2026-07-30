#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Vector
{
	typedef T value_type;
	private:
		T* mData;
		int mSize;
		int mCapacity;

	public:
		Vector(int n = 1) : mData(new T[n]), mCapacity(n), mSize(n) 
		{
			for (int i = 0; i < n; ++i) mData[i] = T();
		};

		void reserve(int newCapacity)
		{
			if (newCapacity <= mCapacity) return;

			T* newData = new T[newCapacity];

			for (int i = 0; i < mSize; ++i)
			{
				newData[i] = mData[i];
			}

			delete[] mData;

			mData = newData;
			mCapacity = newCapacity;
		}
		
		void resize(int newSize)
		{
			if (newSize > mCapacity)
			{
				reserve(newSize);
			}

			if (newSize > mSize)
			{
				for (int i = mSize; i < newSize; ++i)
				{
					mData[i] = T();
				}
			}

			mSize = newSize;
		}

		void push_back(T data)
		{
			if (mCapacity <= mSize + 1)
			{
				mData[mSize++] = data;
			}
		}

		T& operator[](int i) { return mData[i]; }

		int find(T data)
		{
			for (int i = 0; i < mSize; ++i)
			{
				if (data == mData[i]) return i;
			}
		}

		void insert(int index, T data)
		{
			if (mCapacity <= mSize + 1)
			{
				T* newData = new T[mCapacity];

				for (int i = 0; i < index; ++i)
				{
					newData[i] = mData[i];
				}

				newData[index] = data;
				mSize++;

				for (int i = index + 1; i < mSize; ++i)
				{
					newData[i] = mData[i-1];
				}

				delete[] mData;
				mData = newData;
			}
		}

		void erase(T data)
		{
			int index = -1;
			for (int i = 0; i < mSize; ++i)
			{
				if (mData[i] == data)
				{
					index = i;
					break;
				}
			}

			if (index != -1)
			{
				T* newData = new T[mCapacity];

				for (int i = 0; i < index; ++i)
				{
					newData[i] = mData[i];
				}

				mSize--;

				for (int i = index + 1; i < mSize; ++i)
				{
					newData[i] = mData[i+1];
				}

				delete[] mData;
				mData = newData;
			}
		}

		void reverse()
		{
			T* newData = new T[mCapacity];

			for (int i = 0; i < mSize; ++i)
			{
				newData[mSize - i - 1] = mData[i];
			}
		}

		int size()
		{
			return mSize;
		}

		void clear()
		{
			delete[] mData;
			mSize = 0;
		}
};

int main()
{
	Vector<int> container(1);//컨테이너생성시 크기를 지정가능하다.
	container[0] = 10;
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.resize(3); //배열의 크기를 지정한다.
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	//1.추가 2.삽입 3.삭제 4.모두삭제
	for (int i = 0; i < container.size(); i++)
		cout << container[i] << ",";
	cout << endl;
	container.clear(); //모두삭제
	cout << "Clear:";
	for (int i = 0; i < container.size(); i++)
		cout << container[i] << ",";
	cout << endl;
}
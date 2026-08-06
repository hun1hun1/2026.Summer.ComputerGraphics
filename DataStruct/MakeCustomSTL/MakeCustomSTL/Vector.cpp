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
		class iterator
		{
			private:
				T* ptr;

			public:
				iterator(T* p = nullptr) : ptr(p) {}

				T& operator*() { return *ptr; }

				iterator& operator++()
				{
					++ptr;
					return *this;
				}

				iterator operator++(int)
				{
					iterator temp = *this;
					++ptr;
					return temp;
				}

				bool operator!=(const iterator& other) const
				{
					return ptr != other.ptr;
				}

				bool operator==(const iterator& other) const
				{
					return ptr == other.ptr;
				}

				T* get() const
				{
					return ptr;
				}
		};

		Vector(int n = 1) : mData(new T[n]), mCapacity(n), mSize(n) 
		{
			for (int i = 0; i < n; ++i) mData[i] = T();
		};

		Vector(int n, T init) : mData(new T[n]), mCapacity(n), mSize(n)
		{
			for (int i = 0; i < n; ++i) mData[i] = init;
		};

		iterator begin()
		{
			return iterator(mData);
		}

		iterator end()
		{
			return iterator(mData + mSize);
		}

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
			if (mSize >= mCapacity)
			{
				reserve(mCapacity * 2);
			}

			mData[mSize++] = data;
		}

		T& operator[](int i) { return mData[i]; }

		int find(T data)
		{
			for (int i = 0; i < mSize; ++i)
			{
				if (mData[i] == data)
					return i;
			}

			return -1;
		}

		// void insert(int index, T data)
		// {
		// 	if (mCapacity <= mSize + 1)
		// 	{
		// 		T* newData = new T[mCapacity];

		// 		for (int i = 0; i < index; ++i)
		// 		{
		// 			newData[i] = mData[i];
		// 		}

		// 		newData[index] = data;
		// 		mSize++;

		// 		for (int i = index + 1; i < mSize; ++i)
		// 		{
		// 			newData[i] = mData[i-1];
		// 		}

		// 		delete[] mData;
		// 		mData = newData;
		// 	}
		// }

		void insert(iterator it, T data)
		{
			int index = it.get() - mData;

			if (mSize >= mCapacity)
			{
				reserve(mCapacity * 2);
			}

			for (int i = mSize; i > index; --i)
			{
				mData[i] = mData[i - 1];
			}

			mData[index] = data;
			++mSize;
		}

		// void erase(T data)
		// {
		// 	int index = -1;
		// 	for (int i = 0; i < mSize; ++i)
		// 	{
		// 		if (mData[i] == data)
		// 		{
		// 			index = i;
		// 			break;
		// 		}
		// 	}

		// 	if (index != -1)
		// 	{
		// 		T* newData = new T[mCapacity];

		// 		for (int i = 0; i < index; ++i)
		// 		{
		// 			newData[i] = mData[i];
		// 		}

		// 		mSize--;

		// 		for (int i = index + 1; i < mSize; ++i)
		// 		{
		// 			newData[i] = mData[i+1];
		// 		}

		// 		delete[] mData;
		// 		mData = newData;
		// 	}
		// }

		void erase(iterator it)
		{
			int index = it.get() - mData;

			for (int i = index; i < mSize - 1; ++i)
			{
				mData[i] = mData[i + 1];
			}

			--mSize;
		}

		void reverse()
		{
			T* newData = new T[mCapacity];

			for (int i = 0; i < mSize; ++i)
			{
				newData[mSize - i - 1] = mData[i];
			}

			delete[] mData;
			mData = newData;
		}

		int size()
		{
			return mSize;
		}

		void clear()
		{
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
	for (int i = 1; i < container.size(); ++i) container[i] = 10 + i * 10;
	container.push_back(40);
	Vector<int>::iterator it;

	for (it = container.begin(); it != container.end(); it++)
	{
		if (*it == 40)
		{
			container.insert(it, 50);
			break;
		}
	}

	cout << "PrintPtr:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
	container.clear(); //모두삭제
	cout << "Clear:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
}

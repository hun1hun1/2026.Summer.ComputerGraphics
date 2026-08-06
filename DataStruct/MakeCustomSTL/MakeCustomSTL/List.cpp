#include <iostream>
#include <string>

using namespace std;

template<typename Iterator>
Iterator next(Iterator it, int n = 1)
{
    while (n--)
        ++it;

    return it;
}

template <typename T>
class List
{
    private:
        struct Node
        {
            T data;
            Node* prev;
            Node* next;

            Node(const T& d)
                : data(d), prev(nullptr), next(nullptr) {}
        };

        Node* mHead;
        Node* mTail;
        int mSize;

    public:
        class iterator
        {
            private:
                Node* ptr;

            public:
                iterator(Node* p = nullptr)
                    : ptr(p)
                {
                }

                T& operator*()
                {
                    return ptr->data;
                }

                iterator& operator++()
                {
                    ptr = ptr->next;
                    return *this;
                }

                iterator operator++(int)
                {
                    iterator temp = *this;
                    ptr = ptr->next;
                    return temp;
                }

                iterator& operator--()
                {
                    ptr = ptr->prev;
                    return *this;
                }

                bool operator!=(const iterator& other) const
                {
                    return ptr != other.ptr;
                }

                bool operator==(const iterator& other) const
                {
                    return ptr == other.ptr;
                }

                friend class List;
        };

        List() : mHead(nullptr), mTail(nullptr), mSize(0) {}
        List(int n) : mHead(nullptr), mTail(nullptr), mSize(0)
        {
            for (int i = 0; i < n; ++i)
            {
                push_back(T());
            }
        }
        ~List() { clear(); }

        iterator begin()
        {
            return iterator(mHead);
        }

        iterator end()
        {
            return iterator(nullptr);
        }

        void push_back(const T& data)
        {
            Node* node = new Node(data);

            if (mHead == nullptr)
            {
                mHead = mTail = node;
            }
            else
            {
                node->prev = mTail;
                mTail->next = node;
                mTail = node;
            }

            ++mSize;
        }

        void push_front(const T& data)
        {
            Node* node = new Node(data);

            if (mHead == nullptr)
            {
                mHead = mTail = node;
            }
            else
            {
                node->next = mHead;
                mHead->prev = node;
                mHead = node;
            }

            ++mSize;
        }

        iterator insert(iterator pos, const T& value)
        {
            if (pos.ptr == nullptr)
            {
                push_back(value);
                return iterator(mTail);
            }

            Node* cur = pos.ptr;
            Node* node = new Node(value);

            node->next = cur;
            node->prev = cur->prev;

            if (cur->prev)
                cur->prev->next = node;
            else
                mHead = node;

            cur->prev = node;

            ++mSize;

            return iterator(node);
        }

        iterator erase(iterator pos)
        {
            if (pos == end())
                return end();

            Node* cur = pos.ptr;
            Node* next = cur->next;

            if (cur->prev)
                cur->prev->next = cur->next;
            else
                mHead = cur->next;

            if (cur->next)
                cur->next->prev = cur->prev;
            else
                mTail = cur->prev;

            delete cur;
            --mSize;

            return iterator(next);
        }

        iterator find(const T& value)
        {
            for (Node* p = mHead; p != nullptr; p = p->next)
            {
                if (p->data == value)
                    return iterator(p);
            }

            return end();
        }

        void clear()
        {
            Node* p = mHead;

            while (p)
            {
                Node* next = p->next;
                delete p;
                p = next;
            }

            mHead = nullptr;
            mTail = nullptr;
            mSize = 0;
        }

        void resize(int newSize)
        {
            while (mSize < newSize)
            {
                push_back(T());
            }

            while (mSize > newSize)
            {
                Node* temp = mTail;

                mTail = mTail->prev;

                if (mTail)
                    mTail->next = nullptr;
                else
                    mHead = nullptr;

                delete temp;
                --mSize;
            }
        }
};

int main()
{
    List<int> container(1);//컨테이너생성시 크기를 지정가능하다.
	List<int>::iterator it = container.begin();
	*it = 10;
	cout << "Print:";
	int i = 0;
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" <<  i++ << "]" << *it << ",";
	cout << endl; //배열의 크기를 지정한다.
	i = 0;
	container.resize(3);
	cout << "Print:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << i++ << "]" << *it << ",";
	cout << endl;
	//1.추가 2.삽입 3.삭제 4.모두삭제
	i = 1;
	for (it = next(container.begin()); it != container.end(); it++)
	{
		*it = i * 10 + 10;
		i++;
	}

	container.push_back(40);
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

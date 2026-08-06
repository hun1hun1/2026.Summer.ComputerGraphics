#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T, typename Compare = std::less<T>>
class PriorityQueue
{
    private:
        std::vector<T> mData;
        Compare comp;

    public:
        PriorityQueue() = default;

        bool empty() const
        {
            return mData.empty();
        }

        int size() const
        {
            return static_cast<int>(mData.size());
        }

        const T& top() const
        {
            return mData.front();
        }

        void push(const T& value)
        {
            mData.push_back(value);
            heapifyUp(mData.size() - 1);
        }

        void pop()
        {
            if (empty())
                return;

            std::swap(mData.front(), mData.back());
            mData.pop_back();

            if (!empty())
                heapifyDown(0);
        }

    private:
        void heapifyUp(int index)
        {
            while (index > 0)
            {
                int parent = (index - 1) / 2;

                if (!comp(mData[parent], mData[index]))
                    break;

                std::swap(mData[parent], mData[index]);
                index = parent;
            }
        }

        void heapifyDown(int index)
        {
            int n = static_cast<int>(mData.size());

            while (true)
            {
                int left = index * 2 + 1;
                int right = index * 2 + 2;
                int largest = index;

                if (left < n && comp(mData[largest], mData[left]))
                    largest = left;

                if (right < n && comp(mData[largest], mData[right]))
                    largest = right;

                if (largest == index)
                    break;

                std::swap(mData[index], mData[largest]);
                index = largest;
            }
        }
};

int main()
{
    PriorityQueue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    while (!pq.empty())
    {
        std::cout << pq.top() << ' ';
        pq.pop();
    }
}

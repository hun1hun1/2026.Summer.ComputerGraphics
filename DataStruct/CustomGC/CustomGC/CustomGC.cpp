#include <iostream>
#include <vector>
#include <crtdbg.h>
#include <memory>
#include <algorithm>

using namespace std;

class Object
{
public:
	virtual ~Object() = default;
};

class Player : public Object
{
public:
	~Player()
	{
		cout << this << " Player °´Ã¼ ¼Ò¸ê" << endl;
	}
};

class Enemy : public Object
{
public:
	~Enemy()
	{
		cout << this << " Enemy °´Ã¼ ¼Ò¸ê" << endl;
	}
};

class ObjectManager
{
private:
	vector<weak_ptr<Object>> objects;

public:
	template<typename T, typename... Args>
	shared_ptr<T> Create(Args&&... args)
	{
		auto ptr = make_shared<T>(forward<Args>(args)...);

		objects.push_back(ptr);
		cout << ptr << " << °´Ã¼ »ý¼º ¿Ï·á" << endl;

		return ptr;
	}

	void Collect()
	{
		objects.erase(remove_if(objects.begin(), objects.end(), [](const weak_ptr<Object>& ptr) { return ptr.expired(); }), objects.end());
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ObjectManager manager;

	auto player = manager.Create<Player>();
	auto enemy = manager.Create<Enemy>();

	player.reset();

	cout << "Collect ÀÌÀü" << endl;

	manager.Collect();

	cout << "Collect ÀÌÈÄ" << endl;

	return 0;
}

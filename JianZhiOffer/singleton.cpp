#include "pch.h"
#if 0
#include <mutex>
class Singleton
{
public:
	static Singleton * get_instance()
	{
		m.lock();
		if (!instance)
			return instance = new Singleton();
		return instance;
		m.unlock();
	}
private:
	static Singleton* instance;
	static std::mutex m;
	Singleton(){}
	~Singleton() {}
	Singleton(const Singleton&){}
	Singleton& operator=(const Singleton&){}
};
Singleton* Singleton::instance = nullptr;

#endif
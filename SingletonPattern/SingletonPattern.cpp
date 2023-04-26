#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

/**
* Definition:
* Singleton is a creational design pattern,
* which ensures that only one object of its kind exists and provides
* a single point of access to it for any other code.
* This is useful when exactly one object is needed to coordinate actions across the system.
*/
class Singleton {
protected:
	Singleton(std::string const& value) {
		_value = value;
	}
	std::string _value;
	static Singleton* _singleton;

public:
	/* Delete copy constructor and assignment operator */
	Singleton(Singleton&) = delete;
	void operator=(const Singleton&) = delete;

	/* Function to access the unique Singleton instance */
	static Singleton* getInstance(std::string const& value){
		if (_singleton == nullptr) {
			_singleton = new Singleton(value);
		}
		return _singleton;
	}

	auto someOtherBusinessLogics() -> void{

	}

	auto value()->std::string const& {
		return _value;
	}

};

Singleton* Singleton::_singleton = nullptr;
auto ThreadFoo() {
	// Following code emulates slow initialization.
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	auto singleton = Singleton::getInstance("FOO");
	std::cout << singleton->value() << "\n";
}

auto ThreadBar() {
	// Following code emulates slow initialization.
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	auto singleton = Singleton::getInstance("BAR");
	std::cout << singleton->value() << "\n";
}

int main()
{
	std::thread t1(ThreadFoo);
	std::thread t2(ThreadBar);
	t1.join();
	t2.join();
}

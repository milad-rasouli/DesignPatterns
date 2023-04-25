#include <iostream>

/* main objects */
class Developer {
public:
	std::string name;
	std::string type;
	Developer(std::string const& name, std::string const& type) {
		this->name = name;
		this->type = type;
	}

};

class Tester {
public:
	std::string name;
	std::string type;
	Tester(std::string const& name, std::string const& type) {
		this->name = name;
		this->type = type;
	}

};

/* factory method */
class EmployeeFactory {
public:
	static auto create(std::string const& name,std::string const& type) {
		if(type=="developer")
			return std::make_unique<Tester>(name, type);
		if(type =="tester")
			return std::make_unique<Tester>(name, type);
	}
};

int main()
{

	
	auto dev1 = EmployeeFactory::create("Sara", "developer");
	auto dev2 = EmployeeFactory::create("Milad", "developer");
	auto devs = { std::move(dev1),std::move(dev2) };

	auto test1 = EmployeeFactory::create("Jean", "tester");
	auto test2 = EmployeeFactory::create("Alex", "tester");
	auto testers= { std::move(test1),std::move(test2) };

	auto show = [](auto items) {
		// if it was shared_ptr we dont need to use &
		for (auto& item : items) {
			std::clog << "Name: " << item->name << "\tType: " << item->type << "\n";
		}
	};
	show(devs);
	show(testers);
}


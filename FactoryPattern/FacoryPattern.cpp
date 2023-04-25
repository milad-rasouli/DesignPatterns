#include <iostream>

/* main objects */
class Developer {
	std::string name;
	std::string type;
public:
	Developer(std::string const& name, std::string const& type) {
		this->name = name;
		this->type = type;
	}

	auto say()->void const {
		std::clog << "Name:" << name << " Type:" << type << "\n";
	}
};

class Tester {
	std::string name;
	std::string type;
public:
	Tester(std::string const& name, std::string const& type) {
		this->name = name;
		this->type = type;
	}

	auto say()->void const{
		std::clog << "Name:" << name << " Type:" << type << "\n";
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
	
	auto test1 = EmployeeFactory::create("Jean", "tester");
	auto test2 = EmployeeFactory::create("Alex", "tester");

	dev1->say();
	dev2->say();
	test1->say();
	test2->say();
}


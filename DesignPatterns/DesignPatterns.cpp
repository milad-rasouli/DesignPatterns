#include <iostream>
#include <vector>

class Developer {
    std::string name, type;
public:
    Developer() {

    }
};

int main()
{
    int* number = new int(53);
    auto ptr = &number;
    auto item = ***&ptr;
    std::cout << item << std::endl;
    delete number;
    return 0;
}


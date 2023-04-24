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
    int* number = new int[2]{53, 71};
    auto ptr = &number;
    auto item = &**ptr;
    std::cout << item[1] << std::endl;
    delete[] number;
    return 0;
}


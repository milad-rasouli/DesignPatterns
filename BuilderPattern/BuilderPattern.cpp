#include <iostream>
#include <memory>

/* Factory class */
template<typename T>
class Shop {
public:
    auto builder(T builder){
        builder.step1();
        builder.step2();
        return builder.get();
    }
};

/* main class */
class Car {
    uint32_t _parts;
public:

    auto setParts(uint32_t parts)->void {
        _parts = parts;
    }

    auto sayParts()->void {
        std::clog << "The car parts are " << _parts << "\n";
    }
};

/* builder class */
class CarBuilder {
    std::shared_ptr<Car> _car;
public:
    auto step1() {
        _car.reset(new Car);
        return this;
    }
    auto step2(uint32_t parts=5) {
        _car->setParts(parts);
        return this;
    }
    auto get() {
        return _car;
    }
};

int main()
{
    Shop<CarBuilder> shop;
    CarBuilder carBuilder;

    /* all ways to build an object */
    auto car1 = shop.builder(carBuilder);
    
    carBuilder.step1();
    carBuilder.step2(77);
    auto car2 = carBuilder.get();
    
    auto car3 = carBuilder.step1()->step2(2)->get();

    car1->sayParts();
    car2->sayParts();
    car3->sayParts();
}

